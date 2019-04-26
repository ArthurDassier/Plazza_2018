/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** reception.cpp
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Reception.hpp"

Reception::Reception(int time, int nb_cook, int reset_food):
    _time(time),
    _nb_cook(nb_cook),
    _reset_food(reset_food)
{
}

Reception::~Reception()
{
}

int Reception::parseCommand()
{
    std::string str;
/*    pid_t child;
    int status;

    std::getline(std::cin, str);
    std::cout << str << std::endl;
    if (str.compare("test") == 0) {
        if ((child = fork()) == 0) {
            sleep(1);
            std::cout << "je suis un fils" << std::endl;
            exit(0);
        } else
            wait(&status);
    }
    std::cout << "jai fini le parse" << std::endl;*/

    std::getline(std::cin, str);
    if (str.compare("Regina") == 0) {
        setLastCommand("Regina");
        return (0);
    }
    if (str.compare("Margarita") == 0) {
        setLastCommand("Margarita");
        return (0);
    }
    if (str.compare("Americana") == 0) {
        setLastCommand("Americana");
        return (0);
    }
    if (str.compare("Fantasia") == 0) {
        setLastCommand("Fantasia");
        return (0);
    }
    return (84);
}

void Reception::setLastCommand(std::string new_command)
{
    _command = new_command;
}

std::string Reception::getLastCommand()
{
    return (_command);
}