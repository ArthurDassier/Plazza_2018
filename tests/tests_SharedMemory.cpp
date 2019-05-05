/*
** EPITECH PROJECT, 2019
** CCP_Plazza_2018
** File description:
** tests_SharedMemory.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "PlazzaError.hpp"
#include "SharedMemory.hpp"

Test(tests_SharedMemory, keyGen_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";

    cr_assert_eq(_SM.keyGen(path, 65), ftok(path.c_str(), 65));
}

Test(tests_SharedMemory, shmIdGen_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";

    cr_assert_neq(_SM.shmIdGen(_SM.keyGen(path, 65), 1024, IPC_CREAT), 0);
}

Test(tests_SharedMemory, shmIdGen_2)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";

    cr_assert_no_throw(_SM.shmIdGen(_SM.keyGen(path, 65), 1024, IPC_CREAT), SharedMemoryError, "shmctl() failed.");
}

Test(tests_SharedMemory, writeData_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";
    std::string command = "test";

    cr_assert_no_throw(_SM.writeData(_SM.keyGen(path, 65), 1024, IPC_CREAT, command), SharedMemoryError, "sprintf() failed.");
}

Test(tests_SharedMemory, writeData_2)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";
    std::string command = "test";

    cr_assert_no_throw(_SM.writeData(_SM.keyGen(path, 65), 1024, IPC_CREAT, command), SharedMemoryError, "shmdt() failed.");
}

Test(tests_SharedMemory, getDataById_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";
    int shmId = 0;

    shmId = _SM.shmIdGen(_SM.keyGen(path, 65), 1024, IPC_CREAT);
    cr_assert_no_throw(_SM.getDataById(shmId), SharedMemoryError, "shmdt() failed.");
    cr_assert_not_null(_SM.getDataById(shmId));
}

Test(tests_SharedMemory, getData_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";

    cr_assert_no_throw(_SM.getData(_SM.keyGen(path, 65), 1024, IPC_CREAT), SharedMemoryError, "shmdt() failed.");
    cr_assert_not_null(_SM.getData(_SM.keyGen(path, 65), 1024, IPC_CREAT));
}

Test(tests_SharedMemory, detachFrom_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";

    cr_expect_no_throw(_SM.detachFrom(_SM.getData(_SM.keyGen(path, 65), 1024, IPC_CREAT)), SharedMemoryError, "shmdt() failed.");
}

Test(tests_SharedMemory, destroy_1)
{
    SharedMemory _SM;
    std::string path = "log/kitchen1";
    int shmId = 0;

    shmId = _SM.shmIdGen(_SM.keyGen(path, 65), 1024, IPC_CREAT);
    cr_expect_no_throw(_SM.destroy(shmId, IPC_RMID), SharedMemoryError, "shmctl() failed.");
}