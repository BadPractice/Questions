#include "question_catalog.h"
#include "question.h"
#include <gtest/gtest.h>
#include <sstream>

auto create_example_quetion_1() -> question
{
    question q;
    q.question_text = {"What is Peters favorite food"};
    q.answers.emplace_back("Pizza");
    q.answers.emplace_back("Spaghetti");
    q.answers.emplace_back("Ice cream");
    return q;
}

auto create_example_quetion_2() -> question
{
    question q;
    q.question_text = {"What is Freds favorite food"};
    q.answers.emplace_back("Humans");
    return q;
}

TEST(QuestionCatalog, AddAndFindCorrrect)
{
    question_catalog cat;
    auto q = create_example_quetion_1();
    cat.add_question(q);

    q = create_example_quetion_2();
    cat.add_question(q);

    auto res = cat.find_question("What is Peters favorite food");

    ASSERT_TRUE(res.has_value());
    ASSERT_EQ(res.value()[0], "Pizza");
    ASSERT_EQ(res.value()[1], "Spaghetti");
    ASSERT_EQ(res.value()[2], "Ice cream");
}

TEST(QuestionCatalog, OnlyWrongQuestionsIncluded)
{
    question_catalog cat;
    auto q = create_example_quetion_2();
    cat.add_question(q);

    auto res = cat.find_question("What is Peters favorite food");

    ASSERT_FALSE(res.has_value());
}

TEST(QuestionCatalog, AddAndLookForWrong)
{
    question_catalog cat;
    auto q = create_example_quetion_1();
    cat.add_question(q);

    q = create_example_quetion_2();
    cat.add_question(q);

    auto res = cat.find_question("What is Max favorite food");

    ASSERT_FALSE(res.has_value());
}

TEST(QuestionCatalog, UseWithNoQuestion)
{
    question_catalog cat;

    auto res = cat.find_question("What is Peters favorite food");

    ASSERT_FALSE(res.has_value());
}