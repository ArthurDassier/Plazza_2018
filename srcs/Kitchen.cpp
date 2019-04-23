/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.cpp
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int nb_cooks):
    _doe(5),
    _ham(5),
    _steak(5),
    _goat_cheese(5),
    _tomato(5),
    _eggplant(5),
    _gruyere(5),
    _mushrooms(5)
{
    for (int i = 0; i < nb_cooks; i++) {
        Cook current_cook = Cook(i);
        _cookTab.push_back(current_cook);
    }
}

Kitchen::~Kitchen()
{
}
