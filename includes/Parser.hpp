/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Parser.hpp
*/

#pragma once

#include <array>
#include <memory>
#include <string>
#include <vector>
#include "Plazza.hpp"

class Parser
{
    public:
        Parser() = default;
        ~Parser() = default;

        bool parseOrder();

        std::vector<std::string> carveOrder(std::string, char);
        void cleanOrder(std::unique_ptr<std::vector<std::string>> &);
        std::array<std::string, 3> fillArray(std::vector<std::string>);
        bool checkPizza(std::string);

        void setOrder(std::string);
        std::string getOrder() const noexcept;

        void setPizzaType(PizzaType);
        PizzaType getPizzaType() const noexcept;

        void setPizzaSize(std::string);
        PizzaSize getPizzaSize() const noexcept;

        void setPizzaNumber(std::string);
        int getPizzaNumber() const noexcept;

        bool iequals(const std::string &, const std::string &);

      private:
        std::array<std::pair<PizzaType, std::string>, 4> _pizzas
        {
            std::make_pair(Regina, "Regina"),
            std::make_pair(Margarita, "Margarita"),
            std::make_pair(Americana, "Americana"),
            std::make_pair(Fantasia, "Fantasia")
        };
        std::array<std::pair<PizzaSize, std::string>, 5> _sizes
        {
            std::make_pair(S, "S"),
            std::make_pair(M, "M"),
            std::make_pair(L, "L"),
            std::make_pair(XL, "XL"),
            std::make_pair(XXL, "XXL")
        };
        std::string _order;
        PizzaType _type;
        PizzaSize _size;
        int _nb;
};
