
#include "Manager.hpp"

void Manager::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Salary: " << calcSalary() << std::endl
    << "Role: Manager" << std::endl;
}