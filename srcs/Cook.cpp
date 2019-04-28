/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** cook.cpp
*/

#include "Cook.hpp"

std::mutex mutex;

Cook::Cook(int name, double timeWait)
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

    mutex.lock();
    sleep(5);
    std::cout << "~je suis " << info->pizza << std::endl;
    mutex.unlock();
    return (cc);
    // mutex.lock();
    // sleep(info->timeWait/1000);
    // std::cout << "le cook" << info->name << " de kitchen" << info->kitchen 
    // << " a fini " << info->pizza << std::endl;
    // mutex.unlock();
    // return (cc);
}

void Cook::manageCook(int kitchen, PizzaType pizza)
{
    struct createPizza_inf cc = {_name, kitchen, pizza, _timeWait};

    std::cout << "je suis " << pizza << " " << cc.pizza << std::endl;
    if (t1isOccuped() == false) {
        _t1Occuped = true;
        pthread_create(&_thread1, NULL, &createPizza, &cc);
        // if (t1isOccuped() == true && t2isOccuped() == true) {
        //     _allOcupped = true;
        //     pthread_join(thread1, NULL);
        //     _t1Occuped = false;
        //     pthread_join(thread2, NULL);
        //     _t2Occuped = false;
        //     _allOcupped = false;
        //     printf("jai tous fini\n");
        // }
        return;
    }
    else if (t2isOccuped() == false) {
        _t2Occuped = true;
        pthread_create(&_thread2, NULL, &createPizza, &cc);
        // if (t1isOccuped() == true && t2isOccuped() == true) {
        //     _allOcupped = true;
        //     pthread_join(thread1, NULL);
        //     _t1Occuped = false;
        //     pthread_join(thread2, NULL);
        //     _t2Occuped = false;
        //     _allOcupped = false;
        //     printf("jai tous fini\n");
        // }
        return;
    }
    if (t1isOccuped() == true && t2isOccuped() == true) {
            _allOcupped = true;
            return;
            // pthread_join(_thread1, NULL);
            // _t1Occuped = false;
            // pthread_join(_thread2, NULL);
            // _t2Occuped = false;
            // _allOcupped = false;
            // printf("jai tous fini\n");
    }
}