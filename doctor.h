#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "hospital.h"
#include "patient.h"
class Patient;
class Doctor {
private:
    string name;
    int age;
    string specialization;
    vector<Patient*> patients;
    vector<string> diagnoses;

    static string getDiagnosisFromSymptoms(vector<string> symptoms) {
        string diagnoses = "";
        for (string symptom : symptoms) {
            if (symptom == "headache")
            {
                diagnoses = diagnoses + ",migraine ";
            }
            else if (symptom == "cough")
            {
                diagnoses = diagnoses + ",cold ";

            }
            else if (symptom == "fever")
            {
                diagnoses = diagnoses + ",flu ";
            }
            else if (symptom == "stomachache")
            {
                diagnoses = diagnoses + ",food poisoning ";
            }
            else if (symptom == "rash")
            {
                diagnoses = diagnoses + ",allergy ";
            }
            else if (symptom == "dizziness")
            {
                diagnoses = diagnoses + ",low blood pressure ";

            }
            else if (symptom == "nausea")
            {
                diagnoses = diagnoses + ",allergy ";
            }

            else
            {
                diagnoses = diagnoses + ",unknown ";
            }
        }
        return diagnoses;
    }
public:

    Doctor();
    Doctor(string name, int age, string specialization);
    Doctor(const Doctor& doctor);
    Doctor& operator=(const Doctor& doctor);
    void addPatient(Patient* patient);
    void diagnosePatient(Patient* patient);
    string getName() ;
    int getAge() const;
    string getSpecialization() ;
    vector<Patient*> getPatients() const;
    string getDiagnosis(Patient* patient) const;
    void diagnosALL();
    ~Doctor();

    friend ostream& operator<<(ostream& os, const Doctor& doctor)
   {
        os << "Name: " << doctor.name << endl;
        os << "Age: " << doctor.age << endl;
        os << "Specialization: " << doctor.specialization << endl;
        os << "Patients:" << endl;
        for (Patient* patient : doctor.patients)
        {
            os << *patient << endl;
        }
        return os;
    }



};
#include"patient.h"
class Patient;
    Doctor::Doctor()
    {
        name = "";
        age = 0;
        specialization = "";
    }

    Doctor::Doctor(string name, int age, string specialization) {
        this->name = name;
        this->age = age;
        this->specialization = specialization;
    }

    Doctor::Doctor(const Doctor& doctor) {
        name = doctor.name;
        age = doctor.age;
        specialization = doctor.specialization;
        patients = doctor.patients;
    }

    Doctor& Doctor::operator=(const Doctor& doctor) {
        if (this != &doctor) {
            name = doctor.name;
            age = doctor.age;
            specialization = doctor.specialization;
            patients = doctor.patients;
        }
        return *this;
    }

    void Doctor::addPatient(Patient* patient) 
    {
        patients.push_back(patient);
    }

    void Doctor::diagnosePatient(Patient* patient)
    {
        string diagnosis = getDiagnosisFromSymptoms(patient->getSymptoms());
        diagnoses.push_back(diagnosis);
    }

    string Doctor::getName() {
        return name;
    }

    int Doctor::getAge() const {
        return age;
    }

    string Doctor::getSpecialization() {
        return specialization;
    }

    vector<Patient*> Doctor::getPatients() const
    {
        return patients;
    }



    string Doctor::getDiagnosis(Patient* patient) const
    {
        for (size_t i = 0; i < patients.size(); ++i)
        {
            if (patients[i] == patient)
            {
                return diagnoses[i];
            }
        }
        return "No diagnosis found";
    }

    void Doctor::diagnosALL() {
        diagnoses.clear();
        for (Patient* patient : patients) {
            diagnosePatient(patient);
        }
    }

    Doctor::~Doctor()
    {
       
    }

    