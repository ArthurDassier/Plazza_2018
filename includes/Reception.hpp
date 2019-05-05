/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** reception.hpp
*/

#pragma once

#include "Plazza.hpp"
#include "Kitchen.hpp"
#include "PlazzaError.hpp"
#include "SharedMemory.hpp"
#include "Menu.hpp"

class Reception
{
    public:
        Reception(int time, int nb_cook, int reset_food);

        void setLastCommand(std::string new_command);
        std::string getLastCommand();

        void setMenu(std::shared_ptr<Menu::map_t>);
        std::shared_ptr<Menu::map_t> getMenu() const noexcept;

        std::list<Kitchen_inf> getKitchen();
        void goToKitchens(std::string);
        void createKitchen(std::string &command);
        int addKitchen();

    private:
        int _time;
        int _nb_cook;
        int _reset_food;
        std::string _command;
        std::list<Kitchen_inf> _list_kitchen;
        std::list<std::string> _list_key;
        std::shared_ptr<Menu::map_t> _menu;
        SharedMemory _SM;
};
