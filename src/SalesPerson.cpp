
#include "SalesPerson.hpp"

void SalesPerson::printInfo() const noexcept
{
    std::cout 
    << "ID: " << _ID << std::endl
    << "Name: " << _name << std::endl
    << "Salary: " << calcSalary() << std::endl
    << "Role: SalesPerson" << std::endl;
}