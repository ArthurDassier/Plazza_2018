/*
** EPITECH PROJECT, 2019
** b
** File description:
** b
*/

#ifndef TEST_HPP_
#define TEST_HPP_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <mutex>
#include <list>

class IMutex 
{
    public:
        virtual ~IMutex () = default;
        virtual void lock() = 0;
        virtual void unlock () = 0;
        virtual void trylock () = 0;
};

class la_street : virtual IMutex 
{
    public:
        void lock() { pthread_mutex_lock(&mutex); }
        void unlock() { pthread_mutex_unlock(&mutex); }
        void trylock() { std::cout << "hehe" << std::endl; }
        int recup() { return (i); }
        void modify(int a) { i = a; }
    private:
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        int i = 2;
};

class ISafeQueue
{
    public:
        virtual ~ISafeQueue () = default;
        virtual void push(int value) = 0;
        virtual bool tryPop(int &value) = 0;
};

class ex5 : virtual ISafeQueue
{
    public:
        void push(int value) {
            mutex.lock();
            list.push_back(value);
            mutex.unlock();
        }
        bool tryPop(int &value) {
            mutex.lock();
            if (list.empty() == true) {
                mutex.unlock();
                return (false);
            }
            value = list.back();
            list.pop_back();
            mutex.unlock();
            return (true);
        }
    private:
        std::mutex mutex;
        std::list<int> list;
};

#endif /* !TEST_HPP_ */
