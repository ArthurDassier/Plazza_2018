/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** tests_Menu.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Menu.hpp"

Test(tests_Menu, constructor_1)
{
    Menu menu;
    t_ingredients tmp = {0, 1, 0, 0, 1, 1, 1, 0, 1};

    cr_assert_eq(menu.getMenu().begin()->first, Regina);
    cr_assert_eq(std::get<0>(menu.getMenu().begin()->second), "Regina");
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).chief_love, tmp.chief_love);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).doe, tmp.doe);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).eggplant, tmp.eggplant);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).goat_cheese, tmp.goat_cheese);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).gruyere, tmp.gruyere);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).ham, tmp.ham);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).mushrooms, tmp.mushrooms);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).steak, tmp.steak);
    cr_assert_eq(std::get<1>(menu.getMenu().begin()->second).tomato, tmp.tomato);
    cr_assert_eq(std::get<2>(menu.getMenu().begin()->second), 2);
}

Test(tests_Menu, constructor_2)
{
    Menu menu;
    t_ingredients tmp = {1, 1, 1, 1, 0, 0, 0, 0, 1};

    cr_assert_eq(menu.getMenu().rbegin()->first, Fantasia);
    cr_assert_eq(std::get<0>(menu.getMenu().rbegin()->second), "Fantasia");
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).chief_love, tmp.chief_love);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).doe, tmp.doe);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).eggplant, tmp.eggplant);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).goat_cheese, tmp.goat_cheese);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).gruyere, tmp.gruyere);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).ham, tmp.ham);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).mushrooms, tmp.mushrooms);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).steak, tmp.steak);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).tomato, tmp.tomato);
    cr_assert_eq(std::get<2>(menu.getMenu().rbegin()->second), 4);
}

Test(tests_Menu, addNewPizza_1)
{
    Menu menu;
    t_ingredients ing = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    menu.addNewPizza("Calzone", ing, 6);
    cr_assert_eq(menu.getMenu().rbegin()->first, 16);
    cr_assert_eq(std::get<0>(menu.getMenu().rbegin()->second), "Calzone");
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).chief_love, ing.chief_love);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).doe, ing.doe);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).eggplant, ing.eggplant);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).goat_cheese, ing.goat_cheese);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).gruyere, ing.gruyere);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).ham, ing.ham);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).mushrooms, ing.mushrooms);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).steak, ing.steak);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).tomato, ing.tomato);
    cr_assert_eq(std::get<2>(menu.getMenu().rbegin()->second), 6);
}

Test(tests_Menu, addNewPizza_2)
{
    Menu menu;
    t_ingredients ing = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    t_ingredients ing2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    menu.addNewPizza("Calzone", ing2, 6);
    menu.addNewPizza("The Empty", ing, 1);
    cr_assert_eq(menu.getMenu().rbegin()->first, 32);
    cr_assert_eq(std::get<0>(menu.getMenu().rbegin()->second), "The Empty");
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).chief_love, ing.chief_love);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).doe, ing.doe);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).eggplant, ing.eggplant);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).goat_cheese, ing.goat_cheese);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).gruyere, ing.gruyere);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).ham, ing.ham);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).mushrooms, ing.mushrooms);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).steak, ing.steak);
    cr_assert_eq(std::get<1>(menu.getMenu().rbegin()->second).tomato, ing.tomato);
    cr_assert_eq(std::get<2>(menu.getMenu().rbegin()->second), 1);
}

Test(tests_Menu, setIngredients_1)
{
    Menu menu;
    std::array<std::pair<size_t, std::string>, 9> ingredients = {
        std::make_pair(0, "ChiefLove"),
        std::make_pair(0, "Doe"),
        std::make_pair(0, "Eggplant"),
        std::make_pair(1, "GoatCheese"),
        std::make_pair(0, "Gruyere"),
        std::make_pair(0, "Ham"),
        std::make_pair(0, "Mushrooms"),
        std::make_pair(0, "Steak"),
        std::make_pair(1, "Tomato"),
    };

    menu.setIngredients(ingredients);
    cr_assert_eq(menu.getIngredients(), ingredients);
}

Test(tests_Menu, customIngredients)
{
    Menu menu;
    t_ingredients ing = {0, 0, 0, 1, 0, 0, 0, 0, 1};
    std::array<std::pair<size_t, std::string>, 9> ingredients = {
        std::make_pair(0, "ChiefLove"),
        std::make_pair(0, "Doe"),
        std::make_pair(0, "Eggplant"),
        std::make_pair(1, "GoatCheese"),
        std::make_pair(0, "Gruyere"),
        std::make_pair(0, "Ham"),
        std::make_pair(0, "Mushrooms"),
        std::make_pair(0, "Steak"),
        std::make_pair(1, "Tomato"),
    };

    menu.setIngredients(ingredients);
    cr_assert_eq(menu.customIngredients().chief_love, ing.chief_love);
    cr_assert_eq(menu.customIngredients().doe, ing.doe);
    cr_assert_eq(menu.customIngredients().eggplant, ing.eggplant);
    cr_assert_eq(menu.customIngredients().goat_cheese, ing.goat_cheese);
    cr_assert_eq(menu.customIngredients().gruyere, ing.gruyere);
    cr_assert_eq(menu.customIngredients().ham, ing.ham);
    cr_assert_eq(menu.customIngredients().mushrooms, ing.mushrooms);
    cr_assert_eq(menu.customIngredients().steak, ing.steak);
    cr_assert_eq(menu.customIngredients().tomato, ing.tomato);
}