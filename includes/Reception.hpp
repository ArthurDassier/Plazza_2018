/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** reception.hpp
*/

#pragma once

#include <string>
#include "Plazza.hpp"

class Reception 
{
    public:
        Reception(int time, int nb_cook, int reset_food);
        ~Reception();

        int parseCommand();
        void setLastCommand(std::string new_command);
        std::string getLastCommand();
        void manage_kitchen();

    private:
        int _time;
        int _nb_cook;
        int _reset_food;
        std::string _command;
};
