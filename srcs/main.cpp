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

static void plazza(char **av)
{
    Reception reception(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    Parser parser;

    while (1) {
        if (!parser.parseOrder()) {
            std::cout << "heuu c'est pas le nom d'une pizza" <<
            std::endl;
        } else {
            reception.setLastCommand(parser.getOrder());
            std::cout << "Wow il commande une pizza " <<
            reception.getLastCommand() << std::endl;
            reception.goToKitchens(reception.getLastCommand());
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