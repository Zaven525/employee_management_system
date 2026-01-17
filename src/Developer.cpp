#pragma once
#include "Developer.hpp"

void Developer::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Salary: " << calcSalary() << std::endl
    << "Role: Developer" << std::endl;

}