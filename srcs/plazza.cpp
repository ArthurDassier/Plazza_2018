/*
** EPITECH PROJECT, 2019
** Plazza.cpp
** File description:
** Plazza
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Plazza.hpp"

int main(int argc, char **argv)
{
    pid_t child;
    int status;
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    // shmat to attach to shared memory 
    char *str;

    if ((child = fork()) == 0) {
        sleep(3);
        str = (char*) shmat(shmid,(void*)0,0);
        printf("Data read from memory: %s\n",str); 
        //detach from shared memory  
        shmdt(str); 
        // destroy the shared memory 
        shmctl(shmid,IPC_RMID,NULL); 
    } else {
        std::cout << "Write Data : ";
        str = (char*) shmat(shmid,(void*)0,0); 
        // gets(str);
        // std::getline(std::cin, buf);
        std::fgets(str, 20, stdin);
    //    fgets(str, 4, stdin);
        printf("Data written in memory: %s\n", str);
        //detach from shared memory 
        shmdt(str);
        wait(&status);
    }
    return 0;
}
