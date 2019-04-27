/*
** EPITECH PROJECT, 2019
** tests_kitchen.cpp
** File description:
** tests_kitchen
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Kitchen.hpp"

Test(tests_kitchen, tests_kitchen)
{
    Kitchen test(1, 1);

    cr_assert_eq(test.takePizzas("1\n1\n"), "");
    cr_assert_eq(test.takePizzas("1\n1\n"), "");
    cr_assert_eq(test.takePizzas("1\n1\n"), "1\n");
    cr_assert_eq(test.takePizzas("1\n1\n"), "1\n1\n");
}

Test(tests_kitchen, tests_kitchen)
{
    Kitchen test(1, 1);

    cr_assert_eq(test.takePizzas("2\n2\n"), "");
    cr_assert_eq(test.takePizzas("2\n2\n"), "");
    cr_assert_eq(test.takePizzas("2\n2\n"), "2\n");
    cr_assert_eq(test.takePizzas("2\n2\n"), "2\n2\n");
}

Test(tests_kitchen, tests_kitchen)
{
    Kitchen test(1, 1);

    cr_assert_eq(test.takePizzas("3\n3\n"), "");
    cr_assert_eq(test.takePizzas("3\n3\n"), "");
    cr_assert_eq(test.takePizzas("3\n3\n"), "3\n");
    cr_assert_eq(test.takePizzas("3\n3\n"), "3\n3\n");
}

Test(tests_kitchen, tests_kitchen)
{
    Kitchen test(1, 1);

    cr_assert_eq(test.takePizzas("4\n4\n"), "");
    cr_assert_eq(test.takePizzas("4\n4\n"), "");
    cr_assert_eq(test.takePizzas("4\n4\n"), "4\n");
    cr_assert_eq(test.takePizzas("4\n4\n"), "4\n4\n");
}