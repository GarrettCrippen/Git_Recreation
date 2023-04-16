#pragma once

#include "commands/command.hpp"

#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>
#include "Project.hpp"
#include "Branch.hpp"
#include "File.hpp"

std::vector<std::string> ban_list = {
   ".gitignore", "a.exe", "git.jpg", "a.out", "Main"
};
std::string DIRECTORY = "./";

bool banned(const char * filename) {
   for (auto str : ban_list) {
      if (str == filename) return true;
   }
   return false;
}

class TestCommand : public Command {
   public:
   TestCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project * project) {
      #if defined(_WIN32)
      mkdir("testfolder");
      #elif defined(__unix__)
      mkdir("testfolder", 0755);
      #endif
      project->addBranch(new Branch("testbranch"));
      project->setStage(new Commit("stagecommit"));
      DIR * dir_ptr = opendir(DIRECTORY.c_str());
      dirent * current_dirent;
      File * current_file;
      std::ifstream ifs;
      std::string line;
      while ((current_dirent = readdir(dir_ptr)) != nullptr) {
         if (current_dirent->d_type != DT_DIR && !banned(current_dirent->d_name)) {
            printf("%s\n", current_dirent->d_name);
            current_file = new File(current_dirent->d_name);
            project->getStage()->addItem(current_file);
            ifs.open(DIRECTORY + current_file->getName());
            if (!ifs.is_open()) {
               std::cerr << current_file->getName() << " cannot be opened" << std::endl;
               exit(1);
            }
            while (!ifs.eof()) {
               getline(ifs, line);
               current_file->addLine(project->getFactory(), line);
            }
            ifs.close();
         }
      }
      return nullptr;
   }
};