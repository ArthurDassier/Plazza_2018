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

    std::cout << "~je suis " << info->pizza << std::endl;
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
    pthread_t thread1;
    pthread_t thread2;
    struct createPizza_inf cc = {_name, kitchen, pizza, _timeWait};

    std::cout << "je suis " << pizza << " " << cc.pizza << std::endl;
    if (t1isOccuped() == false) {
        _t1Occuped = true;
        pthread_create(&thread1, NULL, &createPizza, &cc);
        if (t1isOccuped() == true && t2isOccuped() == true) {
            _allOcupped = true;
            pthread_join(thread1, NULL);
            _t1Occuped = false;
            pthread_join(thread2, NULL);
            _t2Occuped = false;
            _allOcupped = false;
            printf("jai tous fini\n");
        }
    }
    else if (t2isOccuped() == false) {
        _t2Occuped = true;
        pthread_create(&thread2, NULL, &createPizza, &cc);
        if (t1isOccuped() == true && t2isOccuped() == true) {
            _allOcupped = true;
            pthread_join(thread1, NULL);
            _t1Occuped = false;
            pthread_join(thread2, NULL);
            _t2Occuped = false;
            _allOcupped = false;
            printf("jai tous fini\n");
        }
    }
    // if (t1isOccuped() == true && t2isOccuped() == true) {
    //     _allOcupped = true;
    //     pthread_join(thread1, NULL);
    //     _t1Occuped = false;
    //     pthread_join(thread2, NULL);
    //     _t2Occuped = false;
    //     _allOcupped = false;
    //     printf("jai tous fini\n");
    // }
}