#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

class Employee {
protected:
    string id;
    string fullName;
    time_t startDate;
    string phoneNumber;
    float baseSalary;
public:
    Employee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary)
        : id(id), fullName(fullName), phoneNumber(phoneNumber), baseSalary(baseSalary){
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

    virtual float calculateSalary() = 0;
    // Getters and Setters
    string getId() { return id; }
    void setId(string id) { this->id = id; }

    string getFullName() { return fullName; }
    void setFullName(string fullName) { this->fullName = fullName; }

    time_t getStartDate() { return startDate; }
    void setStartDate(time_t startDate) { this->startDate = startDate; }

    string getPhoneNumber() { return phoneNumber; }
    void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }

    float getBaseSalary() { return baseSalary; }
    void setBaseSalary(float baseSalary) { this->baseSalary = baseSalary; }
};

class FullTimeEmployee : public Employee {
protected:
    float salaryCoefficient;
    int yearsExperience;
public:
    FullTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float salaryCoefficient, int yearsExperience)
        : Employee(id, fullName, startDate, phoneNumber, baseSalary), salaryCoefficient(salaryCoefficient), yearsExperience(yearsExperience) {
        if (salaryCoefficient < 1.65 || salaryCoefficient > 8.00) 
            this->salaryCoefficient = 1.65; // Assigning default value if out of range

        if (yearsExperience < 0) 
            this->yearsExperience = 0;
    }

    float calculateSalary() override {
        float salary = baseSalary * salaryCoefficient + (yearsExperience * 0.05 * (baseSalary * salaryCoefficient));
        return salary;
    }

    // Getters and Setters
    float getSalaryCoefficient() { return salaryCoefficient; }
    void setSalaryCoefficient(float salaryCoefficient) { this->salaryCoefficient = salaryCoefficient; }

    int getYearsExperience() { return yearsExperience; }
    void setYearsExperience(int yearsExperience) { this->yearsExperience = yearsExperience; }
};

class PartTimeEmployee : public Employee {
protected:
    float hoursPerWeek;
    float hourlyWage;
public:
    PartTimeEmployee(string id, string fullName, time_t startDate, string phoneNumber, float baseSalary, float hoursPerWeek, float hourlyWage)
: Employee(id, fullName, startDate, phoneNumber, baseSalary), hoursPerWeek(hoursPerWeek), hourlyWage(hourlyWage) {}

    float calculateSalary() override {
        float regularSalary = 0.3 * baseSalary;
        float overtimeSalary = 0;

        if (hoursPerWeek > 40) {
            overtimeSalary = (hoursPerWeek - 40) * hourlyWage * 1.5;
            hoursPerWeek = 40; // Cap hoursPerWeek to 40 for regular salary calculation
        }

        float totalSalary = regularSalary + (hoursPerWeek * hourlyWage) + overtimeSalary;
        return totalSalary;
    }

    // Getters and Setters
    float getHoursPerWeek() { return hoursPerWeek; }
    void setHoursPerWeek(float hoursPerWeek) { this->hoursPerWeek = hoursPerWeek; }

    float getHourlyWage() { return hourlyWage; }
    void setHourlyWage(float hourlyWage) { this->hourlyWage = hourlyWage; }
};

class EmployeeManager {
private:
    vector<Employee*> employees;
public:
    void addEmployees() {
        // Adding 5 sample employees
        employees.push_back(new FullTimeEmployee("FT001", "John Doe", time(0) - 86400 * 365 * 3, "0123456789", 2000000, 3.0, 5));
        employees.push_back(new PartTimeEmployee("PT001", "Alice Smith", time(0) - 86400 * 365 * 2, "0234567890", 1800000, 35, 50000));
        employees.push_back(new FullTimeEmployee("FT002", "Bob Johnson", time(0) - 86400 * 365, "0345678901", 2500000, 2.5, 3));
        employees.push_back(new PartTimeEmployee("PT002", "Carol Williams", time(0) - 86400 * 365 * 4, "0456789012", 1600000, 20, 45000));
        employees.push_back(new FullTimeEmployee("FT003", "David Brown", time(0) - 86400 * 365 * 5, "0567890123", 2200000, 2.0, 8));
    }

