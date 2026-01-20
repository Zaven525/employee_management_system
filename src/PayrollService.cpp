#include "PayrollService.hpp"
#include "ISalaried.hpp"

double PayrollService::calculateTotalPayroll(const std::vector<Employee*>& employees) const {
    double total = 0.0;
    for (auto e : employees) {
        if (auto salaried = dynamic_cast<ISalaried*>(e)) {
            total += salaried->calcSalary();
        }
    }
    return total;
}
