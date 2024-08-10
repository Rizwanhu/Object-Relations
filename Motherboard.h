#pragma once
#include <string>
using namespace std;

class Motherboard
{
private:
    string chipset;
    string socketType;
    int numRAMSlots;

public:
    Motherboard();
    Motherboard(string chipset, string socketType, int numRAMSlots);
    Motherboard(const Motherboard& motherboard);
    Motherboard& operator=(const Motherboard& motherboard);
    void upgradeSocket(string newSocketType);
    void printDetails();
    void setChipset(string chipset);
    void setSocketType(string socketType);
    void setNumRAMSlots(int numRAMSlots);
    string getChipset();
    string getSocketType();
    int getNumRAMSlots();
    friend ostream& operator<<(ostream& cout, const Motherboard& motherboard) {

        cout << "following are the motherboard details :: " << endl;
        cout << "the chipset used in the motherboard is " << motherboard.chipset << endl;
        cout << "the socket type in the motherboard is " << motherboard.socketType << endl;
        cout << "the number of ram slots in the motherboard are " << motherboard.numRAMSlots << endl;

        return cout;
    }
    friend istream& operator>>(istream& cin, Motherboard& motherboard) {

        cin >> motherboard.chipset;
        cin >> motherboard.socketType;
        cin >> motherboard.numRAMSlots;

        return cin;
    }
};




Motherboard::Motherboard() {

    chipset = '\0';
    socketType = '\0';
    numRAMSlots = 0;
}

Motherboard::Motherboard(string chipset, string socketType, int numRAMSlots) {

    this->chipset = chipset;
    this->socketType = socketType;
    this->numRAMSlots = numRAMSlots;
}

Motherboard::Motherboard(const Motherboard& motherboard) {

    this->chipset = motherboard.chipset;
    this->socketType = motherboard.socketType;
    this->numRAMSlots = motherboard.numRAMSlots;
}

Motherboard& Motherboard::operator=(const Motherboard& motherboard) {

    this->chipset = motherboard.chipset;
    this->socketType = motherboard.socketType;
    this->numRAMSlots = motherboard.numRAMSlots;

    return *this;
}

void Motherboard::upgradeSocket(string newSocketType) {
    socketType = newSocketType;
}

void Motherboard::printDetails() {
    cout << "following are the details of the motherboard : " << endl;
    cout << "the chipset used is " << chipset << endl;
    cout << "the socket type used in the motherboard is " << socketType << endl;
    cout << "the number of ram slots in the motherboard are " << numRAMSlots << endl;
}


void Motherboard::setChipset(string chipset) {
    this->chipset = chipset;
}

void Motherboard::setSocketType(string socketType) {
    this->socketType = socketType;
}

void Motherboard::setNumRAMSlots(int numRAMSlots) {
    this->numRAMSlots = numRAMSlots;
}

string Motherboard::getChipset() {
    return chipset;
}

string Motherboard::getSocketType() {
    return socketType;
}

int Motherboard::getNumRAMSlots() {
    return numRAMSlots;
}

