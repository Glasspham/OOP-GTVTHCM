#pragma once
#ifndef DIEMHOCVIEN_H
#define DIEMHOCVIEN_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;

class Employee
{
protected:
    string id, fullName, phoneNumber;
    time_t startDate;
    float baseSalary;

public:
    Employee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary);

    virtual float calculateSalary() = 0;

    string getId() const;
    void setId(string id);

    string getFullName() const;
    void setFullName(string fullName);

    const time_t& getStartDate() const;
    void setStartDate(time_t startDate);

    string getPhoneNumber() const;
    void setPhoneNumber(string phoneNumber);

    float getBaseSalary() const;
    void setBaseSalary(float baseSalary);
};
#endif