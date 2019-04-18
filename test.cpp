/*
** EPITECH PROJECT, 2019
** test
** File description:
** thread
*/

#include "test.hpp"
#include <pthread.h>

static void *incrementCounter(void *i)
{
    la_street *cc = (la_street *)i;

    cc->lock();
    cc->modify(cc->recup() * 2);
    cc->unlock();
}

int main(void)
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    la_street cc;

    pthread_create(&t1, NULL, &incrementCounter, &cc);
    pthread_create(&t2, NULL, &incrementCounter, &cc);
    pthread_create(&t3, NULL, &incrementCounter, &cc);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    std::cout << cc.recup() << std::endl;
    return (0);
}