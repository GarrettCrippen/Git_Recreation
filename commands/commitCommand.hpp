#ifndef _COMMITCOMMAND_
#define _COMMITCOMMAND_

#include "../Item.hpp"
#include <vector>
#include "command.hpp"
#include "../Project.hpp"

class commitCommand : public Command{
   public:
   commitCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project* p) {

      if (!p->getStage()->getItems()->empty()) {
         std::string temp;
         for (int i = 1; i < argc; i++) {
            temp.append(argv[i]);
            temp.push_back(' ');
         }
         p->getStage()->setMessage(argv[1]);
         p->getCurrentBranch()->addCommit(p->getStage());
         p->setStage(new Commit("stagecommit"));
      }

      return nullptr;
}
};
#endif
