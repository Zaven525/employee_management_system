#pragma once
#include <iostream>

inline static size_t ID = 0;

class Employee 
{
public:
    virtual void printInfo() const noexcept = 0;
protected:
    Employee(std::string name) :_ID{ID++}, _name{name} {}
protected:
    size_t _ID;
    std::string _name;
};

