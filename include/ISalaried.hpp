#pragma once
#include <iostream>

class ISalaried 
{
public:
    virtual double calcSalary() noexcept = 0; 
};