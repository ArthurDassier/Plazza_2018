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
        try {
            parser.parseOrder();
            reception.setLastCommand(parser.getOrder());
            reception.goToKitchens(reception.getLastCommand());
        } catch (PlazzaError const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    for (int i = 1; av[i] != NULL; ++i) {
        for (int j = 0; av[i][j] != '\0'; ++j) {
            if (!isdigit(av[i][j]))
                return (84);
        }
    }
    plazza(av);
    return (0);
}