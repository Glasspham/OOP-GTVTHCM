# Các tệp được yêu cầu
_Employee.h_

```bash
#pragma once
#include <iostream>
#include<string.h>
using namespace std;

class Employee
{
public:
    Employee(const string&, const string&, const string&);

    void setFirstName(const string&); // set first name
    string getFirstName() const; // return first name

    void setLastName(const string&); // set last name
    string getLastName() const; // return last name

    void setSocialSecurityNumber(const string&); // set SSN
    string getSocialSecurityNumber() const; // return SSN

    // pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual

private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
}; // end class Employee
```

_SalariedEmployee.h_

```bash
#pragma once
#include "Employee.h"
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string&, const string&, double = 0.0);

    SalariedEmployee(const string& first, const string& last, const string& ssn, double salary = 0.0);

    void setWeeklySalary(double); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print SalariedEmployee object

private:
    double weeklySalary; // salary per week
}; // end class SalariedEmployee
```

_CommissionEmployee.h_

```bash
#pragma once
#include "Employee.h"
class CommissionEmployee : public Employee
{
public:
    //CommissionEmployee(const string&, const string&, double = 0.0, double = 0.0);
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);

    void setCommissionRate(double); // set commission rate
    double getCommissionRate() const; // return commission rate

    void setGrossSales(double); // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print CommissionEmployee object

private:
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
}; // end class CommissionEmployee
```

_BasePlusCommissionEmployee.h_

```bash
#pragma once
#include "CommissionEmployee.h"
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string&, const string&,
        const string&, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double); // set base salary
    double getBaseSalary() const; // return base salary

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print BasePlusCommissionEmployee object

private:
    double baseSalary; // base salary per week
}; // end class BasePlusCommissionEmployee
```

_Employee.cpp_

```bash
//logic code .........
```

_SalariedEmployee.cpp_

```bash
//logic code .........
```

_CommissionEmployee.cpp_

```bash
//logic code .........
```

_BasePlusCommissionEmployee.cpp_

```bash
//logic code .........
```