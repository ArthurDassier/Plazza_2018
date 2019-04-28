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
    char *str;
    std::list<Kitchen_inf>::iterator it;

    if (_list_kitchen.size() == 0)
        createKitchen(command);
    while (command.empty() == false) {
        it = _list_kitchen.begin();
        for (; it != _list_kitchen.end(); it++) {
            str = (char*)shmat(it->shmid,(void*)0,0);
            if (strcmp(str, "fini") == 0) {
                printf("ya plus de pizza\n");
                command.clear();
                return;
            } else
                command = str;
            sprintf(str, "%s", command.c_str());
            shmdt(str);
        }
        createKitchen(command);
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
    it = _list_kitchen.end();
    it--;
    std::cout << it->pathname.c_str() << std::endl;
    std::cout << it->name << std::endl;
    if ((child = fork()) == 0) {
        Kitchen new_kitchen(it->name, _nb_cook, _reset_food, _time);
        new_kitchen.workOnPizza(it->pathname, it->shmid);
    } else {
        int shmid = shmget(it->key,1024,0666|IPC_CREAT);
        str = (char*) shmat(shmid,(void*)0,0);
        sprintf(str, "%s\n", command.c_str());
        shmdt(str);
    }
    sleep(4);
    int shmid = shmget(it->key,1024,0666|IPC_CREAT);
    str = (char*) shmat(shmid,(void*)0,0);
    if (strcmp(str, "fini") == 0) {
        printf("ya plus de pizza\n");
        command.clear();
    } else {
        std::string tmp(str);
        command = tmp;
    }
    shmdt(str);
}

int Reception::addKitchen()
{
    static int nb_kitchen = 1;
    std::string kitchen_name = "log/kitchen";
    struct Kitchen_inf new_kitchen;
    int pos;
    std::string last_kitchen;

    if (_list_kitchen.size() == 0)
        pos = 1;
    else
        pos = _list_kitchen.size() + 1;
    last_kitchen = std::to_string(pos);
    kitchen_name += last_kitchen;
    new_kitchen.name = nb_kitchen;
    new_kitchen.pathname = kitchen_name;
    new_kitchen.use = true;
    new_kitchen.key = ftok(new_kitchen.pathname.c_str(), 65);
    new_kitchen.shmid = shmget(new_kitchen.key,1024,0666|IPC_CREAT);
    _list_kitchen.push_back(new_kitchen);
    nb_kitchen++;
    return (pos);
}