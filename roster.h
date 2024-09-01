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

    void add(string studentFields);

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
