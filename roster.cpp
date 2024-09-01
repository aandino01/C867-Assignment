#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

Roster::Roster(int rosterSize) {
    this->rosterSize = rosterSize;           
    this->stu = 0;                               
    for (int i = 0; i < rosterSize; i++) {
        this->classRosterArray[i] = nullptr; 
    }
}
Roster::~Roster() {
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr) { 
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

void Roster::add(string studentFields) {
    stringstream ss(studentFields);
    string objHolder;
    string objArr[9];
    int objInd = 0;

    while (getline(ss, objHolder, ',')) {
        objArr[objInd++] = objHolder;
    }

    DegreeProgram degreeProgram;
    if (objArr[8] == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (objArr[8] == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (objArr[8] == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }

    int daysArray[3];
    daysArray[0] = stoi(objArr[5]);
    daysArray[1] = stoi(objArr[6]);
    daysArray[2] = stoi(objArr[7]);

                                    // ID,         first,     last,     email,     age     
    Student* newStudent = new Student(objArr[0], objArr[1], objArr[2], objArr[3], stoi(objArr[4]), 
        daysArray, degreeProgram);

    if (stu < 5) {
        classRosterArray[stu] = newStudent;
        stu += 1;
    }
}

void Roster::remove(string studentID) {
    bool isFound = false;

    for (int i = 0; i < stu; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            isFound = true;
            delete classRosterArray[i];

            for (int j = i; j < stu - 1; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }

            classRosterArray[stu - 1] = nullptr;
            stu--;

            cout << "Student " << studentID << " was removed from the roster.\n\n";
            break;
        }
    }

    if (!isFound) {
        cout << "Student ID: " << studentID << " was not found in the roster.\n";
    }

}

void Roster::printAll() {
    for (int i = 0; i < stu; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < stu; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {

            int days1 = classRosterArray[i]->getDaysToComplete1();
            int days2 = classRosterArray[i]->getDaysToComplete2();
            int days3 = classRosterArray[i]->getDaysToComplete3();

            double averageDays = (days1 + days2 + days3) / 3.0;

            cout << "Student ID: " << studentID << ", average days in course is: ";
            cout << averageDays << endl;
        }
    }
}


void Roster::printInvalidEmails() {
    for (int i = 0; i < stu; i++) {
        string email = classRosterArray[i]->getEmailAddress();

        if (email.find('@') == string::npos) {
            cout << email << " is an invalid email address." << endl;
        }
        else if (email.find('.') == string::npos) {
            cout << email << " is an invalid email address." << endl;
        }
        else if (email.find(' ') != string::npos) {
            cout << email << " is an invalid email address." << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << endl;
    for (int i = 0; i < stu; i++) {
        DegreeProgram deg = classRosterArray[i]->getDegreeProgram();
     
        if (deg == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}















