#ifndef _INIT_
#define _INIT_

#include "../Project.hpp"
#include "command.hpp"
#include <fstream>
#include <string>



class initCommand : public Command{
   public:
   initCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project * p) {
   
   /*IN PROGRESS*/
	p->addBranch(new Branch("testbranch"));
	p->setStage(new Commit("stagecommit"));
   return nullptr;
}

};

#endif
