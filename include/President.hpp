#pragma once
#include <iostream>
#include "Employee.hpp"

class President : public Employee
{
public:
    President(std::string name) : Employee{name} {}
public:
    virtual void printInfo() const noexcept;
};