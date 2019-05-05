/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include <algorithm>
#include "Parser.hpp"
#include "PlazzaError.hpp"

Parser::Parser():
    _firstOrder(true),
    _order(""),
    _type((PizzaType)0),
    _size((PizzaSize)0),
    _nb(0),
    _isNewMenu(true),
    _launch(true)
{
}

void Parser::resetParser()
{
    if (getFirstOrder() == true)
        setFirstOrder(false);
    else
        setIsNewMenu(false);
    setOrder("");
    setLaunch(true);
}

void Parser::parseOrder()
{
    std::string order;

    std::getline(std::cin, order);
    if (std::cin.eof()) {
        throw(InputError("Program ending."));
        return;
    }
    resetParser();
    if (checkCommands(order) == false)
        for (std::string it : carveOrder(order, ';'))
            formatOrder(it);
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

void Parser::cleanOrder(std::unique_ptr<std::vector<std::string>> &order)
{
    std::vector<std::string> tmp;

    for (auto &it : *order) {
        if (it != "")
            tmp.push_back(it);
    }
    order->swap(tmp);
}

void Parser::formatOrder(std::string order)
{
    auto orderVector = std::make_unique<std::vector<std::string>>(carveOrder(order, ' '));
    std::string final_order;
    size_t i = 0;

    cleanOrder(orderVector);
    if (orderVector->size() < 3)
        throw(ParserError("Too few arguments."));
    for (auto &it_c : fillArray(*orderVector)) {
        switch (i) {
            case 0:
                setPizzaType(it_c);
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
        final_order += std::to_string(getPizzaType()) + "\n";
    setOrder(_order += final_order);
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

bool Parser::iequals(const std::string &a, const std::string &b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

bool Parser::checkCommands(std::string order)
{
    if (iequals(order, "custom")) {
        custom();
        return true;
    }
    if (iequals(order, "menu")) {
        setFirstOrder(true);
        setLaunch(false);
        _menu.showMenu();
        return true;
    }
    return false;
}

void Parser::custom()
{
    auto ingredients = _menu.getIngredients();
    auto menu = _menu.getMenu();
    std::string name;
    std::string order;
    int time = 0;

    std::cout << "\033[1;36mWelcome to the custom menu\033[0m" << std::endl;
    std::cout << "Please enter pizza's name: ";
    std::getline(std::cin, name);
    auto it = std::find_if(std::begin(menu), std::end(menu),
                           [&](std::pair<int, std::tuple<std::string, t_ingredients, size_t>> i) {
                               return (iequals(name, std::get<0>(i.second)));
                           });
    if (it != std::end(menu))
        throw(ParserError("Pizza already exists."));
    for (auto &it : ingredients) {
        std::cout << it.second << "? [y/n]: ";
        std::getline(std::cin, order);
        if (iequals(order, "y")) {
            it.first = 1;
            time++;
        }
    }
    std::string size;
    std::cout << "Please enter pizza's size: ";
    std::getline(std::cin, size);
    std::cout << "Please enter number of pizza: ";
    std::string nb;
    std::getline(std::cin, nb);
    _menu.setIngredients(ingredients);
    _menu.addNewPizza(name, _menu.customIngredients(), time);
    setIsNewMenu(true);
    formatOrder(name + " " + size + " " + nb);
}

void Parser::setFirstOrder(bool firstOrder)
{
    _firstOrder = firstOrder;
}

bool Parser::getFirstOrder() const noexcept
{
    return _firstOrder;
}

void Parser::setOrder(std::string order)
{
    _order = order;
}

std::string Parser::getOrder() const noexcept
{
    return _order;
}

void Parser::setPizzaType(std::string type)
{
    try {
        auto menu = _menu.getMenu();
        auto it = std::find_if(std::begin(menu), std::end(menu),
                               [&](std::pair<int, std::tuple<std::string, t_ingredients, size_t>> i) {
                                   return (iequals(type, std::get<0>(i.second)));
                               });
        if (it != std::end(menu))
            _type = (PizzaType)it->first;
        else
            throw(ParserError("Invalid type of pizza."));
    } catch (PlazzaError const &e) {
        throw(e);
    }
}

PizzaType Parser::getPizzaType() const noexcept
{
    return _type;
}

void Parser::setPizzaSize(std::string size)
{
    try {
        auto it = std::find_if(std::begin(_sizes), std::end(_sizes),
                            [&](std::pair<PizzaSize, std::string> i) {
                                return (iequals(size, i.second));
                            });
        if (it != std::end(_sizes))
            _size = it->first;
        else
            throw(ParserError("Invalid size of pizza."));
    } catch (PlazzaError const &e) {
        throw(e);
    }
}

PizzaSize Parser::getPizzaSize() const noexcept
{
    return _size;
}

void Parser::setPizzaNumber(std::string nb)
{
    try {
        if (nb.front() == 'x')
            nb.erase(nb.begin(), nb.begin() + 1);
        try {
            _nb = std::stoi(nb);
        } catch (std::invalid_argument &e){
            throw(ParserError("Invalid number of pizza."));
        }
    } catch (PlazzaError const &e) {
        throw(e);
    }
}

int Parser::getPizzaNumber() const noexcept
{
    return _nb;
}

void Parser::setIsNewMenu(bool isNewMenu)
{
    _isNewMenu = isNewMenu;
}

bool Parser::getIsNewMenu() const noexcept
{
    return _isNewMenu;
}

void Parser::setLaunch(bool launch)
{
    _launch = launch;
}

bool Parser::getLaunch() const noexcept
{
    return _launch;
}

std::shared_ptr<Menu::map_t> Parser::getMenu() const noexcept
{
    auto menu = _menu.getMenu();

    return std::make_shared<Menu::map_t>(menu);
}