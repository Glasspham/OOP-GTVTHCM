#include"EmployeeManager.h"

void EmployeeManager::addEmployees()
{
    employees.push_back(new FullTimeEmployee("FT001", "John Doe", time(0) - 86400 * 365 * 3, "0123456789", 2000000, 3.0, 5));
    employees.push_back(new PartTimeEmployee("PT001", "Alice Smith", time(0) - 86400 * 365 * 2, "0234567890", 1800000, 35, 50000));
    employees.push_back(new FullTimeEmployee("FT002", "Bob Johnson", time(0) - 86400 * 365, "0345678901", 2500000, 2.5, 3));
    employees.push_back(new PartTimeEmployee("PT002", "Carol Williams", time(0) - 86400 * 365 * 4, "0456789012", 1600000, 20, 45000));
    employees.push_back(new FullTimeEmployee("FT003", "David Brown", time(0) - 86400 * 365 * 5, "0567890123", 2200000, 2.0, 8));
}

void EmployeeManager::displayEmployees()
{
    cout << left;
    cout << setw(10) << "ID"
         << setw(20) << "Full Name"
         << setw(15) << "Start Date"
         << setw(15) << "Phone Number"
         << setw(15) << "Base Salary"
         << setw(20) << "Calculated Salary"
         << endl;
    cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
    for (Employee *emp : employees)
    {
        time_t startDate = emp->getStartDate();
        struct tm *timeinfo = localtime(&startDate);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", timeinfo);
        cout << setw(10) << emp->getId()
             << setw(20) << emp->getFullName()
             << setw(15) << buffer
             << setw(15) << emp->getPhoneNumber()
             << fixed << setprecision(0) << setw(15) << emp->getBaseSalary()
             << fixed << setprecision(2) << setw(20) << emp->calculateSalary()
             << endl;
    }
    cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
}

void EmployeeManager::addEmployee(Employee *employee)
{
    bool isExist = false;
    for (Employee *emp : employees)
    {
        if (emp->getId() == employee->getId())
        {
            isExist = true;
            break;
        }
    }

    if (!isExist)
    {
        employees.push_back(employee);
    }
    else
    {
        cout << "Employee with ID " << employee->getId() << " already exists." << endl;
    }
}

float EmployeeManager::totalSalary()
{
    float total = 0;
    for (Employee *emp : employees)
        total += emp->calculateSalary();
    return total;
}

int EmployeeManager::countEmployeesInYear(int year)
{
    int count = 0;
    struct tm *timeinfo;
    for (const Employee *emp : employees)
    {
        time_t startDate = emp->getStartDate();
        timeinfo = localtime(&startDate);
        if (timeinfo->tm_year + 1900 == year)
            count++;
    }
    return count;
}

void EmployeeManager::updateHoursPerWeek(string id, float hoursPerWeek)
{
    for (Employee *emp : employees)
    {
        if (emp->getId() == id && dynamic_cast<PartTimeEmployee *>(emp) != nullptr)
        {
            PartTimeEmployee *ptEmp = dynamic_cast<PartTimeEmployee *>(emp);
            ptEmp->setHoursPerWeek(hoursPerWeek);
            cout << "Hours per week updated for employee " << id << endl;
            return;
        }
    }
    cout << "Part-time employee with ID " << id << " not found." << endl;
}

void EmployeeManager::sortByStartDate()
{
    sort(employees.begin(), employees.end(), [](Employee *a, Employee *b)
         { return a->getStartDate() > b->getStartDate(); });
}

EmployeeManager::~EmployeeManager()
{
    for (Employee *emp : employees)
    {
        delete emp;
    }
}
