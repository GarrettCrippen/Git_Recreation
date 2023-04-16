#ifndef __CHECKOUTCOMMAND_TEST_HPP__
#define __CHECKOUTCOMMAND_TEST_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../commands/branchCommand.hpp"
#include "../commands/checkoutCommand.hpp"
#include "../Project.hpp"
#include "../Branch.hpp"
#include "../commands/command.hpp"

TEST(CheckoutTest , CheckoutOneBranch ){
        char* test_val[3] ; test_val[0]= "./checkoutCommand.hpp"; test_val[1]= "checkout" ; test_val[2]= "newBranch";
        Project* test = new Project();
        Branch* main = new Branch("main");
        test->addBranch(main);
	Branch* newBranch = new Branch("newBranch");
	test->addBranch(newBranch);
        /*the outcome is "*main\nnewBranch" which shows up when running ./test  */

	Command* checkoutTest = new checkoutCommand(2,test_val+1);
	Command* printBranches = new branchCommand(1,test_val+1);
	void * result = checkoutTest->executeCommand(test);
	/*the outcome is "main\n*newBranch" which shows up when running ./test  */

        EXPECT_EQ(NULL, printBranches->executeCommand(test)  );
}

TEST(CheckoutTest , CheckIfItemsAreStagedForCommit ){
        char* test_val[3] ; test_val[0]= "./checkoutCommand.hpp"; test_val[1]= "checkout" ; test_val[2]= "thirdBranch";
        Project* test = new Project();

        Branch* main = new Branch("main");
        test->addBranch(main);

        Branch* newBranch = new Branch("newBranch");
        test->addBranch(newBranch);
	
	Branch* newBranch2 = new Branch("thirdBranch");
        test->addBranch(newBranch2);

	Branch* newBranch3 = new Branch("fourthBranch");
        test->addBranch(newBranch3);

	
        /*the outcome is "*main\nnewBranch" which shows up when running ./test  */

        Command* checkoutTest = new checkoutCommand(2,test_val+1);
        Command* printBranches = new branchCommand(1,test_val+1);
        void * result = checkoutTest->executeCommand(test);
        /*the outcome is "main\n*newBranch" which shows up when running ./test  */

        EXPECT_EQ(NULL, printBranches->executeCommand(test)  );
}

TEST(CheckoutTest , CheckoutThirdOfFourBranches ){
        char* test_val[3] ; test_val[0]= "./checkoutCommand.hpp"; test_val[1]= "checkout" ; test_val[2]= "thirdBranch";
        Project* test = new Project();
	Commit * emptyS = new Commit();
        Branch* main = new Branch("main");
        test->addBranch(main);
        Branch* newBranch = new Branch("newBranch");
        test->addBranch(newBranch);
        Branch* newBranch2 = new Branch("thirdBranch");
        test->addBranch(newBranch2);
        Branch* newBranch3 = new Branch("fourthBranch");
        test->addBranch(newBranch3);

	//std::cout<<"made all branches<<std:endl;
	test->setStage(emptyS);

        /*the outcome is "*main\nnewBranch" which shows up when running ./test  */

        Command* checkoutTest = new checkoutCommand(2,test_val+1);
        Command* printBranches = new branchCommand(1,test_val+1);
        void * result = checkoutTest->executeCommand(test);
        /*the outcome is "main\n*newBranch" which shows up when running ./test  */

        EXPECT_EQ(NULL, printBranches->executeCommand(test)  );
}



#endif

