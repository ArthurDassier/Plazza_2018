/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Pizza.hpp
*/

#pragma once

#include <map>
#include <memory>
#include <vector>
#include "Menu.hpp"
#include "Plazza.hpp"

class Ingredients
{
    public:
        void updateIngredients(std::shared_ptr<t_ingredients>, t_ingredients);
        void restock(std::shared_ptr<t_ingredients>, size_t);
        bool checkIngredients(t_ingredients, t_ingredients);
        bool checkIsEmpty(std::shared_ptr<t_ingredients>);
};

class Pizza : public Menu
{
    public:
        Pizza(PizzaType, std::shared_ptr<map_t>);

        PizzaType getType() const noexcept;
        std::string getName() const noexcept;
        t_ingredients getIngredients() const noexcept;
        size_t getTime() const noexcept;

    private:
        Menu _menu;
        PizzaType _type;
        std::string _name;
        t_ingredients _ing;
        size_t _time;
};