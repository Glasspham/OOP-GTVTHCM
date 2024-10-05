#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "EmployeeManager.h"

void menu()
{
    cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
    cout << "Menu:" << endl;
    cout << "1. Display all employees" << endl;
    cout << "2. Add a new employee" << endl;
    cout << "3. Calculate total salary" << endl;
    cout << "4. Count employees joined in a specific year" << endl;
    cout << "5. Update hours per week for a part-time employee" << endl;
    cout << "6. Sort employees by start date" << endl;
    cout << "0. Exit" << endl;
    cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
    cout << "Enter your choice: ";
}

int main()
{
    EmployeeManager manager;
    manager.addEmployees();
    int choice;
    do
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            manager.displayEmployees();
            break;
        case 2:
        {
            string id, fullName, phoneNumber;
            float baseSalary, hoursPerWeek, salaryCoefficient;
            int yearsExperience;
            char type;
            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter employee Full Name: ";
            cin.ignore();
            getline(cin, fullName);
            cout << "Enter employee Phone Number: ";
            cin >> phoneNumber;
            cout << "Enter employee Base Salary: ";
            cin >> baseSalary;
            cout << "Enter employee type (F: Full-time, P: Part-time): ";
            cin >> type;
            if (type == 'F' || type == 'f')
            {
                cout << "Enter salary coefficient: ";
                cin >> salaryCoefficient;
                cout << "Enter years of experience: ";
                cin >> yearsExperience;
                manager.addEmployee(new FullTimeEmployee(id, fullName, time(0), phoneNumber, baseSalary, salaryCoefficient, yearsExperience));
            }
            else if (type == 'P' || type == 'p')
            {
                cout << "Enter hours per week: ";
                cin >> hoursPerWeek;
                cout << "Enter hourly wage: ";
                cin >> baseSalary;
                manager.addEmployee(new PartTimeEmployee(id, fullName, time(0), phoneNumber, baseSalary, hoursPerWeek, baseSalary));
            }
            else cout << "Invalid employee type." << endl;
            break;
        }
        case 3:
            cout << "Total salary: " << manager.totalSalary() << endl;
            break;
        case 4:
        {
            int year;
            cout << "Enter the year: ";
            cin >> year;
            cout << "Number of employees joined in " << year << ": " << manager.countEmployeesInYear(year) << endl;
            break;
        }
        case 5:
        {
            string id;
            float hoursPerWeek;
            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter new hours per week: ";
            cin >> hoursPerWeek;
            manager.updateHoursPerWeek(id, hoursPerWeek);
            break;
        }
        case 6:
            manager.sortByStartDate();
            cout << "Employees sorted by start date." << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}