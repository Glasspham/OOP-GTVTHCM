#include"PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float hoursPerWeek, float hourlyWage)
    : Employee(id, fullName, startDate, phoneNumber, baseSalary), hoursPerWeek(hoursPerWeek), hourlyWage(hourlyWage) {}

float PartTimeEmployee::calculateSalary()
{
    float regularSalary = 0.3 * baseSalary;
    float overtimeSalary = 0;

    if (hoursPerWeek > 40)
    {
        overtimeSalary = (hoursPerWeek - 40) * hourlyWage * 1.5;
        hoursPerWeek = 40;
    }

    float totalSalary = regularSalary + (hoursPerWeek * hourlyWage) + overtimeSalary;
    return totalSalary;
}

float PartTimeEmployee::getHoursPerWeek() { return hoursPerWeek; }
void PartTimeEmployee::setHoursPerWeek(float hoursPerWeek) { this->hoursPerWeek = hoursPerWeek; }

float PartTimeEmployee::getHourlyWage() { return hourlyWage; }
void PartTimeEmployee::setHourlyWage(float hourlyWage) { this->hourlyWage = hourlyWage; }
