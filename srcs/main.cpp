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

int main(int argc, char **argv)
{
    Reception reception(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
//    auto &tmp_k : _tmp_list_kitchen;
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