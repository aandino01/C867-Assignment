#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor for roster
Roster::Roster(int rosterSize) {
    this->rosterSize = rosterSize;           
    this->stu = 0;                               
    for (int i = 0; i < rosterSize; i++) {
        this->classRosterArray[i] = nullptr; 
    }
}
// Roster destructor
Roster::~Roster() {
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr) { 
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}
// Parse student data and call add method
void Roster::parseAndAddStudent(string studentFields) {
    istringstream ss(studentFields);
    string objHolder;

    string studentID, firstName, lastName, emailAddress;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    DegreeProgram degreeProgram;

    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    getline(ss, objHolder, ',');

    age = stoi(objHolder);

    getline(ss, objHolder, ',');
    daysInCourse1 = stoi(objHolder);

    getline(ss, objHolder, ',');
    daysInCourse2 = stoi(objHolder);

    getline(ss, objHolder, ',');
    daysInCourse3 = stoi(objHolder);

    getline(ss, objHolder, ',');
    if (objHolder == "SECURITY") {
        degreeProgram = SECURITY;
    } else if (objHolder == "NETWORK") {
        degreeProgram = NETWORK;
    } else if (objHolder == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
// Add students to roster 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);

    if (stu < rosterSize) {
        classRosterArray[stu] = newStudent;
        stu++;
    }
}
// Remove students from roster
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
// Print all students who have been added to the roster
void Roster::printAll() {
    for (int i = 0; i < stu; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}
// Average number of days it takes a student to complete a course
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
// Print emails that are not valid
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
// Filter out students by degree program and print them
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















