#pragma once
#include "employee.h"
#include <vector>
#include <string>

class Company
{
private:
    vector<Employee*> employees;
    string companyName;
    int numberOfEmployees;
    float revenue;
    string location;

public:
    // Constructor
    Company();
    Company(string name, int numEmployees, float rev, string loc);
    Company(const Company& comp);

    Company& operator=(const Company& comp);


    // Getter methods
    string getCompanyName() const;
    int getNumberOfEmployees() const;
    float getRevenue() const;
    string getLocation() const;

    // Setter methods
    void setCompanyName(string name);
    void setNumberOfEmployees(int num);
    void setRevenue(float rev);
    void setLocation(string loc);

    // Method to add an employee
    void addEmployee(Employee* emp);

    // Method to print company information
    void printCompanyInfo() const;

    // Method to print all employees
    friend ostream& operator<<(ostream& cout, const Company& comp) {
        cout << "Company Information:" << endl;
        cout << "Company Name: " << comp.companyName << endl;
        cout << "Number of Employees: " << comp.numberOfEmployees << endl;
        cout << "Revenue: $" << comp.revenue << endl;
        cout << "location: " << comp.location << endl;

        if (!comp.employees.empty()) {
            cout << "Employee Details:";
            for (size_t i = 0; i < comp.employees.size(); i++) {
                comp.employees[i]->displayEmployeeInfo();

            }
        }
        else {
            cout << " No employees in the company yet " << endl;
        }
        return cout;
    }
    friend istream& operator>>(istream& cin, Company& comp) {

        cin >> comp.companyName;
        cin >> comp.numberOfEmployees;
        cin >> comp.revenue;
        cin >> comp.location;

        if (!comp.employees.empty()) {
            cout << "Employee Details:";
            for (size_t i = 0; i < comp.employees.size(); i++) {
                comp.employees[i]->displayEmployeeInfo();

            }
        }
        else {
            cout << " No employees in the company yet " << endl;
        }
        

        return cin;
    }
    ~Company();


};



Company::Company() {

    companyName = "";
    numberOfEmployees = 0;
    revenue = 0.0f;
    location = "";
}

Company::Company(string name, int numEmployees, float rev, string loc) {

    this->companyName = name;
    this->numberOfEmployees = numEmployees;
    this->revenue = rev;
    this->location = loc;

}

Company::Company(const Company& comp) {

    this->companyName = comp.companyName;
    this->numberOfEmployees = comp.numberOfEmployees;
    this->revenue = comp.revenue;
    this->location = comp.location;

}

Company& Company::operator=(const Company& comp) {

    this->companyName = comp.companyName;
    this->numberOfEmployees = comp.numberOfEmployees;
    this->revenue = comp.revenue;
    this->location = comp.location;

    return *this;
}




string Company::getCompanyName() const {
    return companyName;
}
int Company::getNumberOfEmployees() const {
    return numberOfEmployees;
}
float Company::getRevenue() const {
    return revenue;
}
string Company::getLocation() const {
    return location;
}






void Company::setCompanyName(string name) {
    companyName = name;
}
void Company::setNumberOfEmployees(int num) {
    numberOfEmployees = num;
}
void Company::setRevenue(float rev) {
    revenue = rev;
}
void Company::setLocation(string loc) {
    location = loc;
}





void Company::printCompanyInfo() const {
    cout << "Company Information:" << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Number of Employees: " << numberOfEmployees << endl;
    cout << "Revenue: $" << revenue << endl;
    cout << "location: " << location << endl;

    if (!employees.empty()) {
        cout << "Employee Details:";
        for (size_t i = 0; i < employees.size(); i++) {
            employees[i]->displayEmployeeInfo();

        }
    }
    else {
        cout << " No employees in the company yet " << endl;
    }
}



Company::~Company() {

}
