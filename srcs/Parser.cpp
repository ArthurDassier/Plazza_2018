/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include <algorithm>
#include "Parser.hpp"

bool Parser::parseOrder()
{
    std::string order;
    std::getline(std::cin, order);
    std::string ord;
    size_t i = 0;

    for (std::string it : carveOrder(order, ';')) {
        auto orderVector = std::make_unique<std::vector<std::string>>(carveOrder(it, ' '));
        cleanOrder(orderVector);
        for (auto &it_c : fillArray(*orderVector)) {
            switch (i) {
                case 0:
                    if (!checkPizza(it_c))
                        return (false);
                    break;
                case 1:
                    setPizzaSize(it_c);
                    break;
                case 2:
                    setPizzaNumber(it_c);
                    break;
                default:
                    break;
            }
            i++;
        }
        for (int j = 0; j < getPizzaNumber(); j++)
            ord += std::to_string(getPizzaType()) + "\n";
        setOrder(_order += ord);
        ord.clear();
        i = 0;
    }
    return (true);
}

std::vector<std::string> Parser::carveOrder(std::string str, char c)
{
    std::vector<std::string> order;
    std::string tmp;

    for (char &it : str) {
        if (it != c)
            tmp += it;
        else {
            order.push_back(tmp);
            tmp.clear();
        }
    }
    order.push_back(tmp);
    tmp.clear();
    return order;
}

bool Parser::iequals(const std::string &a, const std::string &b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

void Parser::cleanOrder(std::unique_ptr<std::vector<std::string>> &order)
{
    std::vector<std::string> tmp;

    for (auto &it : *order) {
        if (it != "")
            tmp.push_back(it);
    }
    order->swap(tmp);
}

std::array<std::string, 3> Parser::fillArray(std::vector<std::string> order)
{
    std::array<std::string, 3> tmp;
    size_t i = 0;

    for (std::string &it : order) {
        if (i >= 3)
            break;
        tmp[i] = it;
        i++;
    }
    return tmp;
}

bool Parser::checkPizza(std::string pizza)
{
    auto it = std::find_if(std::begin(_pizzas), std::end(_pizzas),
                           [&](std::pair<PizzaType, std::string> i) {
                               return (iequals(pizza, i.second));
                           });
    if (it == std::end(_pizzas))
        return (false);
    setPizzaType(it->first);
    return (true);
}

void Parser::setOrder(std::string order)
{
    _order = order;
}

std::string Parser::getOrder() const noexcept
{
    return _order;
}

void Parser::setPizzaType(PizzaType type)
{
    _type = type;
}

PizzaType Parser::getPizzaType() const noexcept
{
    return _type;
}

void Parser::setPizzaSize(std::string size)
{
    auto it = std::find_if(std::begin(_sizes), std::end(_sizes),
                           [&](std::pair<PizzaSize, std::string> i) {
                               return (iequals(size, i.second));
                           });
    if (it != std::end(_sizes))
        _size = it->first;
}

PizzaSize Parser::getPizzaSize() const noexcept
{
    return _size;
}

void Parser::setPizzaNumber(std::string nb)
{
    if (nb.front() == 'x')
        nb.erase(nb.begin(), nb.begin() + 1);
    _nb = std::stoi(nb);
}

int Parser::getPizzaNumber() const noexcept
{
    return _nb;
}