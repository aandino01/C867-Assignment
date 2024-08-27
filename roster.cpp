#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>

using namespace std;

// Constructor
Roster::Roster(int size) {
    this->amountOfStudents = size;
    this->pos = 0;
    for (int i = 0; i < amountOfStudents; ++i) {
        this->classRosterArray[i] = nullptr;  // Initialize array to nullptr
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < amountOfStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];  
        }
    }
}

void Roster::addStudent(string studentData) {
    if (this->pos < this->amountOfStudents) {
        // Parse the studentData string, create a new Student object, and assign it to classRosterArray[pos]
        // Increment pos after adding the student
        this->pos++;
    }
}


