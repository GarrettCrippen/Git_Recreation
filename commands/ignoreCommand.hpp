#ifndef _IGNORE_
#define _IGNORE_  

#include "../Project.hpp"
#include "command.hpp"
#include <fstream>
#include <string>

bool findName(std::string name){
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

class ignoreCommand : public Command{
   public:
   ignoreCommand(int argc, char ** argv) : Command(argc, argv) { }
   void * executeCommand(Project * p) { 
   
	/*append to file ignore.txt*/
	std::ofstream fout("ignore.txt",std::ios_base::app);

	//if already on ignore.txt do not add again
	if(!fout.is_open()|| findName(argv[1]))
		return nullptr;
	
	fout<<argv[1]<<std::endl;
	
	fout.close();
	
	return nullptr;	
} 

};

#endif
