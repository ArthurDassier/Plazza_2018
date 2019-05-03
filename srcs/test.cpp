/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** test.cpp
*/

#include "Parser.hpp"
#include "Pizza.hpp"
#include "PlazzaError.hpp"

#define ever ;;

int main(int argc, char **argv)
{
    Parser parser;
    std::string order;
    std::shared_ptr<plz::t_ingredients> stockIng = std::make_shared<plz::t_ingredients>(
        plz::t_ingredients {5, 5, 5, 5, 5, 5, 5, 5, 5}
    );
    plz::Ingredients stock;

    for (ever) {
        try {
            parser.parseOrder();
            order = parser.getOrder();
        }
        catch (PlazzaError const &e) {
            std::cerr << e.what() << std::endl;
            return (ERROR);
        }
        std::cout << "stoi(order): " << std::stoi(order) << std::endl;

        plz::Pizza pizza = plz::Pizza((PizzaType)std::stoi(order));

        std::cout << pizza.getName() << std::endl;
        std::cout << pizza.getType() << std::endl;
        std::cout << pizza.getTime() << std::endl;

        stock.updateIngredients(stockIng, pizza.getIngredients());
        std::cout << *stockIng;
        std::cout << (!stock.checkIngredients(*stockIng, pizza.getIngredients()) ? "Makable" : "Pas makable") << std::endl;
        // stock.restock(stockIng, 5);
    }
}