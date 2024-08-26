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
	void setEmailAddress(string emailAdress);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// Getters declarations
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int getdaysToComplete1() const;
	int getdaysToComplete2() const;
	int getdaysToComplete3() const;
	DegreeProgram getDegreeProgram() const;

	// Constructor declaration
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, DegreeProgram degreeProgram);
	~Student();

	// Print method declaration
	void print();

};

