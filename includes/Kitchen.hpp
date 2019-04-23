/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.hpp
*/

#pragma once

#include <vector>
#include <unistd.h>
#include "Cook.hpp"

class Kitchen
{
    public:
        Kitchen(int nb_cooks);
        ~Kitchen();

    private:
        pid_t pid;
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
};

