#pragma once
#include "CPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "storage.h"


class Computer
{
private:
    CPU cpu;
    RAM ram;
    Storage storage;
    Motherboard motherboard;

public:
    Computer();
    Computer(const CPU& cpu, const RAM& ram, const Storage& storage, const Motherboard& motherboard);
    Computer(const Computer& computer);
    Computer& operator=(const Computer& computer);
    void addCPU(const CPU& newCPU);
    void addRAM(const RAM& newRAM);
    void addStorageDevice(const Storage& newStorage);
    void removeCPU();
    void removeRAM();
    void removeStorageDevice();
    void addMotherboard(Motherboard newMotherboard);
    void printSpecs();
    friend ostream& operator<<(ostream& cout, const Computer& computer) {

        cout << computer.cpu << endl;
        cout << computer.ram << endl;
        cout << computer.motherboard << endl;
        cout << computer.storage << endl;

        cout << endl;

        return cout;

    }
    friend istream& operator>>(istream& cin, Computer& computer) {

        cin >> computer.cpu;
        cin >> computer.ram;
        cin >> computer.motherboard;
        cin >> computer.storage;

        return cin;

    }
};



Computer::Computer() : cpu(), ram(), storage(), motherboard() {}

void Computer::printSpecs() {

    cout << cpu << endl;
    cout << ram << endl;
    cout << motherboard << endl;
    cout << storage << endl;

    cout << endl;

}

void Computer::addMotherboard(Motherboard newMotherboard) {
   this->motherboard = newMotherboard;
}

void Computer::addCPU(const CPU& newCPU) {
    this->cpu = newCPU;
}

void Computer::addRAM(const RAM& newRAM) {
    this->ram = newRAM;
}

void Computer::addStorageDevice(const Storage& newStorage) {
    storage = newStorage;
}

Computer::Computer(const CPU& cpu, const RAM& ram, const Storage& storage, const Motherboard& motherboard) {

    this->cpu = cpu;
    this->ram = ram;
    this->storage = storage;
    this->motherboard = motherboard;

}

Computer::Computer(const Computer& computer) {
    cpu = computer.cpu;
    ram = computer.ram;
    storage = computer.storage;
    motherboard = computer.motherboard;
}

Computer& Computer::operator=(const Computer& computer) {

    this->cpu = computer.cpu;
    this->ram = computer.ram;
    this->storage = computer.storage;
    this->motherboard = computer.motherboard;

    return *this;

}

void Computer::removeCPU() {

    cpu.remove_cpu();
}

void Computer::removeRAM() {

    ram.remove_ram();
    
}

void Computer::removeStorageDevice() {

    storage.remove_storage();

}


