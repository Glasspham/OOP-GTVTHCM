#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

class Employee {
public:
    Employee(const std::string& first, const std::string& last)
        : firstName(first), lastName(last) {}

    virtual double earnings() const = 0;

    virtual void print() const {
        std::cout << firstName << " " << lastName << ": ";
    }

protected:
    std::string firstName;
    std::string lastName;
};

class SEmployee : public Employee {
public:
    SEmployee(const std::string& first, const std::string& last, double salary)
        : Employee(first, last), weeklySalary(salary) {}

    virtual double earnings() const override {
        return weeklySalary;
    }

    virtual void print() const override {
        Employee::print();
        std::cout << "Salaried Employee, Weekly Salary: $" << earnings() << std::endl;
    }

private:
    double weeklySalary;
};

class CEmployee : public Employee {
public:
    CEmployee(const std::string& first, const std::string& last, double sales, double rate)
        : Employee(first, last), grossSales(sales), commissionRate(rate) {}

    double getGrossSales() const { return grossSales; }
    double getCommissionRate() const { return commissionRate; }

    virtual double earnings() const override {
        return grossSales * commissionRate;
    }

    virtual void print() const override {
        Employee::print();
        std::cout << "Commission Employee, Gross Sales: $" << grossSales << ", Commission Rate: " << commissionRate
                  << ", Earnings: $" << earnings() << std::endl;
    }

private:
    double grossSales;
    double commissionRate;
};

class SCEmployee : public CEmployee {
public:
    SCEmployee(const std::string& first, const std::string& last, double salary, double sales, double rate)
        : CEmployee(first, last, sales, rate), baseSalary(salary) {}

    virtual double earnings() const override {
        return baseSalary + CEmployee::earnings();
    }

    virtual void print() const override {
        Employee::print();
        std::cout << "Base-salary-plus-commission Employee, Base Salary: $" << baseSalary
                  << ", Gross Sales: $" << getGrossSales() << ", Commission Rate: " << getCommissionRate()
                  << ", Earnings: $" << earnings() << std::endl;
    }

private:
    double baseSalary;
};

std::string random_string(size_t length) {
    static const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);

    std::string result;
    result.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        result += characters[dis(gen)];
    }
    return result;
}

int main() {
    std::vector<Employee*> allEmployees;

    for (int i = 0; i < 10; ++i) {
        std::string first = random_string(2);
        std::string last = random_string(2);
        double salary = (rand() % 1000) + 500;
        double sales = (rand() % 10000) + 5000;
        double rate = (rand() % 10) / 10.0;

        allEmployees.push_back(new SEmployee(first, last, salary));
        allEmployees.push_back(new CEmployee(first, last, sales, rate));
        allEmployees.push_back(new SCEmployee(first, last, salary, sales, rate));
    }

    std::cout << "Original lists:" << std::endl;
    for (const auto& employee : allEmployees) {
        employee->print();
    }

    std::sort(allEmployees.begin(), allEmployees.end(),
              [](const Employee* a, const Employee* b) { return a->earnings() > b->earnings(); });

    std::cout << "\nSorted list by earnings (descending order):" << std::endl;
    for (const auto& employee : allEmployees) {
        employee->print();
    }

    // Deallocate memory
    for (auto& employee : allEmployees) {
        delete employee;
    }

    return 0;
}
