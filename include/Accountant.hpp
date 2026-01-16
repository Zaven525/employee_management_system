#pragma once
#include <iostream>
#include "Employee.hpp"
#include "ISalaried.hpp"

class Accountant : public Employee, public ISalaried 
{
public:
    Accountant(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
    virtual double calcSalary() const noexcept;
};
