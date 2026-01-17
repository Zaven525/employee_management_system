#pragma once
#include <iostream>

class ISalaried 
{
public:
    virtual double calcSalary() const noexcept = 0; 
    virtual ~ISalaried() = default;
};