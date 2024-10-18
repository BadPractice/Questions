
#include "question_catalog.h"

auto question_catalog::find_question(const std::string &search_question) const
    -> std::optional<std::vector<std::string>>
{
  for (auto &current_question : m_questions)
  {
    if (current_question.question_text == search_question)
    {
      return current_question.answers;
    }
  }
  return {};
}

auto question_catalog::add_question(question &new_question) -> std::optional<std::string>
{
  for (auto &answer : new_question.answers)

    if (find_question(new_question.question_text).has_value())
    {
      return std::string("The question already exists :(");
    }
  m_questions.emplace_back(std::move(new_question));
  return {};
}