#include <iostream>
#include <optional>
#include <ranges>
#include <regex>
#include <string>

#include "input.h"
#include "question.h"
#include "question_catalog.h"

auto answer_question(const question_catalog &catalog, const std::string &question) -> void
{
  auto maybe_question = catalog.find_question(question);
  if (!maybe_question.has_value())
  {
    std::cout << "  • " << "the answer to life, universe and everything is 42" << std::endl;
    return;
  }
  for (auto answer : maybe_question.value())
  {
    std::cout << "  • " << answer << std::endl;
  }
}

auto main() -> int
{
  question_catalog catalog = question_catalog();

  while (true)
  {
    std::optional<command> command = {};

    while (!command.has_value())
    {
      command = get_command();
    }
    switch (command.value())
    {
    case command::ask:
      answer_question(catalog, ask_for_question_to_answer());
      continue;
    case command::add:
      if (auto new_question = get_new_question())
      {
        auto maybe_err = catalog.add_question(new_question.value());
        if (maybe_err.has_value())
        {
          std::cout << maybe_err.value() << std::endl;
        }
      }
      else
      {
        std::cout << "Invalid question format" << std::endl;
      }
      continue;
    case command::quit:
      std::cout << "So long and thank you for the fish!" << std::endl;
      break;
    }

    return EXIT_SUCCESS;
  }
}
