#include <iostream>
#include <cstring>
//give Patient and Doctor class a name if want do array immediately means class created, need name
using namespace std;

class Person { //base class for common attributes
protected: //Patient and Doctors derived class can have access to this
    char name[100];
    int age;
    char gender[10];
    char address[100];
}; //Base class attributes auto included in derived class

class Patient : public Person { //derived class for patients
    char illness[100]; //add on to Person (can add but cant reduce)
    char doctorAssigned[100];
    int roomNum;

public: //illness, doctorAssigned and roomNum private by default->need get() getter func to access it
    void patientRegistration() {
        cout << "Enter patient name:" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;
        cout << "Enter Gender" << endl;
        cin >> gender;
        cout << "Enter address" << endl;
        cin >> address;
        cout << "Enter illness" << endl;
        cin >> illness;
        cout << "Enter patient room number" << endl;
        cin >> roomNum;
        strcpy(doctorAssigned, ""); // Initialize to no doctor assigned (must complete all class attributes)
        cout << "Patient registered successfully" << endl;
    }

    char* getIllness() { return illness; }
    char* getDoctorAssigned() { return doctorAssigned; }
    char* getName() { return name; }
    int getRoomNum() { return roomNum; }
    void assignDoctor(const char* docName) { strcpy(doctorAssigned, docName); }
};

class Doctor : public Person { //derived class for doctors
    char specialization[100];
    bool availability; //'1' available ; '0' X available

public:
    void doctorRegistration() {
        cout << "Enter doctor name:" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;
        cout << "Enter Gender" << endl;
        cin >> gender;
        cout << "Enter address" << endl;
        cin >> address;
        cout << "Enter specialization" << endl;
        cin >> specialization;
        availability = true; // Default to available
        cout << "Doctor registered successfully" << endl;
    }

    bool isAvailable() { return availability; }
    char* getSpecialization() { return specialization; }
    char* getName() { return name; }
    void markUnavailable() { availability = false; }
};

class Hospital {
    Patient patients[1000]; //multiple patient and doctors
    Doctor doctors[500];
    int patientCount = 0;
    int doctorCount = 0;

public:
    void addPatient() {
        patients[patientCount].patientRegistration();
        patientCount++;
    }

    void addDoctor() {
        doctors[doctorCount].doctorRegistration();
        doctorCount++;
    }

    void assignDoctorToPatient() {
        for (int i = 0; i < patientCount; i++) {
            if (strlen(patients[i].getDoctorAssigned()) == 0) { // Unassigned patient
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].isAvailable() && strcmp(doctors[j].getSpecialization(), patients[i].getIllness()) == 0) {
                        patients[i].assignDoctor(doctors[j].getName());
                        doctors[j].markUnavailable();
                        cout << "Assigned Doctor " << doctors[j].getName()
                             << " to Patient " << patients[i].getName() << endl;
                        return;
                    }
                }
            }
        }
        cout << "No available doctor for unassigned patients." << endl;
    }
};

class Bill {
    int id;
    int treatment;
    int room;
    int total;

public:
    void billingUpdate() {
        cout << "Enter patient ID" << endl;
        cin >> id;
        cout << "Enter treatment cost" << endl;
        cin >> treatment;
        cout << "Enter room cost" << endl;
        cin >> room;
        total = treatment + room;
    }

    void displayBill() {
        cout << "Bill for patient " << id << endl;
        cout << "Treatment fee: $" << treatment << endl;
        cout << "Room fee: $" << room << endl;
        cout << "Total cost: $" << total << endl;
    }
};

Hospital hospital; //create hospital(name of class of Hospital) after Patient and Doctor class as Hospital have patient and doctor class which needs to be defined first

int main() {
    int notExit = 1;
    while (notExit) {
        int choice;
        cout << "Enter your choice:" << endl;
        cout << "1. Patient Registration" << endl;
        cout << "2. Doctor Registration" << endl;
        cout << "3. Doctor-patient assignment" << endl;
        cout << "4. Billing system" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.addDoctor();
            break;
        case 3:
            hospital.assignDoctorToPatient();
            break;
        case 4: {
            Bill bill;
            bill.billingUpdate();
            bill.displayBill();
            break;
        }
        case 5:
            notExit = 0;
            cout << "Exit successful" << endl;
            break;
        default: //always consider worse case scenario
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}

