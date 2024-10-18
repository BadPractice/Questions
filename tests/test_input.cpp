
#include <gtest/gtest.h>
#include "input.h"

TEST(InputTest, ParseCorrectQuestion)
{
    std::string new_question("What is Peters favorite food? \"Pizza\" \"Spaghetti\" \"Ice cream\"");
    auto maybe_parsed_question = parse_new_question(new_question);
    ASSERT_TRUE(maybe_parsed_question.has_value());
    ASSERT_EQ(maybe_parsed_question.value().question_text, "What is Peters favorite food");
    ASSERT_EQ(maybe_parsed_question.value().answers[0], "Pizza");
    ASSERT_EQ(maybe_parsed_question.value().answers[1], "Spaghetti");
    ASSERT_EQ(maybe_parsed_question.value().answers[2], "Ice cream");
}

TEST(InputTest, QuestionParseFormError)
{
    std::string new_question("What is Peters favorite food \"Pizza\" \"Spaghetti\" \"Ice cream\"");
    auto maybe_parsed_question = parse_new_question(new_question);
    ASSERT_FALSE(maybe_parsed_question.has_value());
}

TEST(InputTest, QuestionTooLong)
{
    std::string new_question("What is Peters favorite food 12345678901234567890123456789012345678901234567890123456"
    "78901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"
    "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234"
    "5678901234567890? \"Pizza\" \"Spaghetti\" \"Ice cream\"");
    auto maybe_parsed_question = parse_new_question(new_question);
    ASSERT_FALSE(maybe_parsed_question.has_value());
}
TEST(InputTest, AnswerTooLong)
{
    std::string new_question("What is Peters favorite food \"Pizza1234567890123456789012"
    "345678901234567890123456789012345678901234567890123456789012345678901234567890123456"
    "7890123456789012345678901234567890123456789012345678901234567890123456789012345678901"
    "23456789012345678901234567890123456789012345678901234567890123456789012345678901234567"
    "89012345678901234567890\" \"Spaghetti\" \"Ice cream\"");
    auto maybe_parsed_question = parse_new_question(new_question);
    ASSERT_FALSE(maybe_parsed_question.has_value());
}

TEST(InputTest, ParseAskCommand)
{
    std::string new_command("1");
    auto maybe_parsed_command = parse_command_input(new_command);
    ASSERT_TRUE(maybe_parsed_command.has_value());
    ASSERT_EQ(maybe_parsed_command.value(), command::ask);
}

TEST(InputTest, ParseAddCommand)
{
    std::string new_command("2");
    auto maybe_parsed_command = parse_command_input(new_command);
    ASSERT_TRUE(maybe_parsed_command.has_value());
    ASSERT_EQ(maybe_parsed_command.value(), command::add);
}

TEST(InputTest, ParseQuitCommand)
{
    std::string new_command("3");
    auto maybe_parsed_command = parse_command_input(new_command);
    ASSERT_TRUE(maybe_parsed_command.has_value());
    ASSERT_EQ(maybe_parsed_command.value(), command::quit);
}

TEST(InputTest, ParseInvalidCommand)
{
    std::string new_command("4");
    auto maybe_parsed_command = parse_command_input(new_command);
    ASSERT_FALSE(maybe_parsed_command.has_value());
}

TEST(InputTest, ParseInvalidCommandInput)
{
    std::string new_command("Hello World");
    auto maybe_parsed_command = parse_command_input(new_command);
    ASSERT_FALSE(maybe_parsed_command.has_value());
}