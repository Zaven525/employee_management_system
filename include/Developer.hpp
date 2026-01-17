#pragma once
#include <iostream>
#include "Employee.hpp"
#include "ISalaried.hpp"

class Developer : public Employee, public ISalaried
{
public:
    Developer(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
    virtual double calcSalary() const noexcept { return 1500.0; }
};