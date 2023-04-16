
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include "../LineString.hpp"
#include "../LineStringFactory.hpp"
#include "../Project.hpp"
#include "../Item.hpp"
#include "../File.hpp"
#include "../Folder.hpp"
#include "../Commit.hpp"
#include "../commands/command.hpp"
#include "../commands/commitCommand.hpp"
#include "../commands/stageCommand.hpp"
#include "../commands/statusCommand.hpp"
#include "../commands/unstageCommand.hpp"
#include "../commands/branchCommand.hpp"
#include "../commands/checkoutCommand.hpp"
#include "../commands/helpCommand.hpp"
#include "../commands/ignoreCommand.hpp"
#include "../commands/initCommand.hpp"
#include "../TestCommand.hpp"

const char * _FACTORY_FILE_ = "lines.txt"; //file to store lines
const char * _PROJECT_FILE_ = "project.txt"; //file to store branches and commits

int main() {
        std::cout<<std::endl<<"------ TEST COMMAND:     ./a.out init  &&  ./a.out branch big_branch  && ./a.out checkout big_branch       ------"<<std::endl;
		
		/*clear ignore.txt for testing purposes*/
		std::ofstream fout("ignore.txt",std::ofstream::trunc);
		fout.close();
		
 Project* project = new Project();
 void* output;

 char* argv1[2] = {"./a.out","init"};
 char* argv2[3] = {"./a.out","branch","big_branch"};
  char* argv4[3] = {"./a.out","checkout","big_branch"};
 
 char* argv3[2] = {"./a.out","status"};


 Command * command1 = new initCommand(1,argv1+1);
 Command * command2 = new branchCommand(2,argv2+1);
 Command * command3 = new branchCommand(1,argv3+1);
 Command * command4 = new checkoutCommand(1,argv4+1);


command1->executeCommand(project);

command2->executeCommand(project);

/*checkout*/
command4->executeCommand(project);

command3->executeCommand(project);
return 0;
}
