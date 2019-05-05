/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Pizza.cpp
*/

#include <algorithm>
#include "Pizza.hpp"

void Ingredients::updateIngredients(std::shared_ptr<t_ingredients> stock, t_ingredients pizza)
{
    stock->chief_love -= pizza.chief_love;
    stock->doe -= pizza.doe;
    stock->eggplant -= pizza.eggplant;
    stock->goat_cheese -= pizza.goat_cheese;
    stock->gruyere -= pizza.gruyere;
    stock->ham -= pizza.ham;
    stock->mushrooms -= pizza.mushrooms;
    stock->steak -= pizza.steak;
    stock->tomato -= pizza.tomato;
}

void Ingredients::restock(std::shared_ptr<t_ingredients> stock, size_t max)
{
    stock->chief_love = max;
    stock->doe = max;
    stock->eggplant = max;
    stock->goat_cheese = max;
    stock->gruyere = max;
    stock->ham = max;
    stock->mushrooms = max;
    stock->steak = max;
    stock->tomato = max;
}

bool Ingredients::checkIngredients(t_ingredients stock, t_ingredients pizza)
{
    bool makable = true;

    if (pizza.chief_love != 0 && stock.chief_love == 0)
        makable = false;
    if (pizza.doe != 0 && stock.doe == 0)
        makable = false;
    if (pizza.eggplant != 0 && stock.eggplant == 0)
        makable = false;
    if (pizza.goat_cheese != 0 && stock.goat_cheese == 0)
        makable = false;
    if (pizza.gruyere != 0 && stock.gruyere == 0)
        makable = false;
    if (pizza.ham != 0 && stock.ham == 0)
        makable = false;
    if (pizza.mushrooms != 0 && stock.mushrooms == 0)
        makable = false;
    if (pizza.steak != 0 && stock.steak == 0)
        makable = false;
    if (pizza.tomato != 0 && stock.tomato == 0)
        makable = false;
    return makable;
}

Pizza::Pizza(PizzaType type, std::shared_ptr<map_t> menu) : _type(type)
{
    auto it = std::find_if(menu->begin(), menu->end(),
                           [&](std::pair<int, std::tuple<std::string, t_ingredients, size_t>> i) {
                               return (type == i.first);
                           });
    if (it != menu->end()) {
        std::tie(_name, _ing, _time) = it->second;
        _type = (PizzaType)it->first;
    }
}

PizzaType Pizza::getType() const noexcept
{
    return _type;
}

std::string Pizza::getName() const noexcept
{
    return _name;
}

PizzaSize Pizza::getSize() const noexcept
{
    return _size;
}

t_ingredients Pizza::getIngredients() const noexcept
{
    return _ing;
}

size_t Pizza::getTime() const noexcept
{
    return _time;
}