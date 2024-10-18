
#pragma once

#include <optional>
#include <string>
#include "question.h"

/**
 * @brief all valid commands a user can enter. Invalid commands are handled using std::nullopt
 */
enum command
{
    ask,
    add,
    quit
};

/**
 * @brief writes the command prompt to the user and attempts to fetch a command
 * @return the command if a valid command has been entered, otherwise std::nullopt
 */
auto get_command() -> std::optional<command>;

/**
 * @brief attempts to fetch the command the user has inputted
 * @param input string containing the command that needed to be parsed
 * @return the command if a valid command has been entered, otherwise std::nullopt
 */
auto parse_command_input(const std::string &input) -> std::optional<command>;

/**
 * @brief asks the user for a question
 * @return a question if the input was valid, otherwise std::nullopt
 */
auto get_new_question() -> std::optional<question>;

/**
 * @brief attempts to parse a new question using regex. This also checks for the lenght limitation
 * @param input string containing a question that needed to be parsed
 * @return a question if the input was valid, otherwise std::nullopt
 */
auto parse_new_question(const std::string &input) -> std::optional<question>;

/**
 * @brief asks for a question to answer and then fetches it
 * @return the queistion
 */
auto ask_for_question_to_answer() -> std::string;
