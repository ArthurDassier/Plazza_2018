/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** reception.cpp
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
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
std::list<int> Reception::getKitchen()
{
    return (_list_kitchen);
}

void Reception::goToKitchens(std::string command)
{
    pid_t child;
    char *str;

    if (_list_kitchen.size() == 0) {
        std::string buff = "log/kitchen1";
        key_t key = ftok(buff.c_str(), 65);
        std::cout << key << std::endl;
        _list_kitchen.push_back(1);
        _list_key.push_back(buff);
        if ((child = fork()) == 0) {
            Kitchen new_kitchen(1, _nb_cook);
            new_kitchen.workOnPizza(key, (char *)buff.c_str());
        } else {
            int shmid = shmget(key,1024,0666|IPC_CREAT);
            str = (char*) shmat(shmid,(void*)0,0);
            sprintf(str, "%s\n", command.c_str());
            shmdt(str);
        }
        sleep(4);
        key_t nkey = ftok("log/tes", 65);
        int nshmid = shmget(nkey,1024,0666|IPC_CREAT);
        str = (char*) shmat(nshmid,(void*)0,0);
        sprintf(str, "COUCOU\n");
        shmdt(str);
    }
}