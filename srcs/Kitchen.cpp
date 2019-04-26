/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** kitchen.cpp
*/

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

void Kitchen::workOnPizza(key_t key, char *pathname)
{
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *str;
    std::fstream file(pathname, std::fstream::out);

    _pathname = pathname;
    sleep(3);
    str = (char*) shmat(shmid,(void*)0,0);
    printf("CHUI LA KITCHEN : %s", str);
    file << str;
    file.close();
    shmdt(str);
    sleep(3);
    str = (char*) shmat(shmid,(void*)0,0);
    printf("CHUI LA KITCHEN : %s", str);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);

}