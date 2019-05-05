/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Menu.hpp
*/

#pragma once

#include <map>
#include "Plazza.hpp"

class Menu 
{
	public:
        typedef std::map<int, std::tuple<std::string, t_ingredients, size_t>> map_t;
        Menu();
        ~Menu() = default;

        map_t getMenu() const;

        void setIngredients(std::array<std::pair<size_t, std::string>, 9>);
        std::array<std::pair<size_t, std::string>, 9> getIngredients() const noexcept;

        t_ingredients customIngredients();
        void addNewPizza(std::string, t_ingredients, size_t);
        void showMenu() const noexcept;

    private:
        map_t _pizzaType;
        std::array<std::pair<size_t, std::string>, 9> _ingredients = {
            std::make_pair(0, "ChiefLove"),
            std::make_pair(0, "Doe"),
            std::make_pair(0, "Eggplant"),
            std::make_pair(0, "GoatCheese"),
            std::make_pair(0, "Gruyere"),
            std::make_pair(0, "Ham"),
            std::make_pair(0, "Mushrooms"),
            std::make_pair(0, "Steak"),
            std::make_pair(0, "Tomato"),
        };
};