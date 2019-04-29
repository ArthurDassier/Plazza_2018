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
    Parser test;

    test.setOrder("Margarita S x2");
    cr_assert_eq(test.getOrder(), "Margarita S x2");
}

Test(tests_Parser, setOrder_2)
{
    Parser test;

    test.setOrder("");
    cr_assert_eq(test.getOrder(), "");
}

Test(tests_Parser, setPizzaType_1)
{
    Parser test;

    test.setPizzaType("Regina");
    cr_assert_eq(test.getPizzaType(), Regina);
}

Test(tests_Parser, setPizzaType_2)
{
    Parser test;

    test.setPizzaType("Margarita");
    cr_assert_eq(test.getPizzaType(), Margarita);
}

Test(tests_Parser, setPizzaType_3)
{
    Parser test;

    cr_expect_throw(test.setPizzaType("Fantasio"), PlazzaError, "Invalid type of pizza.");
}

Test(tests_Parser, setPizzaSize_1)
{
    Parser test;

    test.setPizzaSize("S");
    cr_assert_eq(test.getPizzaSize(), S);
}

Test(tests_Parser, setPizzaSize_2)
{
    Parser test;

    test.setPizzaSize("XXL");
    cr_assert_eq(test.getPizzaSize(), XXL);
}

Test(tests_Parser, setPizzaSize_3)
{
    Parser test;

    cr_expect_throw(test.setPizzaSize("XXXL"), PlazzaError, "Invalid size of pizza.");
}

Test(tests_Parser, setPizzaNumber_1)
{
    Parser test;

    test.setPizzaNumber("x3");
    cr_assert_eq(test.getPizzaNumber(), 3);
}

Test(tests_Parser, setPizzaNumber_2)
{
    Parser test;

    cr_expect_no_throw(test.setPizzaNumber("x10"), PlazzaError, "Invalid number of pizza.");
    cr_assert_eq(test.getPizzaNumber(), 10);
}

Test(tests_Parser, setPizzaNumber_3)
{
    Parser test;

    cr_assert_throw(test.setPizzaNumber("xlol3"), PlazzaError, "Invalid number of pizza.");
}

Test(tests_Parser, iequals_1)
{
    Parser test;

    cr_assert_eq(test.iequals("Regina", "Regina"), true);
}

Test(tests_Parser, iequals_2)
{
    Parser test;

    cr_assert_eq(test.iequals("Regina", "regina"), true);
}

Test(tests_Parser, iequals_3)
{
    Parser test;

    cr_assert_neq(test.iequals("Regina", "Margarita"), true);
}

Test(tests_Parser, cleanOrder_1)
{
    Parser test;
    std::unique_ptr<std::vector<std::string>> tmp = std::make_unique<std::vector<std::string>>();

    tmp->push_back("Regina");
    tmp->push_back("M");
    tmp->push_back("x3");

    test.cleanOrder(tmp);
    cr_assert_eq(tmp->at(0), "Regina");
    cr_assert_eq(tmp->at(1), "M");
    cr_assert_eq(tmp->at(2), "x3");
}

Test(tests_Parser, cleanOrder_2)
{
    Parser test;
    std::unique_ptr<std::vector<std::string>> tmp = std::make_unique<std::vector<std::string>>();

    tmp->push_back("Regina");
    tmp->push_back("");
    tmp->push_back("M");
    tmp->push_back("x3");
    tmp->push_back("");

    test.cleanOrder(tmp);
    cr_assert_eq(tmp->at(0), "Regina");
    cr_assert_eq(tmp->at(1), "M");
    cr_assert_eq(tmp->at(2), "x3");
    cr_assert_eq(tmp->size(), 3);
}

Test(tests_Parser, fillArray_1)
{
    Parser test;
    std::vector<std::string> order;
    std::array<std::string, 3> arr;

    order.push_back("Regina");
    order.push_back("M");
    order.push_back("x3");

    arr[0] = "Regina";
    arr[1] = "M";
    arr[2] = "x3";

    cr_assert_eq(test.fillArray(order), arr);
}

Test(tests_Parser, fillArray_2)
{
    Parser test;
    std::vector<std::string> order;
    std::array<std::string, 3> arr;

    order.push_back("Margarita");
    order.push_back("XL");
    order.push_back("x2");

    arr[0] = "Margarita";
    arr[1] = "XL";
    arr[2] = "x2";

    cr_assert_eq(test.fillArray(order), arr);
}

Test(tests_Parser, carveOrder_1)
{
    Parser test;
    std::vector<std::string> tmp;

    tmp.push_back("regina XXL x2");
    tmp.push_back(" fantasia M x3");
    tmp.push_back(" margarita S x1");
    cr_assert_eq(test.carveOrder("regina XXL x2; fantasia M x3; margarita S x1", ';'), tmp);
}

Test(tests_Parser, carveOrder_2)
{
    Parser test;
    std::vector<std::string> tmp;

    tmp.push_back("regina");
    tmp.push_back("M");
    tmp.push_back("x1");
    cr_assert_eq(test.carveOrder("regina M x1", ' '), tmp);
}