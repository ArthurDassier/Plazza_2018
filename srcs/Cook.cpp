/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** cook.cpp
*/

#include "Cook.hpp"

Cook::Cook(int name)
{
    _name = name;
}

Cook::~Cook()
{
}

int Cook::getName() const
{
    return (_name);
}