/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.cpp
*/

#include <string.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Kitchen.hpp"

Kitchen::Kitchen(int name, int nb_cooks, int timeRestock, int timePrepare, std::shared_ptr<Menu::map_t> menu):
    _name(name),
    _timeRestock(timeRestock),
    _timePrepare(timePrepare),
    _menu(menu)
{
    _stock = std::make_shared<t_ingredients>(t_ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5});
    for (int i = 0; i < nb_cooks; ++i) {
        _cookList.emplace_back(
            std::make_tuple(
                Cook(i, timePrepare, _menu),
                std::thread(), 
                std::thread()
            )
        );
        _listLock.emplace_back(std::make_pair(false, false));
    }
}

Kitchen::~Kitchen()
{
}

int Kitchen::getName(void)
{
    return (_name);
}

void Kitchen::setName(int name)
{
    _name = name;
}

std::string Kitchen::takePizzas(std::string pathname, std::string command)
{
    std::vector<PizzaType> pizzas_to_do;
    std::vector<std::string> pizzas_left;
    std::fstream file(pathname, std::fstream::out | std::fstream::in);
    std::string pizza;
    std::string final_command;

    for (char &it : command) {
        if (it != '\n')
            pizza += it;
        else {
            pizzas_to_do.push_back(static_cast<PizzaType>(atoi(pizza.c_str())));
            pizza.clear();
        }
    }
    for (PizzaType &it : pizzas_to_do) {
        Pizza pizza = Pizza(it, _menu);
        if (_ing.checkIngredients(*_stock, pizza.getIngredients())) {
            if (sendToCook((PizzaType)pizza.getType()) == 0) {
                _ing.updateIngredients(_stock, pizza.getIngredients());
                file << pizza.getName() + " in preparation" << std::endl;
            } else {
                pizzas_left.push_back(std::to_string(it));
                pizzas_left.back() += '\n';
            }
        } else {
            if (pizza.getType() != 0)
                std::cout << "\033[1;31mNot enough ingredients to make " << pizza.getName()
                        << " in Kitchen " << _name << "\033[0m" << std::endl;
            pizzas_left.push_back(std::to_string(it));
            pizzas_left.back() += '\n';
        }
    }
    for (std::string &it : pizzas_left)
        final_command += it;
    if (final_command.find_last_of('0') != std::string::npos) {
        final_command.pop_back();
        final_command.pop_back();
    }
    return (final_command);
}

void Kitchen::workOnPizza(std::string pathname, int shmid)
{
    char *str;
    std::fstream file(pathname, std::fstream::out | std::fstream::in);
    int clocke = 0;
    int lock_clock = 0;
    static int sec = 0;
    t_ingredients tmp = t_ingredients{1, 1, 1, 1, 1, 1, 1, 1, 1};

    _pathname = pathname;
    while (1) {
        sleep(1);
        if (lock_clock == 1)
            clocke++;
        if (clocke == (_timeRestock / 1000))
            _ing.restock(_stock, 5);
        str = _SM.getDataById(shmid);
        if (strcmp(str, "end") != 0) {
            if (!_ing.checkIngredients(*_stock, tmp)) {
                sec++;
                if (sec == 5) {
                    std::cout << "\033[1;34mKitchen " << _name << " closed\033[0m" << std::endl;
                    exit (0);
                }
            } else {
                sec = 0;
                lock_clock = 0;
                clocke = 0;
                std::string tmp(str);
                std::string other;
                other = takePizzas(pathname, tmp);
                if (other.size() == 0)
                    sprintf(str, "%s", "end");
                else
                    sprintf(str, "%s", other.c_str());
                auto ttt = _listLock.begin();
                for (auto &it: _cookList) {
                    if (ttt->first == true) {
                        std::get<1>(it).join();
                        std::get<0>(it)._t1Occuped = false;
                    }
                    if (ttt->second == true) {
                        std::get<2>(it).join();
                        std::get<0>(it)._t2Occuped = false;
                    }
                    std::get<0>(it)._allOcupped = false;
                    ttt++;
                }
            }
        } else {
            lock_clock = 1;
            if (clocke == 5) {
                std::cout << "\033[1;34mKitchen " << _name << " closed\033[0m" << std::endl;
                exit (0);
            } else if (clocke == 0)
                std::cout << "Kitchen " << _name << " is waiting" << std::endl;
        }
        _SM.detachFrom(str);
    }
    file.close();
    _SM.destroy(shmid, IPC_RMID);
}

int Kitchen::sendToCook(PizzaType pizza)
{
    int posi = 0;

    try {
        for (auto &it : _cookList) {
            if (manageCook(_name, pizza, it, posi) == 0)
                return (0);
            posi++;
        }
    } catch (PlazzaError const &e) {
        throw(e);
    }
    return (84);
}

int Kitchen::manageCook(int kitchen, PizzaType type, std::tuple<Cook, std::thread, std::thread> &it, int posi)
{
    void *test = (void *)type;
    auto lock = _listLock.begin();
    Pizza pizza = Pizza(type, _menu);

    for (int i = 0; posi < i; i++)
        lock++;
    if (std::get<0>(it).t1isOccuped() == false && pizza.getType()) {
        std::get<0>(it)._t1Occuped = true;
        std::get<1>(it) = std::thread(&Cook::createPizza, std::get<0>(it), test);
        lock->first = true;
        std::cout << "Cook " << std::get<0>(it).getName() + 1 << " of Kitchen "
            << kitchen << " prepare " << pizza.getName() << std::endl;
        return (0);
    } else if (std::get<0>(it).t2isOccuped() == false && pizza.getType()) {
        std::get<0>(it)._t2Occuped = true;
        std::get<2>(it) = std::thread(&Cook::createPizza, std::get<0>(it), test);
        lock->second = true;
        std::cout << "Cook " << std::get<0>(it).getName() + 1 << " of Kitchen " 
            << kitchen << " prepare " << pizza.getName() << std::endl;
        return (0);
    }
    if (std::get<0>(it).t1isOccuped() == true && std::get<0>(it).t2isOccuped() == true) {
        std::get<0>(it)._allOcupped = true;
        return (1);
    } else
        return (0);
}