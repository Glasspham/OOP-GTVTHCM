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