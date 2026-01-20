#pragma once
#include <vector>
#include "Employee.hpp"

class PayrollService {
public:
    double calculateTotalPayroll(const std::vector<Employee*>& employees) const;
};
