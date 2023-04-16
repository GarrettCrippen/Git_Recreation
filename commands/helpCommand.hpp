#ifndef _HELP_
#define _HELP_

#include "../Project.hpp"
#include "command.hpp"
#include <string>
#include <cctype>
#include <iomanip>

std::string lowerCase(char* argv){
std::string s;
        for(unsigned i =0;i<std::strlen(argv);i++){
                s += tolower(argv[i]);
        }
        return s;
}

class helpCommand : public Command{
   public:
   helpCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project * p) {
   if(argc != 2) {
                std::cout<<std::endl<<"--COMMANDS--"<<std::endl;
                std::cout<<"NAME:"<<" status - Show the working tree status"<<std::endl;
                std::cout<<"NAME:"<<" stage - Add file contents to the index"<<std::endl;
                std::cout<<"NAME:"<<" unstage - Remove file contents from the index"<<std::endl;
                std::cout<<"NAME:"<<" ignore - specifies untracked file to be ignored"<<std::endl;
                std::cout<<"NAME:"<<" commit - store changes to repository"<<std::endl;
		std::cout<<"NAME:"<<" checkout - switch to a branch"<<std::endl;
		std::cout<<"NAME:"<<" branch - creates a branch"<<std::endl;
		std::cout<<"------------"<<std::endl;
		std::cout<<"use ./a.out help <command>"<<std::endl<<std::endl;
        return nullptr;
   }
#define format  std::setfill(' ')<<std::setw(21)<<" "
#define format2 std::setfill(' ')<<std::setw(19)<<" "
#define format3 std::setfill(' ')<<std::setw(13)<<" "
#define lh std::endl
  std::string command = lowerCase(argv[1]);
  std::cout<<"*********************************************************************************************"<<std::endl;	
        if(command == "status"){
                std::cout<<"NAME:"<<format<<"status - Show the working tree status"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"status"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"Displays the files that will be committed when running commit and \n the files that you could commit after running stage before running commit. To hide files from status, see ignore."<<std::endl<<std::endl<<lh;
       }
        else if(command == "stage"){
                std::cout<<"NAME:"<<format<<"stage - Add file contents to the index"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"stage <filename/dirname>"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"This command updates to the current index of the working tree, preparing the content to be staged for the next commit. \n You must use the stage command to add any new or modified files to the index. \n Status will show which files are staged for the next commit."<<std::endl<<std::endl<<lh;
       }
        else if(command == "unstage"){
                std::cout<<"NAME:"<<format<<"unstage - Remove file contents from the index"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"unstage <filename/dirname>"<<std::endl<<lh;
                std::cout<<"Description:"<<format3<<"<This command removes the current index from the working tree, preparing the content to be staged for the next commit. \n The unstage command does the opposite of the stage command \n Status will show which files are staged for the next commit"<<std::endl<<std::endl<<lh;
       }
        else if(command == "ignore"){
                std::cout<<"NAME:"<<format<<"ignore - specifies untracked file to be ignored"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"ignore <filename/dirname>"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"This command will ignore the contents when and will not display when running the status command"<<std::endl<<std::endl<<lh;
       }
        else if(command == "commit"){
                std::cout<<"NAME:"<<format<<"commit - store changes to repository"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"commit <Message>"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"This command will store the changes of the repository. \n This can be done first by using the unstage command"<<std::endl<<std::endl<<lh;
       }
        else if(command == "branch"){
                std::cout<<"NAME:"<<format<<"branch - creates a branch on the working tree"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"branch <branch_name>"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"Use this command before running checkout to switch to a branch on the working tree "<<std::endl<<std::endl<<lh;
       }
        else if(command == "checkout"){
                std::cout<<"NAME:"<<format<<"checkout - switches to a branch"<<std::endl<<lh;
                std::cout<<"USAGE: "<<format2<<"checkout <branch_name>"<<std::endl<<lh;
                std::cout<<"Description: "<<format3<<"This command will change to the specified branch"<<std::endl<<std::endl<<lh;
       }
        else{
                std::cout<<"INVALID COMMAND NAME: use \"./a.out help\" to display all the commands"<<std::endl<<lh;
        }
  	std::cout<<"*********************************************************************************************"<<std::endl; 

        return nullptr;
}
};

#endif
