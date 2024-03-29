/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Error class methods
*/

#include "PlazzaError.hpp"

PlazzaError::PlazzaError(std::string const &message,
                                     std::string const &component) :
    _message("\033[1;31m" + component + ": " + message + "\033[0m")
{
}

const char *PlazzaError::what() const noexcept
{
    return (_message.data());
}

FileError::FileError(std::string const &message) : 
    PlazzaError::PlazzaError(message, "FileError")
{
}

InputError::InputError(std::string const &message) : 
    PlazzaError::PlazzaError(message, "InputError")
{
}

ParserError::ParserError(std::string const &message) : 
    PlazzaError::PlazzaError(message, "ParserError")
{
}

SharedMemoryError::SharedMemoryError(std::string const &message) : 
    PlazzaError::PlazzaError(message, "SharedMemoryError")
{
}

ThreadError::ThreadError(std::string const &message) :
    PlazzaError::PlazzaError(message, "ThreadError")
{
}