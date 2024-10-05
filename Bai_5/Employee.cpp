#include"Employee.h"

Employee::Employee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary)
    : id(id), fullName(fullName), phoneNumber(phoneNumber), baseSalary(baseSalary)
{
    if (startDate > time(0))
        this->startDate = time(0);
    else
        this->startDate = startDate;
    if (phoneNumber.length() != 10 || phoneNumber[0] != '0')
        this->phoneNumber = "Invalid";
    else
        this->phoneNumber = phoneNumber;
    if (baseSalary < 0)
        this->baseSalary = 0;
}

string Employee::getId() const { return id; }
void Employee::setId(string id) { this->id = id; }

string Employee::getFullName() const { return fullName; }
void Employee::setFullName(string fullName) { this->fullName = fullName; }

const time_t& Employee::getStartDate() const { return startDate; }
void Employee::setStartDate(time_t startDate) { this->startDate = startDate; }

string Employee::getPhoneNumber() const { return phoneNumber; }
void Employee::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }

float Employee::getBaseSalary() const { return baseSalary; }
void Employee::setBaseSalary(float baseSalary) { this->baseSalary = baseSalary; }
