#ifndef __CHECKOUT_COMMAND_HPP
#define __CHECKOUT_COMMAND_HPP

#include "command.hpp"
#include <string.h>

class checkoutCommand : public Command{
    private:
    
    public:
    checkoutCommand(int argc, char**argv) : Command(argc, argv) { }

    void * executeCommand(Project * currentProject){
        for(int i = 0 ; i < currentProject->getBranches()->size() ; i++){
	   if(!currentProject->getStage()->getItems()->empty()) {
            std::cout<<"Items are still staged in this branch"<<std::endl;
           }
	  else{
            std::string branchName = currentProject->getBranches()->at(i)->getName();
            const char * charBranchName = branchName.c_str();

            if(strcmp(argv[1], charBranchName ) == 0 ){
                currentProject->setCurrentBranch(currentProject->getBranches()->at(i));
                std::cout<<"success"<<std::endl;
            }
	  }

        }

        return nullptr;

    }

};

#endif
