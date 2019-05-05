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
#include "Menu.hpp"
#include "Plazza.hpp"

class Parser
{
    public:
        Parser();
        ~Parser() = default;

        void parseOrder();

        std::vector<std::string> carveOrder(std::string, char);
        void cleanOrder(std::unique_ptr<std::vector<std::string>> &);
        std::array<std::string, 3> fillArray(std::vector<std::string>);
        
        bool iequals(const std::string &, const std::string &);

        void custom();

        void setOrder(std::string);
        std::string getOrder() const noexcept;

        void setPizzaType(std::string);
        PizzaType getPizzaType() const noexcept;

        void setPizzaSize(std::string);
        PizzaSize getPizzaSize() const noexcept;

        void setPizzaNumber(std::string);
        int getPizzaNumber() const noexcept;

        void setIsNewMenu(bool);
        bool getIsNewMenu() const noexcept;

        void setLaunch(bool);
        bool getLaunch() const noexcept;

        std::shared_ptr<Menu::map_t> getMenu() const noexcept;

    private:
        Menu _menu;
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
        bool _isNewMenu;
        bool _launch;
};
