/*
** EPITECH PROJECT, 2019
** tests_reception.cpp
** File description:
** tests_reception
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Reception.hpp"

Test(tests_SDL, setLastCommand)
{
    Reception test(1, 1, 1);

    test.setLastCommand("WOOOOOWWW");
    cr_assert_eq(test.getLastCommand(), "WOOOOOWWW");
}
