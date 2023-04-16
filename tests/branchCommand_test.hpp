#ifndef __BRANCHCOMMAND_TEST_HPP__
#define __BRANCHCOMMAND_TEST_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../commands/branchCommand.hpp"
#include "../Project.hpp"
#include "../Branch.hpp"
#include "../commands/command.hpp"
TEST(BranchTest , OnlyBranch ){
	char* test_val[2] ; test_val[0]= "./branchCommand.hpp"; test_val[1]= "branch" ;
        Project* test = new Project();
	Branch* main = new Branch("main");
	test->addBranch(main);
	Command* branchTest = new branchCommand(1,test_val+1);
	
	/*the expected outcome is "*main" which shows up when running ./test  */
	EXPECT_EQ(NULL, branchTest->executeCommand(test)  );	
}

TEST(BranchTest , MakeBranch_newBranch ){
        char* test_val[3] ; test_val[0]= "./branchCommand.hpp"; test_val[1]= "branch" ; test_val[2]= "newBranch";
        Project* test = new Project();
        Branch* main = new Branch("main");
        test->addBranch(main);
        Command* branchTest = new branchCommand(2,test_val+1);

        /*the expected outcome is "*main\nnewBranch" which shows up when running ./test  */
        EXPECT_EQ(NULL, branchTest->executeCommand(test)  );
}



#endif 

