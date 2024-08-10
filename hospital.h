#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "doctor.h"
#include "patient.h"
class Doctor;
class Patient;
class Hospital {
private:
    vector<Doctor*> doctors;
    vector<Patient*> patients;

public:
    Hospital();
    Hospital(const Hospital& hospital);
    Hospital& operator=(const Hospital& hospital);
    void addDoctor(Doctor* doctor);
    void addPatient(Patient* patient);
    //void assignPatientsToDoctors();
    void assignPatientsToDoctors() {
        if (doctors.empty() || patients.empty()) {
            return;
        }

        /*
        size_t doctorIndex = 0;
        for (Patient* patient : patients) {
            doctors[doctorIndex % doctors.size()]->addPatient(patient);
            doctorIndex++;
        }
        */
        size_t doci = 0;
        for (Patient* patient : patients)
        {
            doctors[doci]->addPatient(patient);
            ++doci;
            if (doci == doctors.size())
            {
                doci = 0;
            }
        }
    }

    vector<Doctor*> getDoctors() const;
    vector<Patient*> getPatients() const;
    //friend ostream& operator<<(ostream& os, const Doctor& doctor);
   /* friend ostream& operator<<(ostream& cout, const Hospital& hospital);*/
        /*cout << "Hospital Information:" << endl;
        cout << "  Doctors (" << hospital.doctors.size() << "):" << endl;
        if (hospital.doctors.empty()) {
            cout << "    None" << endl;
        }
        else {
            for (Doctor* doctor : hospital.doctors)
            {
                cout << "    | " << *doctor << endl<<endl;
            }
        }
        cout << "  patientz (" << hospital.patients.size() << ") :: " << endl <<endl;
        if (hospital.patients.empty()) {
            cout << "    None" << endl;
        }
        else {
            for (Patient* patient : hospital.patients) {
                cout << "    | " << *patient << endl;
            }
        }
        return cout;
    }*/

    friend ostream& operator<<(ostream& os, const Doctor& doctor)
    {
        os << "Name: " << doctor.getName() << endl;
        os << "Specialization: " << doctor.getSpecialization() << endl;
        return os;
    }
 
};


class Doctor;
class Patient;

    Hospital::Hospital() {}

    Hospital::Hospital(const Hospital& hospital) {
        doctors = hospital.doctors;
        patients = hospital.patients;
    }

    Hospital& Hospital::operator=(const Hospital& hospital) {
        if (this != &hospital) {
            doctors = hospital.doctors;
            patients = hospital.patients;
        }
        return *this;
    }

    void Hospital::addDoctor(Doctor* doctor) {
        doctors.push_back(doctor);
    }

    void Hospital::addPatient(Patient* patient) {
        patients.push_back(patient);
    }

   
     vector<Doctor*> Hospital::getDoctors() const {
        return doctors;
    }

    vector<Patient*> Hospital::getPatients() const {
        return patients;
    }



    //  ostream& operator<<(ostream& os, const Hospital& hospital)
    //{
    //    os << "Doctors:" << endl;
    //    for (Doctor* doctor : hospital.doctors)
    //    {
    //        os << *doctor << endl;
    //    }
    //    os << "Patients:" << endl;
    //    for (Patient* patient : hospital.patients)
    //    {
    //        os << *patient << endl;
    //    }
    //    return os;
    //}
 
