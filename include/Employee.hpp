#pragma once
#include <iostream>

inline static size_t ID = 0;

class Employee 
{
protected:
    Employee(std::string name) :_ID{ID++}, _name{name} {}
public:
    virtual void printInfo() const noexcept = 0;
protected:
    size_t _ID;
    std::string _name;
};

