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
#include <tuple>
#include <functional>
#include "Plazza.hpp"
#include "Cook.hpp"
#include "PlazzaError.hpp"
#include "SharedMemory.hpp"
#include "Pizza.hpp"

class Kitchen
{
    public:
        Kitchen(int, int, int, int);
        ~Kitchen();

        // Members
        int getName();
        void setName(int);
        void workOnPizza(std::string, int);
        std::string takePizzas(std::string, std::string);
        int sendToCook(PizzaType);
        void restock();
        int manageCook(int, PizzaType, std::tuple<Cook, std::thread, std::thread> &it, int posi);

    private:
        int _name;
        std::string _pathname;
        std::vector<PizzaType> _PizzasToPrepare;
        std::list<std::tuple<Cook, std::thread, std::thread>> _cookList;
        std::mutex mutex;
        SharedMemory _SM;
        std::shared_ptr<plz::t_ingredients> _stock;
        plz::Ingredients _ing;
        std::list<std::pair<bool, bool>> _listLock;
        int _timeRestock;
        int _timePrepare;
};