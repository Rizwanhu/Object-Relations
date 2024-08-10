#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Doctor;
#include "doctor.h"
#include "hospital.h"

class Patient {
private:
    string name;
    int age;
    vector<string> symptoms;

public:
    Patient();
    Patient(string name, int age);
    Patient(const Patient& patient);
    Patient& operator=(const Patient& patient);
    bool operator==(const Patient& patient) const;
    void addSymptom(string symptom);
    string getName() const;
    int getAge() const;
    vector<string> getSymptoms() const;
    friend ostream& operator<<(ostream& cout, const Patient& patient) {
        cout << "Patient Information:" << endl;
        cout << "  Name: " << patient.name << endl;
        cout << "  Age: " << patient.age << endl;
        cout << "  Symptoms: ";

        if (patient.symptoms.empty()) {
            cout << "None" << endl;
        }
        else {
            cout << endl;
            for (const string& symptom : patient.symptoms) {
                cout << "    - " << symptom << endl;
            }
        }
        return cout;
    }
};




Patient::Patient() {

    name = "";
    age = 0;
    symptoms = vector<string>();
}

Patient::Patient(string name, int age) {

    this->name = name;
    this->age = age;
}

Patient::Patient(const Patient& patient) {

    name = patient.name;
    age = patient.age;

}


    Patient& Patient::operator=(const Patient& patient) {
        if (this != &patient) {
            name = patient.name;
            age = patient.age;
            symptoms = patient.symptoms;
        }
        return *this;
    }

    bool Patient::operator==(const Patient& patient) const {
        return (name == patient.name && age == patient.age);
    }

    void Patient::addSymptom(string symptom) {
        symptoms.push_back(symptom);
    }

    string Patient::getName() const {
        return name;
    }

    int Patient::getAge() const {
        return age;
    }

    vector<string> Patient::getSymptoms() const {
        return symptoms;
    }



