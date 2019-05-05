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
        void addNewPizza(std::string, t_ingredients, size_t);
        void showMenu() const noexcept;

    private:
        map_t _pizzaType;
};