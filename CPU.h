#pragma once
#include <string>
#include <iostream>
using namespace std;

class CPU
{
private:
    string brand;
    string model;
    double clockSpeedGHz;
    int numCores;

public:
    CPU();
    CPU(string brand, string model, double clockSpeedGHz, int numCores);
    CPU(const CPU& cpu);
    void upgradeCores(int newNumCores);
    CPU& operator=(const CPU& cpu);
    void overclock(double newClockSpeed);
    void printDetails();
    void setBrand(string brand);
    void setModel(string model);
    void setClockSpeedGHz(double clockSpeedGHz);
    void setNumCores(int numCores);
    string getBrand();
    string getModel();
    double getClockSpeedGHz();
    int getNumCores();
    void remove_cpu();
    friend ostream& operator<<(ostream& cout, const CPU& cpu) {

        cout << "following are the cpu details :: " << endl;
        cout << "the brand of cpu is " << cpu.brand << endl;
        cout << "the model of cpu is " << cpu.model << endl;
        cout << "the clock-speed of the cpu is " << cpu.clockSpeedGHz << " GHz" << endl;
        cout << "the number of cores in this cpu is " << cpu.numCores << endl;

        return cout;
    }
    friend istream& operator>>(istream& cin, CPU& cpu) {
        cin >> cpu.brand;
        cin >> cpu.model;
        cin >> cpu.clockSpeedGHz;
        cin >> cpu.numCores;

        return cin;
    }
};




CPU::CPU() {
    brand = '\0';
    model = '\0';
    clockSpeedGHz = 0.0;
    numCores = 0;
}


CPU::CPU(string brand, string model, double clockSpeedGHz, int numCores) {

    this->brand = brand;
    this->model = model;
    this->clockSpeedGHz = clockSpeedGHz;
    this->numCores = numCores;

}

CPU::CPU(const CPU& cpu) {

    brand = cpu.brand;
    model = cpu.model;
    clockSpeedGHz = cpu.clockSpeedGHz;
    numCores = cpu.numCores;

}


void CPU::upgradeCores(int newNumCores) {

    if (newNumCores <= 0) {
        cout << "number of cores cannot be zero or negative." << endl;
        return;
    }

   numCores = newNumCores;

}


CPU& CPU::operator=(const CPU& cpu) {
    
    if (this == &cpu) {
        return *this;
    }

    brand = cpu.brand;
    model = cpu.model;
    clockSpeedGHz = cpu.clockSpeedGHz;
    numCores = cpu.numCores;

    return *this;

}

void CPU::overclock(double newClockSpeed) {

    if (newClockSpeed<=0)
    {
        cout << "chawal na marein..." << endl; return;
    }

    this->clockSpeedGHz = newClockSpeed;

}


void CPU::printDetails() {

    cout << "following are the cpu details :: " << endl;
    cout << "the brand of cpu is " << brand << endl;
    cout << "the model of cpu is " << model << endl;
    cout << "the clock-speed of the cpu is " << clockSpeedGHz << " GHz" << endl;
    cout << "the number of cores in this cpu is " << numCores << endl;

}


void CPU::setBrand(string brand) {
    this->brand = brand;
}


void CPU::setModel(string model) {

    this->model = model;
}

void CPU::setClockSpeedGHz(double clockSpeedGHz) {

    this->clockSpeedGHz = clockSpeedGHz;
}

void CPU::setNumCores(int numCores) {
    this->numCores = numCores;
}

string CPU::getBrand() {

    return brand;
}

string CPU::getModel() {
    return model;
}

double CPU::getClockSpeedGHz() {
    return clockSpeedGHz;
}

int CPU::getNumCores() {
    return numCores;
}

void CPU::remove_cpu() {
    this->brand = '\0';
    this->model = '\0';
    this->clockSpeedGHz = 0.0;
    this->numCores = 0;
}