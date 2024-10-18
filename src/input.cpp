#include "input.h"
#include <iostream>
#include <regex>

auto get_command() -> std::optional<command>
{
    std::string input;

    std::cout << "What would you like to do?" << std::endl
              << "1) Ask question" << std::endl
              << "2) Add question" << std::endl
              << "3) Quit" << std::endl;

    std::getline(std::cin, input);
    return parse_command_input(input);
}

auto parse_command_input(const std::string &input) -> std::optional<command>
{
    if (input.length() != 1)
    {
        return {};
    }
    switch (input[0])
    {
    case '1':
        return command::ask;
    case '2':
        return command::add;
    case '3':
        return command::quit;
    default:
        return {};
    }
}

auto get_new_question() -> std::optional<question>
{
    std::cout << "State the question you want to add" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    return parse_new_question(input);
}

auto parse_new_question(const std::string &input) -> std::optional<question>
{
    std::regex split_question_pattern("(.+?)\\?(.*)");
    std::regex split_answers_pattern("\"(.*?)\"");

    // parse question
    std::smatch input_match;
    if (!std::regex_match(input, input_match, split_question_pattern) || input_match.size() != 3 || input_match[0].length() > 255)
    {
        return {};
    }

    question new_question;
    new_question.question_text = input_match[1];

    std::string answers(input_match[2]);

    //parse answers
    for (std::smatch answer_match;
         std::regex_search(answers, answer_match, split_answers_pattern);)
    {
        new_question.answers.emplace_back(
            answer_match.str().substr(1, answer_match.str().size() - 2));
        if (new_question.answers.back().length() > 255)
        {
            return {};
        }
        answers = answer_match.suffix();
    }
    if (new_question.answers.empty())
    {
        return {};
    }
    return new_question;
}

auto ask_for_question_to_answer() -> std::string
{
    std::string input;

    std::cout << "Ask the question!" << std::endl;
    std::getline(std::cin, input);
    // removing the '?' at the end
    input = input.substr(0, input.size() - 1);
    std::cout << input << std::endl;
    return input;
}
