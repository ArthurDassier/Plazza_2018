/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** test.cpp
*/

#include "Pizza.hpp"

int main(int argc, char **argv)
{
    plz::Pizza pizza = plz::Pizza(Fantasia, S);

    std::cout << pizza.getName() << std::endl;
    std::cout << pizza.getSize() << std::endl;
    std::cout << pizza.getType() << std::endl;
}