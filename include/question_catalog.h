#pragma once

#include <optional>
#include <string>
#include <vector>

#include "question.h"

/**
 * @brief The catalog of possible questions
 *
 * This class represents the catalog of possible questions it can be used to add
 * new questions or look for an question already in the catalog
 *
 * Newly added question will be checked for correct lenght and redundancy
 */
class question_catalog
{

private:
  std::vector<question> m_questions;

public:
  /**
   * @brief Attempts to find the question in the question catalog
   * @param search_question the the question that should be looked up
   * @return the answers to the question, or std::nullopt if not found
   */
  auto find_question(const std::string &new_question) const
      -> std::optional<std::vector<std::string>>;

  /**
   * @brief Adds new question to the question catalog. Newly added question will
   * be checked for correct lenght and redundancy. In any violation an error is
   * returned. and the question will not be added.
   * @param new_question the the question that should be added
   * @return std::nullopt no error occured, otherwise the error message
   */
  auto add_question(question &new_question) -> std::optional<std::string>;
};