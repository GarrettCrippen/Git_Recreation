#ifndef __COMMAND_HPP
#define __COMMAND_HPP

#include "../Project.hpp"

class Command {
   protected:
   int argc;
   char ** argv;

   public:
   Command(int argc, char ** argv) : argc(argc), argv(argv) { }
   virtual void * executeCommand(Project * project) = 0;
};

#endif
