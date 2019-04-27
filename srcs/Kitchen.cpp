/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.cpp
*/

#include <string.h>
#include "Kitchen.hpp"

Kitchen::Kitchen(int name, int nb_cooks):
    _name(name),
    _doe(5),
    _ham(5),
    _steak(5),
    _goat_cheese(5),
    _tomato(5),
    _eggplant(5),
    _gruyere(5),
    _mushrooms(5)
{
    for (int i = 0; i < nb_cooks; i++) {
        Cook current_cook = Cook(i);
        _cookTab.push_back(current_cook);
    }
}

Kitchen::~Kitchen()
{
}

int Kitchen::getName(void)
{
    return (_name);
}

void Kitchen::setName(int name)
{
    _name = name;
}

void Kitchen::workOnPizza(char *pathname, int shmid)
{
    char *str;
    std::fstream file(pathname, std::fstream::out | std::fstream::in);

    _pathname = pathname;
    while (1) {
        sleep(1);
        str = (char*) shmat(shmid,(void*)0,0);
        if (strcmp(str, "fini") != 0) {
            printf("CHUI LA KITCHEN : %s", str);
            file << str;
            sprintf(str, "%s", "fini");
        } else
            std::cout << "j'attend" << std::endl;
        shmdt(str);
    }
    file.close();
    shmctl(shmid,IPC_RMID,NULL);
}