#pragma once
#include <iostream>
#include "Employee.hpp"
#include "ISalaried.hpp"

class Manager : public Employee, public ISalaried
{
public:
    Manager(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
    virtual double calcSalary() const noexcept { return 3000; }
};