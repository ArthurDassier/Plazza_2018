/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** SharedMemory.hpp
*/

#pragma once

#include <list>
#include "Plazza.hpp"

class SharedMemory {
    public:
        SharedMemory() = default;//(std::list<Kitchen_inf>::iterator it);
        ~SharedMemory() = default;

        void writeData(key_t, size_t, size_t, std::string);
        char *getData(key_t, size_t, size_t) const;
        char *getDataById(int) const;
        void detachFrom(const void *);

        void destroy(int, int);

        key_t keyGen(std::string, int) const;
        int shmIdGen(key_t, size_t, size_t) const;
};