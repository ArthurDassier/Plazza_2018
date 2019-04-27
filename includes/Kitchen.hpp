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
#include <iostream>
#include "Cook.hpp"

class Kitchen
{
    public:
        Kitchen(int name, int nb_cooks);
        ~Kitchen();


        int getName();
        void setName(int name);
        void workOnPizza(std::string pathname, int shmid);

        std::string takePizzas(std::string);

    private:
        int _name;
        std::string _pathname;
        std::vector<PizzaType> _PizzasToPrepare;
        std::vector<Cook> _cookTab;
        int _doe;
        int _ham;
        int _steak;
        int _goat_cheese;
        int _tomato;
        int _eggplant;
        int _gruyere;
        int _mushrooms;
        int _chief_love;
};

