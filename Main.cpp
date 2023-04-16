#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include "LineString.hpp"
#include "LineStringFactory.hpp"
#include "Project.hpp"
#include "Item.hpp"
#include "File.hpp"
#include "Folder.hpp"
#include "Commit.hpp"
#include "commands/command.hpp"
#include "commands/commitCommand.hpp"
#include "commands/stageCommand.hpp"
#include "commands/statusCommand.hpp"
#include "commands/unstageCommand.hpp"
#include "commands/branchCommand.hpp"
#include "commands/checkoutCommand.hpp"
#include "commands/helpCommand.hpp"
#include "commands/ignoreCommand.hpp"
#include "commands/initCommand.hpp"
#include "TestCommand.hpp"

const char * _FACTORY_FILE_ = "data/lines.txt"; //file to store lines
const char * _PROJECT_FILE_ = "data/project.txt"; //file to store branches and commits

int main(int argc, char ** argv) {
   if (argc < 2) {
      std::cout << "Insufficient arguments\n";
      return 1;
   }

   //create project
   Project* project = new Project();

   Command * command = nullptr;
   void * output;
   if (strcmp(argv[1], "init") == 0) command = new initCommand(argc - 1, argv + 1);
   else {
   //load project files
   project->loadFactory(_FACTORY_FILE_);
   project->readFromFile(_PROJECT_FILE_);
   }

   //read command line arguments
   if (strcmp(argv[1], "stage") == 0) command = new stageCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "unstage") == 0) command = new unstageCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "branch") == 0) command = new branchCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "status") == 0) command = new statusCommand(argc - 1, argv + 1);
   
   if (strcmp(argv[1], "commit") == 0) command = new commitCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "ignore") == 0) command = new ignoreCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "help") == 0) command = new helpCommand(argc - 1, argv + 1);
   if (strcmp(argv[1], "checkout") == 0) command = new checkoutCommand(argc - 1, argv + 1);

   if (strcmp(argv[1], "test") == 0) command = new TestCommand(argc - 1, argv + 1);
   if (command == nullptr) {
      std::cout << "Invalid command" << std::endl;
      // return 1;
      goto end;
   }
   
   //execute command
   output = command->executeCommand(project);

   //save project
   end:

   project->saveFactory(_FACTORY_FILE_);
   project->writeToFile(_PROJECT_FILE_);
	
   delete command;
   delete project;
   return 0;
}
