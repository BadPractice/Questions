#include <gtest/gtest.h>
#include "test_question_catalog.cpp"
#include "test_input.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
