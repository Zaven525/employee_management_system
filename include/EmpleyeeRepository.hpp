#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Employee.hpp"

class EmployeeRepository
{
public:

private:
    std::vector<std::unique_ptr<Employee> > employees;
    
};