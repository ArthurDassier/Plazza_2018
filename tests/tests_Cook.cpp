/*
** EPITECH PROJECT, 2019
** tests_cook.cpp
** File description:
** tests_cook
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Cook.hpp"

Test(tests_Cook, getName1)
{
    Cook test(1, 1);

    cr_assert_eq(test.getName(), 1);
}

Test(tests_Cook, getName2)
{
    Cook test(2, 1);

    cr_assert_eq(test.getName(), 2);
}

Test(tests_Cook, getName3)
{
    Cook test(1, 1);

    cr_assert_neq(test.getName(), 2);
}

Test(tests_Cook, getName4)
{
    Cook test(2, 1);

    cr_assert_neq(test.getName(), 1);
}

Test(tests_Cook, t1isOccuped)
{
    Cook test(1, 1);

    cr_assert_eq(test.t1isOccuped(), false);
}

Test(tests_Cook, t1isOccuped2)
{
    Cook test(1, 1);

    cr_assert_neq(test.t1isOccuped(), true);
}

Test(tests_Cook, t2isOccuped)
{
    Cook test(1, 1);

    cr_assert_eq(test.t2isOccuped(), false);
}

Test(tests_Cook, t2isOccuped2)
{
    Cook test(1, 1);

    cr_assert_neq(test.t2isOccuped(), true);
}

Test(tests_Cook, allisOccuped)
{
    Cook test(1, 1);

    cr_assert_eq(test.allisOccuped(), false);
}

Test(tests_Cook, allisOccuped2)
{
    Cook test(1, 1);

    cr_assert_neq(test.allisOccuped(), true);
}
