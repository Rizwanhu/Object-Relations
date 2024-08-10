#pragma once
#include <string>
using namespace std;

class RAM
{
private:
    int capacityGB;
    int speedMHz;
    string type;

public:
    RAM();
    RAM(int capacityGB, int speedMHz, string type);
    RAM(const RAM& ram);
    void changeSpeed(int newSpeedMHz);
    const RAM& operator=(const RAM& ram);
    void upgrade(int newCapacityGB);
    void printDetails();
    void setCapacityGB(int capacityGB);
    void setSpeedMHz(int speedMHz);
    void setType(string type);
    int getCapacityGB();
    int getSpeedMHz();
    string getType();
    void remove_ram();
    friend ostream& operator<<(ostream& cout, const RAM& ram) {
        cout << "the details of the ram are following: " << endl;
        cout << "the capacity of the ram is " << ram.capacityGB << " GB " << endl;
        cout << "the speed of the ram is " << ram.speedMHz << " MHz" << endl;
        cout << "the type of ram is " << ram.type << endl;

        return cout;
    }

    friend istream& operator>>(istream& cin, RAM& ram) {
        cin >> ram.capacityGB;
        cin >> ram.speedMHz;
        cin >> ram.type;

        return cin;
    }
};


RAM::RAM() {
    capacityGB = 0;
    speedMHz = 0;
    type = '\0';

}

RAM::RAM(int capacityGB, int speedMHz, string type) {

    this->capacityGB = capacityGB;
    this->speedMHz = speedMHz;
    this->type = type;

}

RAM::RAM(const RAM& ram) {

    this->capacityGB = ram.capacityGB;
    this->speedMHz = ram.speedMHz;
    this->type = ram.type;

}

void RAM::changeSpeed(int newSpeedMHz) {

    this->speedMHz = newSpeedMHz;
}


const RAM& RAM::operator=(const RAM& ram) {

    if (this == &ram) {
        return *this;
    }

    this->capacityGB = ram.capacityGB;
    this->speedMHz = ram.speedMHz;
    this->type = ram.type;

    return *this;

}

void RAM::upgrade(int newCapacityGB) {
    capacityGB = newCapacityGB;
}

void RAM::printDetails() {

    cout << "the details of the ram are following: " << endl;
    cout << "the capacity of the ram is " << capacityGB << " GB " << endl;
    cout << "the speed of the ram is " << speedMHz << " MHz" << endl;
    cout << "the type of ram is " << type << endl;

}

void RAM::setCapacityGB(int capacityGB) {

    this->capacityGB = capacityGB;
}

void RAM::setSpeedMHz(int speedMHz) {
    this->speedMHz = speedMHz;
}

void RAM::setType(string type) {
    this->type = type;
}

int RAM::getCapacityGB() {
    return capacityGB;
}

int RAM::getSpeedMHz() {
    return speedMHz;
}

string RAM::getType() {
    return type;
}


void RAM::remove_ram() {

    this->capacityGB = 0;
    this->speedMHz = 0;
    this->type = '\0';

}
