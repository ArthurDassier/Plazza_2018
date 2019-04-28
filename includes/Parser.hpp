/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include <array>
#include <boost/algorithm/string.hpp>
#include <memory>
#include <string>
#include <vector>
#include "Plazza.hpp"

class Parser
{
    public:
        Parser();
        ~Parser() = default;

        bool parseOrder();

        std::vector<std::string> carveOrder(std::string, char);
        void cleanOrder(std::unique_ptr<std::vector<std::string>> &);
        std::array<std::string, 3> fillArray(std::vector<std::string>);
        bool checkPizza(std::string);

        void setOrder(std::string);
        std::string getOrder() const noexcept;

        void setPizzaType(std::string);
        std::string getPizzaType() const noexcept;

        void setPizzaSize(std::string);
        PizzaSize getPizzaSize() const noexcept;

        void setPizzaNumber(std::string);
        int getPizzaNumber() const noexcept;

      private:
        std::array<std::string, 4> _pizzas
        {
            "Regina",
            "Margarita",
            "Americana",
            "Fantasia"
        };
        std::string _order;
        std::string _type;
        PizzaSize _size;
        int _nb;
};

#endif /* !PARSER_HPP_ */