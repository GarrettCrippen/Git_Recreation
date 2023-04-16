#ifndef _STAGE_
#define _STAGE_

#include "../File.hpp"
#include "../Item.hpp"
#include <vector>
#include <cstring>
#include "command.hpp"
#include "../Project.hpp"
#include "dirent.h"
#include "fstream"

class stageCommand : public Command{
   public:
   stageCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project* p) {

      if (argc < 2) {
         std::cout << "Insufficient arguments for stage command" << std::endl;
         return nullptr;
      }

      File* temp = nullptr;

      DIR* d;
      struct dirent* ptr;
      d = opendir(".");

      if(d)
      while( ( ptr = readdir(d) ) != NULL){
         /*check if file exists*/
         if(strcmp( ptr->d_name,argv[1] )== 0){
            temp = new File(ptr->d_name);
            
            /*push back lines to file's vector*/	
            std::string line;
            std::ifstream fin(argv[1]);

            if(!fin.is_open())return nullptr;

            while (getline(fin,line)) {
               temp->addLine(p->getFactory(), line);
            }
            fin.close();
            closedir(d);

            goto found;
         }
      }
      closedir(d);

      /*if not found return*/
      return nullptr;
      found:

      if (p->getStage() == nullptr) p->setStage(new Commit("stagecommit"));
      Commit* s = p->getStage();
      std::vector<Item*> stage = *(s->getItems());
      Item* t;
      for(Item* element : stage){
         /*if already staged point to new File and then return*/
         if(element->getName() == argv[1] ){
            t=element;
            element = temp;
            delete t;
            return nullptr;
         }
      }

      /*stage if not already staged*/
      s->addItem(temp);
      return nullptr;
   }
};

#endif
