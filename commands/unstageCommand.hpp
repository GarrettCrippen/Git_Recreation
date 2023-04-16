#ifndef _UNSTAGE_
#define _UNSTAGE_

#include "../Item.hpp"
#include <vector>
#include "command.hpp"
#include "../Project.hpp"
#include "../Commit.hpp"

class unstageCommand : public Command{
   public:
   unstageCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project* p) {
      Commit* s = p->getStage();
      std::vector<Item*> stage = *(s->getItems());

      /*return if nothing staged*/
      if(!stage.size())
         return nullptr;
               
      /*find element and then erase*/
      Item* t;
      for(unsigned i =0; i<stage.size(); i++){
         if(stage.at(i)->getName() == argv[1]){
            t=stage.at(i);
            s->removeItem(i);
            delete t;
            return nullptr;
         }
      }
      return nullptr;
   }
};
#endif
