#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "Employee.hpp"
#include "ISalaried.hpp"
#include "PayrollService.hpp"

#include "Developer.hpp"
#include "SalesPerson.hpp"
#include "Accountant.hpp"
#include "Manager.hpp"
#include "President.hpp"

int main() {

    std::cout << "=== MASSIVE PAYROLL STRESS TEST ===\n\n";

    std::vector<std::unique_ptr<Employee>> storage;
    PayrollService payroll;

    // ---------------------------
    // 1. Создаём первые 20 сотрудников
    // ---------------------------
    for(int i = 1; i <= 5; ++i) storage.push_back(std::make_unique<Developer>("Dev" + std::to_string(i)));
    for(int i = 1; i <= 5; ++i) storage.push_back(std::make_unique<SalesPerson>("Sales" + std::to_string(i)));
    for(int i = 1; i <= 5; ++i) storage.push_back(std::make_unique<Accountant>("Acc" + std::to_string(i)));
    for(int i = 1; i <= 3; ++i) storage.push_back(std::make_unique<Manager>("Mgr" + std::to_string(i)));
    for(int i = 1; i <= 2; ++i) storage.push_back(std::make_unique<President>("Pres" + std::to_string(i)));

    std::vector<Employee*> employees;
    for(auto &e : storage) employees.push_back(e.get());

    double total = payroll.calculateTotalPayroll(employees);
    std::cout << "Initial payroll (20 employees): " << total << "\n\n";

    // ---------------------------
    // 2. Повторные расчёты, stress
    // ---------------------------
    for(int round=1; round <= 10; ++round){
        double t = payroll.calculateTotalPayroll(employees);
        std::cout << "Recalculation " << round << ": " << t << "\n";
    }

    // ---------------------------
    // 3. Добавляем ещё 30 сотрудников
    // ---------------------------
    for(int i = 6; i <= 15; ++i) storage.push_back(std::make_unique<Developer>("Dev" + std::to_string(i)));
    for(int i = 6; i <= 15; ++i) storage.push_back(std::make_unique<SalesPerson>("Sales" + std::to_string(i)));
    for(int i = 6; i <= 15; ++i) storage.push_back(std::make_unique<Accountant>("Acc" + std::to_string(i)));

    employees.clear();
    for(auto &e : storage) employees.push_back(e.get());

    double total2 = payroll.calculateTotalPayroll(employees);
    std::cout << "\nPayroll after adding 30 more: " << total2 << "\n\n";

    // ---------------------------
    // 4. Частичная проверка зарплат
    // ---------------------------
    std::cout << "--- First 20 individual salaries ---\n";
    for(size_t i=0;i<20 && i<employees.size(); ++i){
        if(auto s = dynamic_cast<ISalaried*>(employees[i])) std::cout << s->calcSalary() << " ";
        else std::cout << "[no salary] ";
    }
    std::cout << "\n\n";

    // ---------------------------
    // 5. Добавляем ещё 50 сотрудников
    // ---------------------------
    for(int i = 16; i <= 40; ++i) storage.push_back(std::make_unique<Developer>("Dev" + std::to_string(i)));
    for(int i = 16; i <= 40; ++i) storage.push_back(std::make_unique<SalesPerson>("Sales" + std::to_string(i)));
    for(int i = 16; i <= 40; ++i) storage.push_back(std::make_unique<Accountant>("Acc" + std::to_string(i)));
    for(int i = 4; i <= 10; ++i) storage.push_back(std::make_unique<Manager>("Mgr" + std::to_string(i)));
    for(int i = 3; i <= 5; ++i) storage.push_back(std::make_unique<President>("Pres" + std::to_string(i)));

    employees.clear();
    for(auto &e : storage) employees.push_back(e.get());

    double total3 = payroll.calculateTotalPayroll(employees);
    std::cout << "Payroll after adding 50 more: " << total3 << "\n\n";

    // ---------------------------
    // 6. Многократные стресс-расчёты
    // ---------------------------
    for(int round=11; round<=30; ++round){
        double t = payroll.calculateTotalPayroll(employees);
        std::cout << "Stress calc " << round << ": " << t << "\n";
    }

    // ---------------------------
    // 7. Проверка индивидуальных зарплат первых 50 сотрудников
    // ---------------------------
    std::cout << "\n--- First 50 salaries check ---\n";
    for(size_t i=0;i<50 && i<employees.size(); ++i){
        if(auto s = dynamic_cast<ISalaried*>(employees[i])) std::cout << s->calcSalary() << " ";
        else std::cout << "[no salary] ";
    }
    std::cout << "\n\n";

    // ---------------------------
    // 8. Добавление ещё 100 сотрудников
    // ---------------------------
    for(int i=41;i<=90;++i) storage.push_back(std::make_unique<Developer>("Dev"+std::to_string(i)));
    for(int i=41;i<=90;++i) storage.push_back(std::make_unique<SalesPerson>("Sales"+std::to_string(i)));
    for(int i=41;i<=90;++i) storage.push_back(std::make_unique<Accountant>("Acc"+std::to_string(i)));
    for(int i=11;i<=20;++i) storage.push_back(std::make_unique<Manager>("Mgr"+std::to_string(i)));
    for(int i=6;i<=10;++i) storage.push_back(std::make_unique<President>("Pres"+std::to_string(i)));

    employees.clear();
    for(auto &e : storage) employees.push_back(e.get());

    double total4 = payroll.calculateTotalPayroll(employees);
    std::cout << "Payroll after adding 100 more: " << total4 << "\n\n";

    // ---------------------------
    // 9. Выводим зарплаты случайных 50 сотрудников
    // ---------------------------
    std::cout << "--- Random 50 salaries ---\n";
    for(size_t i=10;i<60 && i<employees.size(); ++i){
        if(auto s = dynamic_cast<ISalaried*>(employees[i])) std::cout << s->calcSalary() << " ";
        else std::cout << "[no salary] ";
    }
    std::cout << "\n\n";

    // ---------------------------
    // 10. Финальный стресс-тест: 50 повторных расчётов
    // ---------------------------
    for(int round=31;round<=80;++round){
        double t = payroll.calculateTotalPayroll(employees);
        if(round%5==0) std::cout << "Final stress calc " << round << ": " << t << "\n";
    }

    std::cout << "\n=== MASSIVE PAYROLL TEST COMPLETE ===\n";
    return 0;
}
