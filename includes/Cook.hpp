/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Cook.hpp
*/

#pragma once

#include "Plazza.hpp"

class Cook 
{
    public:
        Cook(int name);
        ~Cook();

        int getName() const;

    private:
        int _name;
};
