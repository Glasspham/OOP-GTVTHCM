#include "Employee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "SalariedEmployee.h"
#include <vector>
#include <iostream>
#include <iomanip>

void virtualViaPointer(const Employee* const baseClassPtr);
void virtualViaReference(const Employee& baseClassRef);

int main() {
    cout << fixed << setprecision(2);
    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

    cout << "Employees processed individually using static binding:\n\n";
    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    vector<Employee*> employees(3);
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    cout << "Employees processed polymorphically via dynamic binding:\n\n";
    for (size_t i = 0; i < employees.size(); i++) 
        virtualViaPointer(employees[i]);

    cout << "Virtual function calls made off base-class reference:\n\n";
    for (size_t i = 0; i < employees.size(); i++) 
        virtualViaReference(*employees[i]);
    
    return 0;
}

void virtualViaPointer(const Employee* const baseClassPtr) {
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
} // end function virtualViaPointer 

void virtualViaReference(const Employee& baseClassRef) {
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
} // end function virtualViaReference