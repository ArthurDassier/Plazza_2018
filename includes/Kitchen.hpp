/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.hpp
*/

#pragma once

#include <vector>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <pthread.h>
#include "Plazza.hpp"
#include "Cook.hpp"

class Kitchen
{
    public:
        Kitchen(int name, int nb_cooks, int timeRestock, double timePrepare);
        ~Kitchen();

        int getName();
        void setName(int name);
        void workOnPizza(std::string pathname, int shmid);
        std::string takePizzas(std::string, std::string);
        int sendToCook(PizzaType);
        void restock();

    private:
        int _name;
        std::string _pathname;
        std::vector<PizzaType> _PizzasToPrepare;
        std::list<Cook> _cookList;
        std::mutex mutex;
        std::list<pthread_t> _threadList;
        int _doe;
        int _ham;
        int _steak;
        int _goat_cheese;
        int _tomato;
        int _eggplant;
        int _gruyere;
        int _mushrooms;
        int _chief_love;
        int _timeRestock;
        double _timePrepare;
};