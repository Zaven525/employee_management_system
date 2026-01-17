#pragma once
#include <iostream>

inline static size_t ID = 0;

class Employee 
{
protected:
    Employee(std::string name) :_ID{ID++}, _name{name} {}
    virtual ~Employee() = default;
public:
    size_t getID() const noexcept { return _ID; }
    virtual void printInfo() const noexcept = 0;
protected:
    size_t _ID;
    std::string _name;
};

