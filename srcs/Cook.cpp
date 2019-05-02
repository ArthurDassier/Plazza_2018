/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** cook.cpp
*/

#include "Cook.hpp"

std::mutex mutex;

Cook::Cook(int name, int timeWait)
{
    _name = name;
    _timeWait = timeWait;
    _allOcupped = false;
    _t1Occuped = false;
    _t2Occuped = false;
    _nbCurrPizza = 0;
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
    int *info = (int *)cc;
    void *ret;

    mutex.lock();
    switch (*info) {
        case 1: sleep(_timeWait * 2);
            break;
        case 2: sleep(_timeWait * 1);
            break;
        case 4: sleep(_timeWait * 2);
            break;
        case 8: sleep(_timeWait * 4);
            break;
        default: sleep(1);
            break;
    }
    std::cout << "Cook finished pizza" << std::endl;
    mutex.unlock();
    return (ret);
}
