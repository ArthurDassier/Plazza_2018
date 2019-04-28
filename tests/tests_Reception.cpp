/*
** EPITECH PROJECT, 2019
** tests_reception.cpp
** File description:
** tests_reception
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Reception.hpp"

Test(tests_Reception, setLastCommand_1)
{
    Reception test(1, 1, 1);

    test.setLastCommand("WOOOOOWWW");
    cr_assert_eq(test.getLastCommand(), "WOOOOOWWW");
}

Test(tests_Reception, setLastCommand_2)
{
    Reception test(1, 1, 1);

    test.setLastCommand("");
    cr_assert_eq(test.getLastCommand(), "");
}
