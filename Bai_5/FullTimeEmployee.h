#pragma once
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee : public Employee
{
protected:
    float salaryCoefficient;
    int yearsExperience;

public:
    FullTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float salaryCoefficient, int yearsExperience);
    float calculateSalary() override;
    float getSalaryCoefficient();
    void setSalaryCoefficient(float salaryCoefficient);
    int getYearsExperience();
    void setYearsExperience(int yearsExperience);
};
#endif