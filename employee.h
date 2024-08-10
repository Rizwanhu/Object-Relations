#pragma once
#include <string>
#include<vector>
#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int employeeID;
    string department;
    float salary;

public:
    // Constructor
    Employee();
    Employee(string name, int employeeID, string department, float salary);
    Employee(const Employee& emp);

    Employee& operator=(const Employee& emp);

    // Getter methods
    string getName() const;
    int getEmployeeID() const;
    string getDepartment() const;
    float getSalary() const;

    // Setter methods
    void setName(string newName);
    void setEmployeeID(int newID);
    void setDepartment(string newDept);
    void setSalary(float newSalary);

    void displayEmployeeInfo() const;
    friend ostream& operator<<(ostream& cout, const Employee& emp) {

        cout << "following are the details of the employee : " << endl;
        cout << "the name of the employee is " << emp.name << endl;
        cout << "the employee id is " << emp.employeeID << endl;
        cout << "the department of the employee is " << emp.department << endl;
        cout << "the salary of the employee is " << emp.salary << " $ " << endl;

        return cout;
    }
    friend istream& operator>>(istream& cin, Employee& emp) {

        cin >> emp.name;
        cin >> emp.employeeID;
        cin >> emp.department;
        cin >> emp.salary;

        return cin;
    }
    ~Employee();
};



Employee::Employee() {

    name = '\0';
    employeeID = 0;
    department = '\0';
    salary = 0;

}

Employee::Employee(string name, int employeeID, string department, float salary) {

    this->name = name;
    this->employeeID = employeeID;
    this->department = department;
    this->salary = salary;

}

Employee::Employee(const Employee& emp) {

    this->name = emp.name;
    this->employeeID = emp.employeeID;
    this->department = emp.department;
    this->salary = emp.salary;

    }

Employee& Employee::operator=(const Employee& emp) {

    this->name = emp.name;
    this->employeeID = emp.employeeID;
    this->department = emp.department;
    this->salary = emp.salary;

    return *this;

    }

string Employee::getName() const {
    return name;
    }

int Employee::getEmployeeID() const {
    return employeeID;
    }

string Employee::getDepartment() const {
    return department;
    }

float Employee::getSalary() const {
    return salary;
    }




void Employee::setName(string newName) {
    this->name = newName;
    }

void Employee::setEmployeeID(int newID) {
    this->employeeID = newID;
    }

void Employee::setDepartment(string newDept) {
    this->department = newDept;
    }

void Employee::setSalary(float newSalary) {
    this->salary = newSalary;
    }



void Employee::displayEmployeeInfo() const {

    cout << "following are the details of the employee : " << endl;
    cout << "the name of the employee is " << name << endl;
    cout << "the employee id is " << employeeID << endl;
    cout << "the department of the employee is " << department << endl;
    cout << "the salary of the employee is " << salary << " $ " << endl;
    }





Employee::~Employee() {

}

