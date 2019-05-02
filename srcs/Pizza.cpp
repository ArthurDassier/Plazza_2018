/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Pizza.cpp
*/

#include <algorithm>
#include "Pizza.hpp"

using namespace plz;

Pizza::Pizza(PizzaType type, PizzaSize size):
    _type(type), _size(size)
{
    auto it = std::find_if(std::begin(_pizzaTypes), std::end(_pizzaTypes),
                           [&](std::tuple<PizzaType, std::string, t_ingredients, size_t> i) {
                               return (type == std::get<0>(i));
                           });
    std::tie(_type, _name, _ing, _time) = *it;
    _pizza.size = _size;
    _pizza.type = _type;
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

Pizza::t_pizza Pizza::getPizza() const noexcept
{
    return _pizza;
}