#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Storage
{
private:
    vector<string> drives;
    int totalCapacityTB;

public:
    Storage();
    Storage(const vector<string>& drives, int totalCapacityTB);
    Storage(Storage& storage);
    void upgradeCapacity(int newTotalCapacityTB);
    Storage& operator=(const Storage& storage);
    void addDrive(string drive);
    void printDetails();
    void setDrives(vector<string> drives);
    void setTotalCapacityTB(int totalCapacityTB);
    vector<string> getDrives();
    void remove_storage();
    int getTotalCapacityTB();
    //friend ostream& operator<<(ostream& cout, const Storage& storage);
    friend ostream& operator<<(ostream& cout, const Storage& storage) {
        cout << "storage details are following " << endl;
        cout << "the total storage capacity is " << storage.totalCapacityTB << endl;
        for (int i = 0; i < storage.drives.size(); ++i) {
            cout << storage.drives[i] << " ";
        }
        cout << endl;

        return cout;
    }
    friend istream& operator>>(istream& cin, Storage& storage) {
        cout << "enter the drives (input -1 to quit): " << endl;

        string drive;
        while (drive != "done") {
            cout << "Enter a drive name (or 'done' to finish): ";
            getline(cin, drive);

            if (drive != "done") {
                storage.drives.push_back(drive);
            }
        }

        cin >> storage.totalCapacityTB;

        return cin;
    }
};






Storage::Storage(){
    this->totalCapacityTB = totalCapacityTB;
}


Storage::Storage(const vector<string>& drives, int totalCapacityTB)
        : totalCapacityTB(totalCapacityTB) {
        
        this->drives.reserve(drives.size());
        std::copy(drives.begin(), drives.end(), std::back_inserter(this->drives));
    }

    
Storage::Storage(Storage& other) : totalCapacityTB(other.totalCapacityTB) {
        
        this->drives.reserve(other.drives.size());
        std::copy(other.drives.begin(), other.drives.end(), std::back_inserter(this->drives));
    }


    void Storage::upgradeCapacity(int newTotalCapacityTB) {
        totalCapacityTB = newTotalCapacityTB;
    }

    
    Storage& Storage::operator=(const Storage& storage) {
        if (this != &storage) {
            totalCapacityTB = storage.totalCapacityTB;
            this->drives.clear();
            this->drives.reserve(storage.drives.size());
            std::copy(storage.drives.begin(), storage.drives.end(), std::back_inserter(this->drives));
        }
        return *this;
    }

    void Storage::addDrive(string drive) {
        drives.push_back(drive);
    }

    void Storage::printDetails(){
        cout << "Drives are : " << endl;
        for (const string& drive : drives) {
            cout << " | " << drive << endl;
        }
        cout << "Total Capacity (TB): " << totalCapacityTB << endl;
    }

    void Storage::setDrives(const vector<string> drives) {
        this->drives = drives;
    }

    void Storage::setTotalCapacityTB(int totalCapacityTB) {
        this->totalCapacityTB = totalCapacityTB;
    }

    vector<string> Storage::getDrives(){
        return drives;
    }

    int Storage::getTotalCapacityTB(){
        return totalCapacityTB;
    }

    void Storage::remove_storage() {

        this->drives.clear();
        this->totalCapacityTB = 0;

    }