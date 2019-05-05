/*
** EPITECH PROJECT, 2019
** tests_kitchen.cpp
** File description:
** tests_kitchen
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Kitchen.hpp"
#include "Pizza.hpp"

Test(tests_kitchen, getName)
{
    std::shared_ptr<Menu::map_t> menu;
    Kitchen test(1, 1, 1, 1, menu);

    cr_assert_eq(test.getName(), 1);
}

Test(tests_kitchen, getName2)
{
    std::shared_ptr<Menu::map_t> menu;
    Kitchen test(1, 1, 1, 1, menu);

    cr_assert_neq(test.getName(), 2);
}

Test(tests_kitchen, setName)
{
    std::shared_ptr<Menu::map_t> menu;
    Kitchen test(1, 1, 1, 1, menu);

    test.setName(2);
    cr_assert_eq(test.getName(), 2);
}

Test(tests_kitchen, setName2)
{
    std::shared_ptr<Menu::map_t> menu;
    Kitchen test(2, 1, 1, 1, menu);

    test.setName(1);
    cr_assert_neq(test.getName(), 2);
}
