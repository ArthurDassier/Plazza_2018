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

Menu::map_t Menu::getMenu() const
{
    return _pizzaType;
}

void Menu::addNewPizza(std::string name, t_ingredients ingredients, size_t time)
{
    std::tuple<std::string, t_ingredients, size_t> tmp(name, ingredients, time);
    std::pair<int, std::tuple<std::string, t_ingredients, size_t>> newPizza(_pizzaType.rbegin()->first * 2, tmp);
    _pizzaType.insert(newPizza);
}

void Menu::showMenu() const noexcept
{
    for (auto &it : _pizzaType)
        std::cout << std::get<0>(it.second) << " (" << std::get<2>(it.second) << " sec)" << std::endl;
}