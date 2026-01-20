#pragma once
#include <iostream>
#include "Employee.hpp"
#include "ISalaried.hpp"

class SalesPerson : public Employee, public ISalaried
{
public:
    SalesPerson(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
    virtual double calcSalary() const noexcept { return 8000; }
};