#include "gtest/gtest.h"

#include "branchCommand_test.hpp"
#include "checkoutCommand_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
