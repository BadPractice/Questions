
#pragma once

#include <string>
#include <vector>

/**
 * @brief a simple struct holding a question
 */
struct question
{
  std::string question_text;
  std::vector<std::string> answers;
};
