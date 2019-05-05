/*
** EPITECH PROJECT, 2019
** CPP_Plazza_2018
** File description:
** tests_Parser.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "PlazzaError.hpp"

Test(tests_Parser, setOrder_1)
{
    Parser parser;

    parser.setOrder("Margarita S x2");
    cr_assert_eq(parser.getOrder(), "Margarita S x2");
}

Test(tests_Parser, setOrder_2)
{
    Parser parser;

    parser.setOrder("");
    cr_assert_eq(parser.getOrder(), "");
}

Test(tests_Parser, setPizzaType_1)
{
    Parser parser;

    parser.setPizzaType("Regina");
    cr_assert_eq(parser.getPizzaType(), Regina);
}

Test(tests_Parser, setPizzaType_2)
{
    Parser parser;

    parser.setPizzaType("Margarita");
    cr_assert_eq(parser.getPizzaType(), Margarita);
}

Test(tests_Parser, setPizzaType_3)
{
    Parser parser;

    cr_expect_throw(parser.setPizzaType("Fantasio"), PlazzaError, "Invalid type of pizza.");
}

Test(tests_Parser, setPizzaSize_1)
{
    Parser parser;

    parser.setPizzaSize("S");
    cr_assert_eq(parser.getPizzaSize(), S);
}

Test(tests_Parser, setPizzaSize_2)
{
    Parser parser;

    parser.setPizzaSize("XXL");
    cr_assert_eq(parser.getPizzaSize(), XXL);
}

Test(tests_Parser, setPizzaSize_3)
{
    Parser parser;

    cr_expect_throw(parser.setPizzaSize("XXXL"), PlazzaError, "Invalid size of pizza.");
}

Test(tests_Parser, setPizzaNumber_1)
{
    Parser parser;

    parser.setPizzaNumber("x3");
    cr_assert_eq(parser.getPizzaNumber(), 3);
}

Test(tests_Parser, setPizzaNumber_2)
{
    Parser parser;

    cr_expect_no_throw(parser.setPizzaNumber("x10"), PlazzaError, "Invalid number of pizza.");
    cr_assert_eq(parser.getPizzaNumber(), 10);
}

Test(tests_Parser, setPizzaNumber_3)
{
    Parser parser;

    cr_assert_throw(parser.setPizzaNumber("xlol3"), PlazzaError, "Invalid number of pizza.");
}

Test(tests_Parser, iequals_1)
{
    Parser parser;

    cr_assert_eq(parser.iequals("Regina", "Regina"), true);
}

Test(tests_Parser, iequals_2)
{
    Parser parser;

    cr_assert_eq(parser.iequals("Regina", "regina"), true);
}

Test(tests_Parser, iequals_3)
{
    Parser parser;

    cr_assert_neq(parser.iequals("Regina", "Margarita"), true);
}

Test(tests_Parser, cleanOrder_1)
{
    Parser parser;
    std::unique_ptr<std::vector<std::string>> tmp = std::make_unique<std::vector<std::string>>();

    tmp->push_back("Regina");
    tmp->push_back("M");
    tmp->push_back("x3");

    parser.cleanOrder(tmp);
    cr_assert_eq(tmp->at(0), "Regina");
    cr_assert_eq(tmp->at(1), "M");
    cr_assert_eq(tmp->at(2), "x3");
}

Test(tests_Parser, cleanOrder_2)
{
    Parser parser;
    std::unique_ptr<std::vector<std::string>> tmp = std::make_unique<std::vector<std::string>>();

    tmp->push_back("Regina");
    tmp->push_back("");
    tmp->push_back("M");
    tmp->push_back("x3");
    tmp->push_back("");

    parser.cleanOrder(tmp);
    cr_assert_eq(tmp->at(0), "Regina");
    cr_assert_eq(tmp->at(1), "M");
    cr_assert_eq(tmp->at(2), "x3");
    cr_assert_eq(tmp->size(), 3);
}

Test(tests_Parser, fillArray_1)
{
    Parser parser;
    std::vector<std::string> order;
    std::array<std::string, 3> arr;

    order.push_back("Regina");
    order.push_back("M");
    order.push_back("x3");

    arr[0] = "Regina";
    arr[1] = "M";
    arr[2] = "x3";

    cr_assert_eq(parser.fillArray(order), arr);
}

Test(tests_Parser, fillArray_2)
{
    Parser parser;
    std::vector<std::string> order;
    std::array<std::string, 3> arr;

    order.push_back("Margarita");
    order.push_back("XL");
    order.push_back("x2");

    arr[0] = "Margarita";
    arr[1] = "XL";
    arr[2] = "x2";

    cr_assert_eq(parser.fillArray(order), arr);
}

Test(tests_Parser, carveOrder_1)
{
    Parser parser;
    std::vector<std::string> tmp;

    tmp.push_back("regina XXL x2");
    tmp.push_back(" fantasia M x3");
    tmp.push_back(" margarita S x1");
    cr_assert_eq(parser.carveOrder("regina XXL x2; fantasia M x3; margarita S x1", ';'), tmp);
}

Test(tests_Parser, carveOrder_2)
{
    Parser parser;
    std::vector<std::string> tmp;

    tmp.push_back("regina");
    tmp.push_back("M");
    tmp.push_back("x1");
    cr_assert_eq(parser.carveOrder("regina M x1", ' '), tmp);
}

Test(tests_Parser, resetParser_1)
{
    Parser parser;

    parser.resetParser();
    cr_assert_eq(parser.getFirstOrder(), false);
    cr_assert_eq(parser.getOrder(), "");
    cr_assert_eq(parser.getLaunch(), true);
}

Test(tests_Parser, resetParser_2)
{
    Parser parser;

    parser.setFirstOrder(false);
    parser.resetParser();
    cr_assert_eq(parser.getIsNewMenu(), false);
    cr_assert_eq(parser.getOrder(), "");
    cr_assert_eq(parser.getLaunch(), true);
}

Test(tests_Parser, isNewMenu_1)
{
    Parser parser;

    cr_assert_eq(parser.getIsNewMenu(), true);
}

Test(tests_Parser, isNewMenu_2)
{
    Parser parser;

    parser.setIsNewMenu(false);
    cr_assert_eq(parser.getIsNewMenu(), false);
}

Test(tests_Parser, launch_1)
{
    Parser parser;

    cr_assert_eq(parser.getLaunch(), true);
}

Test(tests_Parser, launch_2)
{
    Parser parser;

    parser.setLaunch(false);
    cr_assert_eq(parser.getLaunch(), false);
}

Test(tests_Parser, firstOrder_1)
{
    Parser parser;

    cr_assert_eq(parser.getFirstOrder(), true);
}

Test(tests_Parser, firstOrder_2)
{
    Parser parser;

    parser.setFirstOrder(false);
    cr_assert_eq(parser.getFirstOrder(), false);
}

Test(tests_Parser, checkCommands_1)
{
    Parser parser;

    cr_assert_eq(parser.checkCommands("test"), false);
}

Test(tests_Parser, getMenu_1)
{
    Parser parser;

    cr_assert_not_null(parser.getMenu());
}

Test(tests_Parser, formatOrder_1)
{
    Parser parser;

    parser.formatOrder("Regina S x1");
    cr_assert_neq(parser.getOrder(), "");
}

Test(tests_Parser, formatOrder_2)
{
    Parser parser;

    cr_assert_throw(parser.formatOrder("Test"), ParserError, "Too few arguments.");
}