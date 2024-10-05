#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float salaryCoefficient, int yearsExperience)
    : Employee(id, fullName, startDate, phoneNumber, baseSalary), salaryCoefficient(salaryCoefficient), yearsExperience(yearsExperience)
{
    if (salaryCoefficient < 1.65 || salaryCoefficient > 8.00)
        this->salaryCoefficient = 1.65;
    if (yearsExperience < 0)
        this->yearsExperience = 0;
}

float FullTimeEmployee::calculateSalary() {
    float salary = baseSalary * salaryCoefficient + (yearsExperience * 0.05 * (baseSalary * salaryCoefficient));
    return salary;
}

float FullTimeEmployee::getSalaryCoefficient() { return salaryCoefficient; }
void FullTimeEmployee::setSalaryCoefficient(float salaryCoefficient) { this->salaryCoefficient = salaryCoefficient; }

int FullTimeEmployee::getYearsExperience() { return yearsExperience; }
void FullTimeEmployee::setYearsExperience(int yearsExperience) { this->yearsExperience = yearsExperience; }
