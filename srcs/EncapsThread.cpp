/*
** EPITECH PROJECT, 2019
** EncapsThread.cpp
** File description:
** EncapsThread
*/

#include "EncapsThread.hpp"

EncapsThread::EncapsThread(void *function(void *), void *param)
{
    if (pthread_create(&_thread, NULL, function, param))
        throw(ThreadError("pthread_create() error."));
}

int EncapsThread::waitThread(void)
{
    return pthread_join(_thread, NULL);
}

int EncapsThread::cancelThread(void)
{
    return pthread_cancel(_thread);
}

void EncapsThread::exitThread()
{
    pthread_exit(NULL);
}

int EncapsThread::setCancelThread(int state, int *etat)
{
    return (pthread_setcancelstate (state, etat));
}