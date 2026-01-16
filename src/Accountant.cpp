#pragma once
#include "Accountant.hpp"

void Accountant::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Salary: " << calculateSalary() << std::endl;
}

double Accountant::calculateSalary() const noexcept
{
    
}