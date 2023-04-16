#ifndef __PROJECT_HPP
#define __PROJECT_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "LineString.hpp"
#include "LineStringFactory.hpp"

#include "Branch.hpp"

class Project {
   private:
   LineStringFactory * factory;
   std::vector<Branch*> branches;
   int current; //index of current branch in branches
   Commit * stage;

   public:
   Project() : factory(new LineStringFactory) { }

   ~Project(){
	/*delete factory, branches, stage*/
	delete factory;
	
	for(auto i : branches){
	delete i;
	}

	delete stage;
	}

   void addBranch(Branch * branch) {
      branches.push_back(branch);
      if (branches.size() == 1) current = 0;
   }

   void setStage(Commit * commit) {
      stage = commit;
   }

   Commit * getStage() const {
      return stage;
   }

   LineStringFactory * getFactory() {
      return factory;
   }

   void loadFactory(const char * filename) const {
      factory->readFromFile(filename);
   }

   void saveFactory(const char * filename) const {
      factory->writeToFile(filename);
   }

   const std::vector<Branch *> * getBranches() const {
      return &branches;
   }

   Branch* getCurrentBranch() const{
	   return branches.at(current);
   }

   void setCurrentBranch(Branch * branch) {
      for (int i = 0; i < branches.size(); i++) {
         if (branches.at(i) == branch) current = i;
      }
   }

   void writeToFile(const char * filename) {
      std::ofstream ofs(filename);
      ofs << "Project {\n";
      ofs << "current: " << current << '\n';

      // if (branches.empty()) { ofs << "none\n"; }
      for (Branch * branch : branches) {
         branch->printFormatted(ofs);
      }
      if (stage != nullptr)
         stage->printFormatted(ofs);
      ofs << "}\n";
   }

   #define NEXT_fs getline(ifs, recieved)

   void readFromFile(const char * filename) {
      std::ifstream ifs(filename);
      if (!ifs.is_open()) {
         std::cerr << "Error: " << filename << "could not be opened" << std::endl;
         return;
      }
      std::string recieved;
      NEXT_fs;
      if (recieved != "Project {") {
         std::cout << "Expected: " << "Project {" << ", got: " << recieved << std::endl;
         exit(1);
      }
      NEXT_fs;
      current = stoi(recieved.substr(9, std::string::npos));
      bool stage = false;
      while (true) {
         NEXT_fs;
         if (recieved == "Branch {") {
            NEXT_fs;
            branches.push_back(new Branch(recieved.substr(6, std::string::npos)));
            branches.back()->readFormatted(ifs, factory);
            continue;
         }
         else if (recieved == "Commit {") {
            if (stage == true) {
               std::cout << "Error: Multiple Commits loading into Project" << std::endl;
               exit(1);
            }
            NEXT_fs;
            this->stage = new Commit(recieved.substr(9, std::string::npos));
            this->stage->readFormatted(ifs, factory);
            stage = true;
            continue;
         }
         else if (recieved == "}") {
            if (stage == false) this->stage = nullptr;
            break;
         }
      }
   }
};

#endif
