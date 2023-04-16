#ifndef _STATUS_
#define _STATUS_

#include "dirent.h"
#include "command.hpp"
#include "../Item.hpp"
#include "../Project.hpp"
#include <string>
#include <vector>
#include <cstring>

/*helper function to see if a file is staged or not*/
bool exists(const std::vector<Item*>& stage, std::string fileName){
        for(Item* s : stage){
                if(s->getName() == fileName)
                        return true;
        }
        return false;
}
/*helper to see if file is on ignore list*/
bool ignore(std::string name){
std::string key;
std::ifstream fin("ignore.txt");
bool found = false;

        if(!fin.is_open())
                return false;

        while( std::getline(fin,key)){
                if ( key == name )
                found = true;
 }
fin.close();
return found;
}

class statusCommand : public Command{
   public:
   statusCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project* p) {
                std::cout<<std::endl<<"--On Branch: "<<p->getCurrentBranch()->getName()<<"--"<<std::endl;
                std::cout<<"# Changes to be committed.."<<std::endl;
                std::cout<<"#   Use unstage <file> to unstage"<<std::endl<<"#"<<std::endl;
			/*print all files that are ready to be committed*/
			Commit* stage = p->getStage();
                        std::vector<Item*> stageItems = (stage == nullptr) ? std::vector<Item*>() : *(stage->getItems());

			for(Item* s : stageItems){
                        std::cout<<"#           "<<s->getName()<<std::endl;
                        }
                std::cout<<"#"<<std::endl<<"#Untracked Files.."<<std::endl;
                std::cout<<"#   Use stage <file> to stage"<<std::endl<<"#"<<std::endl;

                DIR* d;
                struct dirent* ptr;
                d = opendir(".");

                if(d)
                while( ( ptr = readdir(d) ) != NULL){
			/*do not print . or .. directories*/
                        if(!strcmp( ptr->d_name,"." )== 0 && !strcmp( ptr->d_name,"..")== 0 ){

                                /*check if file is not yet staged or on ignore.txt*/
                                if(!exists(stageItems,ptr->d_name) && !ignore(ptr->d_name) )
                                        std::cout<<"#           "<<ptr->d_name<<std::endl;
                        }
                }
                std::cout<<std::endl;

                closedir(d);
                return nullptr;
}
};
#endif
