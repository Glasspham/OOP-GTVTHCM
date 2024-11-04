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