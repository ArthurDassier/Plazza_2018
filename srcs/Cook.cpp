/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** cook.cpp
*/

#include "Cook.hpp"

std::mutex mutex;

Cook::Cook(int name, int timeWait, std::shared_ptr<Menu::map_t> menu):
    _t1Occuped(false),
    _t2Occuped(false),
    _allOcupped(false),
    _name(name),
    _nbCurrPizza(0),
    _timeWait(timeWait),
    _menu(menu)
{
}

Cook::~Cook()
{
}

int Cook::getName() const
{
    return (_name);
}

bool Cook::t1isOccuped() const
{
    return (_t1Occuped);
}

bool Cook::t2isOccuped() const
{
    return (_t2Occuped);
}

bool Cook::allisOccuped() const
{
    return (_allOcupped);
}

void *Cook::createPizza(void *cc)
{
    PizzaType info = *(reinterpret_cast<PizzaType *>(&cc));
    void *ret;
    Pizza pizza = Pizza(info, _menu);

    mutex.lock();
    sleep(_timeWait * pizza.getTime());
    std::cout << "Cook finished " << pizza.getName() << std::endl;
    mutex.unlock();
    return (ret);
}
