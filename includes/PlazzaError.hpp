/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Error class
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>


class PlazzaError : public std::exception
{
    public:
        PlazzaError(std::string const &message,
                        std::string const &component = "Unknown");

        const char *what() const noexcept override;

    private:
        std::string _message;
};

class FileError : public PlazzaError
{
    public:
        FileError(std::string const &message);
};

class InputError : public PlazzaError
{
    public:
        InputError(std::string const &message);
};

class ParserError : public PlazzaError
{
    public:
        ParserError(std::string const &message);
};

class SharedMemoryError : public PlazzaError
{
    public:
        SharedMemoryError(std::string const &message);
};

class ThreadError : public PlazzaError
{
    public:
        ThreadError(std::string const &message);
};

#endif /* !ERROR_HPP_ */