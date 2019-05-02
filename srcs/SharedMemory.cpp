/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** SharedMemory.cpp
*/

#include "PlazzaError.hpp"
#include "SharedMemory.hpp"

void SharedMemory::writeData(key_t key, size_t data_size, size_t process, std::string data)
{
    char *tmp = getData(key, data_size, process);
    
    if (sprintf(tmp, "%s\n", data.c_str()) < 0)
        throw(SharedMemoryError("sprintf() failed."));
    detachFrom(tmp);
}

char *SharedMemory::getData(key_t key, size_t data_size, size_t process) const
{
    char *data = nullptr;

    data = getDataById(shmIdGen(key, data_size, process));
    return data;
}

char *SharedMemory::getDataById(int shmId) const
{
    char *data = nullptr;

    if ((data = (char *)shmat(shmId, (void *)0, 0)) == (void *)-1)
        throw(SharedMemoryError("shmat() failed."));
    return data;
}

void SharedMemory::detachFrom(const void *data)
{
    if (shmdt(data) == -1)
        throw(SharedMemoryError("shmdt() failed."));
}

void SharedMemory::destroy(int shmId, int process)
{
    if (shmctl(shmId, process, NULL) == -1)
        throw(SharedMemoryError("shmctl() failed."));
}

key_t SharedMemory::keyGen(std::string pathname, int proj_id) const
{
    return ftok(pathname.c_str(), proj_id);
}

int SharedMemory::shmIdGen(key_t key, size_t data_size, size_t process) const
{
    int shmId = 0;

    if ((shmId = shmget(key, data_size, 0666 | process)) < 0)
        throw(SharedMemoryError("shmget() failed."));
    return shmId;
}