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

static void *createPizza(void *cc)
{
    struct createPizza_inf *info = (struct createPizza_inf *)cc;
    void *ret;

    mutex.lock();
    switch (info->pizza) {
        case 1: sleep(info->timeWait * 2);
            break;
        case 2: sleep(info->timeWait * 1);
            break;
        case 4: sleep(info->timeWait * 2);
            break;
        case 8: sleep(info->timeWait * 4);
            break;
        default: sleep(1);
            break;
    }
    std::cout << "Cook finish pizza" << std::endl;
    mutex.unlock();
    return (ret);
}

void Cook::manageCook(int kitchen, PizzaType pizza)
{
    struct createPizza_inf cc = {_name, kitchen, pizza, _timeWait};

    std::cout << "Cook of Kitchen " << kitchen << " prepare ";
    switch (pizza) {
        case 1: std::cout << "Regina" << std::endl;
            break;
        case 2: std::cout << "Margarita" << std::endl;
            break;
        case 4: std::cout << "Americana" << std::endl;
            break;
        case 8: std::cout << "Fantasia" << std::endl;
            break;
    }
    if (t1isOccuped() == false) {
        _t1Occuped = true;
        if (pthread_create(&_thread1, NULL, &createPizza, &cc))
            throw(ThreadError("pthread_create() error."));
        return;
    }
    else if (t2isOccuped() == false) {
        _t2Occuped = true;
        if (pthread_create(&_thread2, NULL, &createPizza, &cc))
            throw(ThreadError("pthread_create() error."));
        return;
    }
    if (t1isOccuped() == true && t2isOccuped() == true) {
        _allOcupped = true;
        return;
    }
}