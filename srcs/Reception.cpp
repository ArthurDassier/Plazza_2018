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

void Reception::goToKitchens(std::string command)
{
    char *str;
    std::list<Kitchen_inf>::iterator it;

    createKitchen(command);
    while (command.empty() == false) {
        for (it = _list_kitchen.begin(); it != _list_kitchen.end(); it++) {
            try {
                str = _SM.getDataById(it->shmid);
                if (strcmp(str, "end") == 0) {
                    command.clear();
                    return;
                } else
                    command = str;
                sprintf(str, "%s", command.c_str());
                shmdt(str);
            } catch (PlazzaError const &e) {
                throw(e);
            }
        }
        createKitchen(command);
    }
}

void Reception::createKitchen(std::string &command)
{
    pid_t child;
    char *str;
    std::list<Kitchen_inf>::iterator it;

    addKitchen();
    it = _list_kitchen.end();
    it--;
    std::cout << "\033[1;32mKitchen " << it->name << " created\033[0m" << std::endl;
    if ((child = fork()) == 0) {
        Kitchen new_kitchen(it->name, _nb_cook, _reset_food, _time, _menu);
        new_kitchen.workOnPizza(it->pathname, it->shmid);
    } else
        _SM.writeData(it->key, 1024, IPC_CREAT, command);
    sleep(4);
    str = _SM.getData(it->key, 1024, IPC_CREAT);
    if (strcmp(str, "end") == 0)
        command.clear();
    else {
        std::string tmp(str);
        command = tmp;
    }
    _SM.detachFrom(str);
}

int Reception::addKitchen()
{
    static int nb_kitchen = 1;
    std::string kitchen_name = "log/kitchen";
    struct Kitchen_inf new_kitchen;
    int pos;
    std::string last_kitchen;

    pos = (_list_kitchen.size() == 0) ? 1 : _list_kitchen.size() + 1;
    last_kitchen = std::to_string(pos);
    kitchen_name += last_kitchen;
    new_kitchen.name = nb_kitchen;
    new_kitchen.pathname = kitchen_name;
    new_kitchen.use = true;
    new_kitchen.key = _SM.keyGen(new_kitchen.pathname, 65);
    new_kitchen.shmid = _SM.shmIdGen(new_kitchen.key, 1024, IPC_CREAT);
    if (new_kitchen.shmid < 0)
        throw(SharedMemoryError("shmget() error."));
    _list_kitchen.push_back(new_kitchen);
    nb_kitchen++;
    return (pos);
}

void Reception::setLastCommand(std::string new_command)
{
    _command = new_command;
}

std::string Reception::getLastCommand()
{
    return (_command);
}

void Reception::setMenu(std::shared_ptr<Menu::map_t> menu)
{
    _menu = menu;
}

std::shared_ptr<Menu::map_t> Reception::getMenu() const noexcept
{
    return _menu;
}

std::list<Kitchen_inf> Reception::getKitchen()
{
    return (_list_kitchen);
}