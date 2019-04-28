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

Kitchen::Kitchen(int name, int nb_cooks, int timeRestock, int timePrepare):
    _name(name),
    _doe(5),
    _ham(5),
    _steak(5),
    _goat_cheese(5),
    _tomato(5),
    _eggplant(5),
    _gruyere(5),
    _mushrooms(5),
    _chief_love(5),
    _timeRestock(timeRestock),
    _timePrepare(timePrepare)
{
    for (int i = 0; i < nb_cooks; i++) {
        Cook current_cook = Cook(i, timePrepare);
        pthread_t thread1;
        _cookList.push_back(current_cook);
        _threadList.push_back(thread1);
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
        if (it == Regina && _doe > 0 && _tomato > 0 && _gruyere > 0 && _ham > 0 && _mushrooms > 0) {
            if (sendToCook(it) == 0) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
                _ham -= 1;
                _mushrooms -= 1;
                std::cout << "Regina in preparation" << std::endl;
                file << "Regina in preparation" << std::endl;
            } else {
                pizzas_left.push_back(std::to_string(it));
                pizzas_left.back() += '\n';
            }
        } else if (it == Margarita && _doe > 0 && _tomato > 0 && _gruyere > 0) {
            if (sendToCook(it) == 0) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
                std::cout << "Margarita in preparation" << std::endl;
                file << "Margarita in preparation" << std::endl;
            } else {
                pizzas_left.push_back(std::to_string(it));
                pizzas_left.back() += '\n';
            }
        } else if (it == Americana && _doe > 0 && _tomato > 0 && _gruyere > 0 && _steak > 0) {
            if (sendToCook(it) == 0) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
                _steak -= 1;
                std::cout << "Americana in preparation" << std::endl;
                file << "Americana in preparation" << std::endl;
            } else {
                pizzas_left.push_back(std::to_string(it));
                pizzas_left.back() += '\n';
            }
        } else if (it == Fantasia && _doe > 0 && _tomato > 0 && _eggplant > 0 && _goat_cheese > 0 && _chief_love > 0) {
            if (sendToCook(it) == 0) {
                _doe -= 1;
                _tomato -= 1;
                _eggplant -= 1;
                _goat_cheese -= 1;
                _chief_love -= 1;
                std::cout << "Fantasia in preparation" << std::endl;
                file << "Fantasia in preparation" << std::endl;
            } else {
                pizzas_left.push_back(std::to_string(it));
                pizzas_left.back() += '\n';
            }
        } else {
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
    static int ntm = 0;

    _pathname = pathname;
    while (1) {
        sleep(1);
        if (lock_clock == 1)
            clocke++;
        if (clocke == (_timeRestock / 1000))
            restock();
        str = (char*) shmat(shmid, (void*)0, 0);
        if (str == (void *)-1)
            throw(SharedMemoryError("shmat error."));
        if (strcmp(str, "end") != 0) {
            if (_doe == 0 || _ham == 0 || _steak == 0 || _goat_cheese == 0 ||
                _tomato == 0 || _eggplant == 0 || _gruyere == 0 || _mushrooms == 0 ||
                _chief_love == 0) {
                ntm++;
                if (ntm == 5) {
                    std::cout << "Kitchen " << _name << " closed" << std::endl;
                    exit (0);
                }
            }
            else {
                ntm = 0;
                lock_clock = 0;
                clocke = 0;
                std::string tmp(str);
                std::string other;
                other = takePizzas(pathname, tmp);
                if (other.size() == 0)
                    sprintf(str, "%s", "end");
                else
                    sprintf(str, "%s", other.c_str());
            }
        } else {
            lock_clock = 1;
            if (clocke == 5) {
                std::cout << "Kitchen " << _name << " closed" << std::endl;
                exit (0);
            }
            std::cout << "Kitchen " << _name << " is waiting" << std::endl;
        }
        shmdt(str);
    }
    file.close();
    shmctl(shmid, IPC_RMID, NULL);
}

int Kitchen::sendToCook(PizzaType pizza)
{
    std::list<Cook>::iterator it = _cookList.begin();

    try {
        for (; it != _cookList.end(); it++)
            if (it->allisOccuped() == false) {
                it->manageCook(_name, pizza);
                return (0);
            }
    } catch (PlazzaError const &e) {
        throw(e);
    }
    return (84);
}

void Kitchen::restock()
{
    _doe++;
    _ham++;
    _steak++;
    _goat_cheese++;
    _tomato++;
    _eggplant++;
    _gruyere++;
    _mushrooms++;
    _chief_love++;
}