#pragma once
#include "President.hpp"

void President::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Role: President" << std::endl;
}