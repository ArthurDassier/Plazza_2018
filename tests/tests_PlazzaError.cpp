/*
** EPITECH PROJECT, 2019
** CCP_Plazza_2018
** File description:
** tests_PlazzaError.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "PlazzaError.hpp"

Test(tests_PlazzaError, constructor_1)
{
    PlazzaError error("Error_msg", "Component");
    cr_assert_not_null(error.what());
}

Test(tests_PlazzaError, FileError_1)
{
    FileError error("Error_msg");
    cr_assert_not_null(error.what());
}

Test(tests_PlazzaError, InputError_1)
{
    InputError error("Error_msg");
    cr_assert_not_null(error.what());
}

Test(tests_PlazzaError, ParserError_1)
{
    ParserError error("Error_msg");
    cr_assert_not_null(error.what());
}

Test(tests_PlazzaError, SharedMemoryError_1)
{
    SharedMemoryError error("Error_msg");
    cr_assert_not_null(error.what());
}

Test(tests_PlazzaError, ThreadError_1)
{
    ThreadError error("Error_msg");
    cr_assert_not_null(error.what());
}