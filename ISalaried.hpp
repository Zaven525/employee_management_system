#pragma once
#include <iostream>

class ISalaried 
{
public:
    virtual double calculateSalary() noexcept = 0; 
};