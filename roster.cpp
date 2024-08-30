#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor   
Roster::Roster(int rosterSize) {                
	this->rosterSize = rosterSize;
	this->stu = 0;
	for (int i = 0; i < rosterSize; i++) {
		this->classRosterArray[i] = nullptr;    
	}
}
// Destructor
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

    Student* newStudent = new Student(objArr[0], objArr[1], objArr[2], objArr[3], stoi(objArr[4]), daysArray, degreeProgram);

    if (stu < 5) {
        classRosterArray[stu] = newStudent;
        stu+=1;
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

          cout << "Student " << studentID << " removed from the roster." << endl;
          break;
        }
    }

    if (!isFound) {
        cout << "Student ID: " << studentID << " was not found in the roster." << endl;
    }
}


void Roster::printAll() {
    for (int i = 0; i < this->stu; i++) {
        this->classRosterArray[i]->print();
    }
}


