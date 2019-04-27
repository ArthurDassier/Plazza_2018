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

int main(int argc, char **argv)
{
    Reception reception(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
//    auto &tmp_k : _tmp_list_kitchen;

    while (1) {
        if (reception.parseCommand() == 0) {
            std::cout << "Wow il commande une pizza " << 
            reception.getLastCommand() << std::endl;
            reception.goToKitchens(reception.getLastCommand());
        } else
            std::cout << "heuu c'est pas le nom d'une pizza" <<
            std::endl;
    }
}