#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Employee.hpp"

class EmployeeRepository
{
public:
    EmployeeRepository() = default;
    ~EmployeeRepository() = default;
public:
    void addEmployee(std::unique_ptr<Employee> emp) noexcept { employees.push_back(std::move(emp)); }
    void removeEmployee(size_t ID) noexcept;
    void printAllEmployees() const noexcept;
private:
    std::vector<std::unique_ptr<Employee> > employees;
};