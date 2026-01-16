#pragma once
#include <iostream>
#include "Employee.hpp"

class Developer : public Employee
{
public:
    Developer(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
};