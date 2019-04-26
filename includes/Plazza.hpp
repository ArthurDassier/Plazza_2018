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

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};