
---

# Payroll System Project

## Description

This is a C++ project for managing employees and calculating payroll.
The project demonstrates:

* **Inheritance and polymorphism** (`Employee`, `ISalaried`)
* Managing employees via `EmployeeRepository`
* Calculating total payroll using `PayrollService`
* Stress-testing with hundreds of employees
* Proper project structure with `include` and `src` folders

---

## Project Structure

```
project/
│
├─ include/
│   ├─ Employee.hpp
│   ├─ Developer.hpp
│   ├─ SalesPerson.hpp
│   ├─ Accountant.hpp
│   ├─ Manager.hpp
│   ├─ President.hpp
│   ├─ ISalaried.hpp
│   ├─ EmployeeRepository.hpp
│   └─ PayrollService.hpp
│
├─ src/
│   ├─ Employee.cpp
│   ├─ Developer.cpp
│   ├─ SalesPerson.cpp
│   ├─ Accountant.cpp
│   ├─ Manager.cpp
│   ├─ President.cpp
│   ├─ EmployeeRepository.cpp
│   ├─ PayrollService.cpp
│   └─ main.cpp
│
└─ Makefile
```

---

## Build and Run

### Linux / Windows (g++)

```bash
# Compile
g++ -std=c++20 -Iinclude src/*.cpp -o app

# Run
./app   # Linux
app.exe # Windows
```

---

## Features

* Add employees of different types: `Developer`, `SalesPerson`, `Accountant`, `Manager`, `President`
* Calculate total payroll using `PayrollService`
* Retrieve individual salaries via `calcSalary()`
* Stress test payroll calculations with hundreds of employees
* Supports adding/removing employees dynamically

---

## Notes

* Salaries are **calculated only** via `calcSalary()`; there is no stored salary value.
* Unpaid roles or ISP requirements are **not implemented** in this version.
* Designed for learning **OOP, polymorphism, and memory management** in C++

---

