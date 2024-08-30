#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	// Setters declarations
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// Getters declarations
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int getDaysToComplete1() const;
	int getDaysToComplete2() const;
	int getDaysToComplete3() const;
	DegreeProgram getDegreeProgram() const;

	// Constructor declaration
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram);

	// Print method declaration
	void print();

};

