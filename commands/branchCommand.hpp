#ifndef __BRANCH_COMMAND_HPP
#define __BRANCH_COMMAND_HPP

#include "command.hpp"

class branchCommand : public Command{
    private:


    public:
    branchCommand(int argc, char**argv): Command(argc,argv) { }

    void * executeCommand(Project * currentProject){

        if(argc < 2){ //if the only argument is "branch" with nothing after
            for(int i = 0 ; i < currentProject->getBranches()->size() ; i++){

                if(currentProject->getCurrentBranch() == currentProject->getBranches()->at(i)){
                    std::cout<<"*"<<currentProject->getBranches()->at(i)->getName()<<std::endl;
                }
                else{
                    std::cout<<currentProject->getBranches()->at(i)->getName()<<std::endl;
                }
            }
        }

        else if(argc >= 2){
            currentProject->addBranch(new Branch(argv[1]));

            for(int i = 0 ; i < currentProject->getBranches()->size() ; i++){

                if(currentProject->getCurrentBranch() == currentProject->getBranches()->at(i)){
                    std::cout<<"*"<<currentProject->getBranches()->at(i)->getName()<<std::endl;
                }
                else{
                    std::cout<<currentProject->getBranches()->at(i)->getName()<<std::endl;
                }
            }
        }
        
        return nullptr;
    }
};

#endif
