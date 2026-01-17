#pragma once
#include "Accountant.hpp"

void Accountant::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Salary: " << calcSalary() << std::endl
    << "Role: Accountant" << std::endl;

}