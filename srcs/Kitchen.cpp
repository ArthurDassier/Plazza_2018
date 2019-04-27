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
    _mushrooms(5),
    _chief_love(5)
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

std::string Kitchen::takePizzas(std::string command)
{
    std::vector<int> pizzas_to_do;
    std::vector<std::string> pizzas_left;
    std::string pizza;
    std::string final_command;

    for (char &it : command) {
        if (it != '\n')
            pizza += it; 
        else {
            pizzas_to_do.push_back(atoi(pizza.c_str()));
            pizza.clear();
        }
    }
    for (int &it : pizzas_to_do) {
        if (it == 1) {
            if (_doe && _tomato && _gruyere && _ham && _mushrooms) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
                _ham -= 1;
                _mushrooms -= 1;
            }
        } else if (it == 2) {
            if (_doe && _tomato && _gruyere) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
            }
        } else if (it == 3) {
            if (_doe && _tomato && _gruyere && _steak) {
                _doe -= 1;
                _tomato -= 1;
                _gruyere -= 1;
                _steak -= 1;
            }
        } else if (it == 4) {
            if (_doe && _tomato && _eggplant && _goat_cheese && _chief_love) {
                _doe -= 1;
                _tomato -= 1;
                _eggplant -= 1;
                _goat_cheese -= 1;
                _chief_love -= 1;
            }
        } else {
            pizzas_left.push_back(std::to_string(it));
            pizza.end() += '\n';
        }
    }
    for (std::string &it : pizzas_left)
        final_command += it;
    return (final_command);
}

void Kitchen::workOnPizza(std::string pathname, int shmid)
{
    char *str;
    std::fstream file(pathname, std::fstream::out | std::fstream::in);

    _pathname = pathname;
    while (1) {
        sleep(1);
        str = (char*) shmat(shmid, (void*)0, 0);
        if (strcmp(str, "fini") != 0) {
            printf("CHUI LA KITCHEN%c : %s\n",
            pathname[strlen((char *)pathname.c_str()) - 1], str);
            file << str;
            sprintf(str, "%s", "fini");
        } else
            std::cout << "j'attend" << std::endl;
        shmdt(str);
    }
    file.close();
    shmctl(shmid,IPC_RMID,NULL);
}