#pragma once
#include "Employee.h"
class CommissionEmployee : public Employee
{
public:
    //CommissionEmployee(const string&, const string&, double = 0.0, double = 0.0);
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);

    void setCommissionRate(double); // set commission rate
    double getCommissionRate() const; // return commission rate

    void setGrossSales(double); // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print CommissionEmployee object

private:
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
}; // end class CommissionEmployee