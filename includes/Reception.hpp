/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** reception.hpp
*/

#pragma once

#include <string>
#include "Plazza.hpp"
#include "Kitchen.hpp"

class Reception 
{
    public:
        Reception(int time, int nb_cook, int reset_food);
        ~Reception();

        int parseCommand();
        void setLastCommand(std::string new_command);
        std::string getLastCommand();
        std::list<int> getKitchen();
        void goToKitchens(std::string);

    private:
        int _time;
        int _nb_cook;
        int _reset_food;
        std::string _command;
        std::list<int> _list_kitchen;
        std::list<std::string> _list_key;
};