    void displayEmployees() {
        cout << setw(10) << "ID" << setw(20) << "Full Name" << setw(20) << "Start Date" << setw(15) << "Phone Number" << setw(15) << "Base Salary" << setw(15) << "Calculated Salary" << endl;
        cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
        for (Employee* emp : employees) {
            cout << setw(10) << emp->getId() << setw(20) << emp->getFullName() << setw(20) << ctime(&emp->getStartDate()) << setw(15) << emp->getPhoneNumber() << setw(15) << emp->getBaseSalary() << setw(15) << emp->calculateSalary() << endl;
        }
    }

    void addEmployee(Employee* employee) {
        bool isExist = false;
        for (Employee* emp : employees) {
            if (emp->getId() == employee->getId()) {
                isExist = true;
                break;
            }
        }

        if (!isExist) {
            employees.push_back(employee);
        }
        else {
            cout << "Employee with ID " << employee->getId() << " already exists." << endl;
        }
    }

    float totalSalary() {
        float total = 0;
        for (Employee* emp : employees) 
            total += emp->calculateSalary();
        return total;
    }

    int countEmployeesInYear(int year) {
        int count = 0;
        struct tm* timeinfo;
for (const Employee* emp : employees) { // Sửa từ 'Employee*' thành 'const Employee*'
            timeinfo = localtime(&emp->getStartDate());
            if (timeinfo->tm_year + 1900 == year) {
                count++;
            }
        }
        return count;
    }

    void updateHoursPerWeek(string id, float hoursPerWeek) {
        for (Employee* emp : employees) {
            if (emp->getId() == id && dynamic_cast<PartTimeEmployee*>(emp) != nullptr) {
                PartTimeEmployee* ptEmp = dynamic_cast<PartTimeEmployee*>(emp);
                ptEmp->setHoursPerWeek(hoursPerWeek);
                cout << "Hours per week updated for employee " << id << endl;
                return;
            }
        }
        cout << "Part-time employee with ID " << id << " not found." << endl;
    }

    void sortByStartDate() {
        sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
            return a->getStartDate() > b->getStartDate();
            });
    }

    ~EmployeeManager() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }
};

int main() {
    EmployeeManager manager;
    manager.addEmployees();

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display all employees" << endl;
        cout << "2. Add a new employee" << endl;
        cout << "3. Calculate total salary" << endl;
        cout << "4. Count employees joined in a specific year" << endl;
        cout << "5. Update hours per week for a part-time employee" << endl;
        cout << "6. Sort employees by start date" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.displayEmployees();
            break;
        case 2: {
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
            cout << "Enter employee type (F for Full-time, P for Part-time): ";
            cin >> type;

            if (type == 'F' || type == 'f') {
                cout << "Enter salary coefficient: ";
                cin >> salaryCoefficient;
                cout << "Enter years of experience: ";
                cin >> yearsExperience;
                manager.addEmployee(new FullTimeEmployee(id, fullName, time(0), phoneNumber, baseSalary, salaryCoefficient, yearsExperience));
            }
            else if (type == 'P' || type == 'p') {
                cout << "Enter hours per week: ";
                cin >> hoursPerWeek;
cout << "Enter hourly wage: ";
                cin >> baseSalary; // Reusing baseSalary for hourly wage
                manager.addEmployee(new PartTimeEmployee(id, fullName, time(0), phoneNumber, baseSalary, hoursPerWeek, baseSalary));
            }
            else {
                cout << "Invalid employee type." << endl;
            }
            break;
        }
        case 3:
            cout << "Total salary: " << manager.totalSalary() << endl;
            break;
        case 4: {
            int year;
            cout << "Enter the year: ";
            cin >> year;
            cout << "Number of employees joined in " << year << ": " << manager.countEmployeesInYear(year) << endl;
            break;
        }
        case 5: {
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