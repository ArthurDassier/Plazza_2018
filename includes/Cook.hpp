/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Cook.hpp
*/

#pragma once

#include <thread>
#include "Plazza.hpp"
#include "PlazzaError.hpp"

typedef struct
{
    int name;
    int kitchen;
    PizzaType pizza;
    int timeWait;
} createPizza_inf_t;

class Cook 
{
    public:
        Cook(int, int);
        ~Cook();

        int getName() const;
        bool t1isOccuped() const;
        bool t2isOccuped() const;
        bool allisOccuped() const;
        void manageCook(int, PizzaType);
        void *createPizza(void *);
        bool _t1Occuped;
        bool _t2Occuped;
        bool _allOcupped;

    private:
        int _name;
        int _nbCurrPizza;
        int _timeWait;
};
