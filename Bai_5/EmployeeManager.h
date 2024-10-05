#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

class EmployeeManager
{
private:
    vector<Employee *> employees;

public:
    void addEmployees();
    void displayEmployees();
    void addEmployee(Employee *employee);
    float totalSalary();
    int countEmployeesInYear(int year);
    void updateHoursPerWeek(string id, float hoursPerWeek);
    void sortByStartDate();
    ~EmployeeManager();
};