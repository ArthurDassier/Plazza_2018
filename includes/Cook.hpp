/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Cook.hpp
*/

#pragma once

#include "Plazza.hpp"

struct createPizza_inf
{
    int name;
    int kitchen;
    PizzaType pizza;
    int timeWait;
};

class Cook 
{
    public:
        Cook(int name, int _timeWait);
        ~Cook();

        int getName() const;
        bool t1isOccuped() const;
        bool t2isOccuped() const;
        bool allisOccuped() const;
        void manageCook(int kitchen, PizzaType pizza);

    private:
        pthread_t _thread1;
        pthread_t _thread2;
        int _name;
        bool _t1Occuped;
        bool _t2Occuped;
        bool _allOcupped;
        int _nbCurrPizza;
        int _timeWait;
};
