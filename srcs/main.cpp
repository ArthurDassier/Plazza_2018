/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** main.cpp
*/

#include "Plazza.hpp"
#include "Reception.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"
#include "Parser.hpp"
#include "PlazzaError.hpp"

static void plazza(char **av)
{
    Reception reception(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    Parser parser;

    while (1) {
        if (std::cin.eof())
            return;
        try {
            parser.parseOrder();
            if (parser.getLaunch() == true) {
                if (parser.getIsNewMenu() == true)
                    reception.setMenu(parser.getMenu());
                reception.setLastCommand(parser.getOrder());
                reception.goToKitchens(reception.getLastCommand());
                reception.setLastCommand("");
            }
        } catch (PlazzaError const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main(int ac, char **av)
{
    try {
        if (ac != 4)
            throw(InputError("Too few parameters."));
        for (int i = 1; av[i] != NULL; ++i){
            for (int j = 0; av[i][j] != '\0'; ++j) {
                if (!isdigit(av[i][j]))
                    throw(InputError("Parameters must be digits."));
            }
        }
    } catch(PlazzaError const &e) {
        std::cerr << e.what() << std::endl;
        return (ERROR);
    }
    plazza(av);
    return (0);
}