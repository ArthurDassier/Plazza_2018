/*
** EPITECH PROJECT, 2019
** CCP_Plazza_2018
** File description:
** tests_Pizza.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Pizza.hpp"

Test(tests_Pizza, constructor_1)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    Pizza pizza(Regina, menu);

    cr_assert_eq(pizza.getType(), Regina);
    cr_assert_eq(pizza.getName(), "Regina");
    cr_assert_eq(pizza.getTime(), 2);
    cr_assert_eq(pizza.getIngredients().chief_love, 0);
    cr_assert_eq(pizza.getIngredients().doe, 1);
    cr_assert_eq(pizza.getIngredients().eggplant, 0);
    cr_assert_eq(pizza.getIngredients().goat_cheese, 0);
    cr_assert_eq(pizza.getIngredients().gruyere, 1);
    cr_assert_eq(pizza.getIngredients().ham, 1);
    cr_assert_eq(pizza.getIngredients().mushrooms, 1);
    cr_assert_eq(pizza.getIngredients().steak, 0);
    cr_assert_eq(pizza.getIngredients().tomato, 1);
}

Test(tests_Pizza, constructor_2)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    Pizza pizza(Fantasia, menu);

    cr_assert_eq(pizza.getType(), Fantasia);
    cr_assert_eq(pizza.getName(), "Fantasia");
    cr_assert_eq(pizza.getTime(), 4);
    cr_assert_eq(pizza.getIngredients().chief_love, 1);
    cr_assert_eq(pizza.getIngredients().doe, 1);
    cr_assert_eq(pizza.getIngredients().eggplant, 1);
    cr_assert_eq(pizza.getIngredients().goat_cheese, 1);
    cr_assert_eq(pizza.getIngredients().gruyere, 0);
    cr_assert_eq(pizza.getIngredients().ham, 0);
    cr_assert_eq(pizza.getIngredients().mushrooms, 0);
    cr_assert_eq(pizza.getIngredients().steak, 0);
    cr_assert_eq(pizza.getIngredients().tomato, 1);
}

Test(tests_Pizza, updateIngredients_1)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    auto stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    Ingredients ing;
    Pizza pizza(Regina, menu);

    ing.updateIngredients(stock, pizza.getIngredients());
    cr_assert_neq(stock->doe, 5);
    cr_assert_eq(stock->doe, 4);
    cr_assert_neq(stock->gruyere, 5);
    cr_assert_eq(stock->gruyere, 4);
    cr_assert_neq(stock->ham, 5);
    cr_assert_eq(stock->ham, 4);
    cr_assert_neq(stock->mushrooms, 5);
    cr_assert_eq(stock->mushrooms, 4);
    cr_assert_neq(stock->tomato, 5);
    cr_assert_eq(stock->tomato, 4);
}

Test(tests_Pizza, updateIngredients_2)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    auto stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    Ingredients ing;
    Pizza pizza(Regina, menu);

    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    cr_assert_neq(stock->doe, 5);
    cr_assert_eq(stock->doe, 3);
    cr_assert_neq(stock->gruyere, 5);
    cr_assert_eq(stock->gruyere, 3);
    cr_assert_neq(stock->ham, 5);
    cr_assert_eq(stock->ham, 3);
    cr_assert_neq(stock->mushrooms, 5);
    cr_assert_eq(stock->mushrooms, 3);
    cr_assert_neq(stock->tomato, 5);
    cr_assert_eq(stock->tomato, 3);
}

Test(tests_Pizza, restock_1)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    auto stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    Ingredients ing;
    Pizza pizza(Regina, menu);

    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    cr_assert_neq(stock->doe, 5);
    cr_assert_eq(stock->doe, 3);
    cr_assert_neq(stock->gruyere, 5);
    cr_assert_eq(stock->gruyere, 3);
    cr_assert_neq(stock->ham, 5);
    cr_assert_eq(stock->ham, 3);
    cr_assert_neq(stock->mushrooms, 5);
    cr_assert_eq(stock->mushrooms, 3);
    cr_assert_neq(stock->tomato, 5);
    cr_assert_eq(stock->tomato, 3);
    ing.restock(stock, 5);
    cr_assert_eq(stock->doe, 5);
    cr_assert_eq(stock->gruyere, 5);
    cr_assert_eq(stock->ham, 5);
    cr_assert_eq(stock->mushrooms, 5);
    cr_assert_eq(stock->tomato, 5);
}

Test(tests_Pizza, checkIngredients_1)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    auto stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    Ingredients ing;
    Pizza pizza(Regina, menu);
    Pizza pizza2(Margarita, menu);
    Pizza pizza3(Americana, menu);
    Pizza pizza4(Fantasia, menu);

    cr_assert_eq(ing.checkIngredients(*stock, pizza.getIngredients()), true);
    cr_assert_eq(ing.checkIngredients(*stock, pizza2.getIngredients()), true);
    cr_assert_eq(ing.checkIngredients(*stock, pizza3.getIngredients()), true);
    cr_assert_eq(ing.checkIngredients(*stock, pizza4.getIngredients()), true);
}

Test(tests_Pizza, checkIngredients_2)
{
    Menu tmp;
    auto menu = std::make_shared<Menu::map_t>(tmp.getMenu());
    auto stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    Ingredients ing;
    Pizza pizza(Regina, menu);

    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    ing.updateIngredients(stock, pizza.getIngredients());
    cr_assert_neq(stock->doe, 5);
    cr_expect_eq(stock->doe, 0);
    cr_assert_neq(stock->gruyere, 5);
    cr_expect_eq(stock->gruyere, 0);
    cr_assert_neq(stock->ham, 5);
    cr_expect_eq(stock->ham, 0);
    cr_assert_neq(stock->mushrooms, 5);
    cr_expect_eq(stock->mushrooms, 0);
    cr_assert_neq(stock->tomato, 5);
    cr_expect_eq(stock->tomato, 0);
    cr_assert_eq(ing.checkIngredients(*stock, pizza.getIngredients()), false);
}