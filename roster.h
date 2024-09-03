#pragma once
#include "student.h"
#include "degree.h"
#include <array>
using namespace std;

class Roster {

private:
    int stu;
    int rosterSize;

public:
    Student* classRosterArray[5];
    Roster(int rosterSize);
    ~Roster();

    void parseAndAddStudent(string studentFields);
    void add(string studentID, string firstName, string lastName, 
        string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
