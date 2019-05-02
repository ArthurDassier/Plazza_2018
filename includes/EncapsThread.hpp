/*
** EPITECH PROJECT, 2019
** EncapsThread.cpp
** File description:
** EncapsThread
*/

#pragma once

#include <iostream>
#include <pthread.h>
#include "PlazzaError.hpp"

class EncapsThread {
    public:
        EncapsThread(void *(void *), void *);
        ~EncapsThread() = default;

        // Members
        int waitThread(void);
        int cancelThread(void);
        void exitThread();
        int setCancelThread(int, int *);

    private:
        pthread_t _thread;
};

