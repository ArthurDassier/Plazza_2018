/*
** EPITECH PROJECT, 2019
** Plazza.hpp
** File description:
** Plazza
*/

#pragma once

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <cstdio>
#include <list>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mutex>

#define ERROR 84

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
    Nothing = 0
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

typedef struct s_ingredients
{
    size_t chief_love;
    size_t doe;
    size_t eggplant;
    size_t goat_cheese;
    size_t gruyere;
    size_t ham;
    size_t mushrooms;
    size_t steak;
    size_t tomato;

    friend std::ostream &operator<<(std::ostream &os, s_ingredients const &a)
    {
        return os
               << "chief_love: " << a.chief_love << std::endl
               << "doe: " << a.doe << std::endl
               << "eggplant: " << a.eggplant << std::endl
               << "goat_cheese: " << a.goat_cheese << std::endl
               << "gruyere: " << a.gruyere << std::endl
               << "ham: " << a.ham << std::endl
               << "mushrooms: " << a.mushrooms << std::endl
               << "steak: " << a.steak << std::endl
               << "tomato: " << a.tomato << std::endl;
    }
} t_ingredients;

// typedef std::map<int, std::tuple<std::string, t_ingredients, size_t>> map_t;

// enum PizzaIngredients
// {
//     ChiefLove,
//     Doe,
//     Eggplant,
//     GoatCheese,
//     Gruyere,
//     Ham,
//     Mushrooms,
//     Steak,
//     Tomato
// };

struct Kitchen_inf
{
    std::string pathname;
    key_t key;
    int shmid;
    int name;
    bool use;
};