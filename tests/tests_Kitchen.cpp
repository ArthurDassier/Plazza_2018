/*
** EPITECH PROJECT, 2019
** tests_kitchen.cpp
** File description:
** tests_kitchen
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Kitchen.hpp"

Test(tests_kitchen, getName)
{
    Kitchen test(1, 1, 1, 1);

    cr_assert_eq(test.getName(), 1);
}

Test(tests_kitchen, getName2)
{
    Kitchen test(1, 1, 1, 1);

    cr_assert_neq(test.getName(), 2);
}

Test(tests_kitchen, setName)
{
    Kitchen test(1, 1, 1, 1);

    test.setName(2);
    cr_assert_eq(test.getName(), 2);
}

Test(tests_kitchen, setName2)
{
    Kitchen test(2, 1, 1, 1);

    test.setName(1);
    cr_assert_neq(test.getName(), 2);
}
