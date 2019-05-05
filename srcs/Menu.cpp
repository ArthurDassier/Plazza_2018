/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu()
{
    _pizzaType[Regina] = std::make_tuple("Regina", t_ingredients{0, 1, 0, 0, 1, 1, 1, 0, 1}, 2);
    _pizzaType[Margarita] = std::make_tuple("Margarita", t_ingredients{0, 1, 0, 0, 1, 0, 1, 0, 1}, 1);
    _pizzaType[Americana] = std::make_tuple("Americana", t_ingredients{0, 1, 0, 0, 1, 0, 0, 1, 1}, 2);
    _pizzaType[Fantasia] = std::make_tuple("Fantasia", t_ingredients{1, 1, 1, 1, 0, 0, 0, 0, 1}, 4);
}

t_ingredients Menu::customIngredients()
{
    auto ingredients = getIngredients();

    t_ingredients pizza = {
        ingredients[0].first,
        ingredients[1].first,
        ingredients[2].first,
        ingredients[3].first,
        ingredients[4].first,
        ingredients[5].first,
        ingredients[6].first,
        ingredients[7].first,
        ingredients[8].first
    };
    return pizza;
}

void Menu::addNewPizza(std::string name, t_ingredients ingredients, size_t time)
{
    std::tuple<std::string, t_ingredients, size_t> tmp(name, ingredients, time);
    std::pair<int, std::tuple<std::string, t_ingredients, size_t>> newPizza(_pizzaType.rbegin()->first * 2, tmp);
    _pizzaType.insert(newPizza);
}

void Menu::showMenu() const noexcept
{
    std::cout << "\033[1;36m====== M E N U ======\033[0m" << std::endl;
    for (auto &it : _pizzaType)
        std::cout
            << std::get<0>(it.second) << " (" << std::get<2>(it.second) << " sec)" << std::endl;
    std::cout << "\033[1;36m=====================\033[0m" << std::endl;
}

Menu::map_t Menu::getMenu() const
{
    return _pizzaType;
}

void Menu::setIngredients(std::array<std::pair<size_t, std::string>, 9> ingredients)
{
    _ingredients = ingredients;
}

std::array<std::pair<size_t, std::string>, 9> Menu::getIngredients() const noexcept
{
    return _ingredients;
}