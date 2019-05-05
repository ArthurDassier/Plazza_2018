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
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_eq(test.getName(), 1);
}

Test(tests_Cook, getName2)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(2, 1, menu);

    cr_assert_eq(test.getName(), 2);
}

Test(tests_Cook, getName3)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_neq(test.getName(), 2);
}

Test(tests_Cook, getName4)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(2, 1, menu);

    cr_assert_neq(test.getName(), 1);
}

Test(tests_Cook, t1isOccuped)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_eq(test.t1isOccuped(), false);
}

Test(tests_Cook, t1isOccuped2)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_neq(test.t1isOccuped(), true);
}

Test(tests_Cook, t2isOccuped)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_eq(test.t2isOccuped(), false);
}

Test(tests_Cook, t2isOccuped2)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_neq(test.t2isOccuped(), true);
}

Test(tests_Cook, allisOccuped)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_eq(test.allisOccuped(), false);
}

Test(tests_Cook, allisOccuped2)
{
    std::shared_ptr<Menu::map_t> menu;
    Cook test(1, 1, menu);

    cr_assert_neq(test.allisOccuped(), true);
}
