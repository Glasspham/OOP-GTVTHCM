#pragma once
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee
{
protected:
    float hoursPerWeek;
    float hourlyWage;

public:
    PartTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float hoursPerWeek, float hourlyWage);
    float calculateSalary() override;
    float getHoursPerWeek();
    void setHoursPerWeek(float hoursPerWeek);
    float getHourlyWage();
    void setHourlyWage(float hourlyWage);
};
#endif