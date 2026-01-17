#pragma once
#include "EmpleyeeRepository.hpp"

void EmployeeRepository::removeEmployee(size_t ID) noexcept
{
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if ((*it)->getID() == ID)
        {
            employees.erase(it);
            return;
        }
    }
}

void EmployeeRepository::printAllEmployees() const noexcept
{
    for (const auto& emp : employees)
    {
        emp->printInfo();
        std::cout << "------------------------" << std::endl;
    }
}