#pragma once
#include "student.h"
#include "degree.h"
#include <array>
using namespace std;

class Roster {

private:
    Student* classRosterArray[5];
    int pos;
    int amountOfStudents;

public:
    Roster(int size);
    ~Roster();

    void addStudent(string studentData);
    void removeStudent(string studentID);
    void printAllStudents();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
