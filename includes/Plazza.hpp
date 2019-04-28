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

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

struct Kitchen_inf
{
    std::string pathname;
    key_t key;
    int shmid;
    int name;
    bool use;
};