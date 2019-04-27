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
std::list<Kitchen_inf> Reception::getKitchen()
{
    return (_list_kitchen);
}

void Reception::goToKitchens(std::string command)
{
    pid_t child;
    char *str;
    std::list<Kitchen_inf>::iterator it;

    if (_list_kitchen.size() == 0)
        createKitchen(command);
    it = _list_kitchen.begin();
    for (; it != _list_kitchen.end(); it++) {
        if (command.size() == 0) {
            std::cout << "ya plus de pizza a faire" << std::endl;
            return;
        }
        str = (char*)shmat(it->shmid,(void*)0,0);
        sprintf(str, "%s", command.c_str());
        shmdt(str);
    }

    // sleep(4);
    // key_t nkey = ftok("log/tes", 65);
    // int nshmid = shmget(nkey,1024,0666|IPC_CREAT);
    // str = (char*) shmat(nshmid,(void*)0,0);
    // sprintf(str, "COUCOU\n");
    // shmdt(str);
}

void Reception::createKitchen(std::string &command)
{
    pid_t child;
    char *str;
    std::list<Kitchen_inf>::iterator it;

    addKitchen();
    it = _list_kitchen.begin();
    std::cout << it->pathname.c_str() << std::endl;
    std::cout << _list_kitchen.size() << std::endl;
    if ((child = fork()) == 0) {
        Kitchen new_kitchen(1, _nb_cook);
        new_kitchen.workOnPizza((char *)it->pathname.c_str(), it->shmid);
    } else {
        int shmid = shmget(it->key,1024,0666|IPC_CREAT);
        str = (char*) shmat(shmid,(void*)0,0);
        sprintf(str, "%s\n", command.c_str());
        shmdt(str);
    }
    sleep(2);
    int shmid = shmget(it->key,1024,0666|IPC_CREAT);
    str = (char*) shmat(shmid,(void*)0,0);
    if (strcmp(str, "fini") == 0) {
        printf("ya plus de pizza\n");
        command.clear();
    }
}

int Reception::addKitchen()
{
    static int nb_kitchen = 1;
    std::string kitchen_name = "log/kitchen";
    struct Kitchen_inf new_kitchen;
    int pos = 1;
    std::string last_kitchen;
    key_t key;

    if (nb_kitchen == 1) {
        new_kitchen.name = 1;
        new_kitchen.pathname = "log/kitchen1";
        new_kitchen.use = true;
        new_kitchen.key = ftok(new_kitchen.pathname.c_str(), 65);
        new_kitchen.shmid = shmget(new_kitchen.key,1024,0666|IPC_CREAT);
        _list_kitchen.push_back(new_kitchen);
        nb_kitchen++;
        return (0);
    }

    pos = _list_kitchen.size();
    pos++;
    last_kitchen = std::to_string(pos);
    kitchen_name += last_kitchen;
    std::cout << kitchen_name << std::endl;
    return (pos);
}