#include <string>
#include "student.h"
#include <iostream>
using namespace std;

// Setters definitions
void Student::setStudentID(string studentID) { 
	this->studentID = studentID; 
}

void Student::setFirstName(string firstName) { 
	this->firstName = firstName; 
}

void Student::setLastName(string lastName) { 
	this->lastName = lastName; 
}

void Student::setEmailAddress(string emailAddress) { 
	this->emailAddress = emailAddress; 
}

void Student::setAge(int age) {	
	this->age = age; 
} 

void Student::setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3) {
	this->daysToComplete[0] = daysToComplete1;
	this->daysToComplete[1] = daysToComplete2;
	this->daysToComplete[2] = daysToComplete3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { 
	this->degreeProgram = degreeProgram; 
}

// Getters definitions
string Student::getStudentID() const { 
	return studentID; 
}

string Student::getFirstName() const { 
	return firstName; 
}

string Student::getLastName() const { 
	return lastName; 
}

string Student::getEmailAddress() const { 
	return emailAddress; 
}

int Student::getAge() const { 
	return age; 
}

int Student::getdaysToComplete1() const { 
	return daysToComplete[0]; 
}

int Student::getdaysToComplete2() const { 
	return daysToComplete[1]; 
}

int Student::getdaysToComplete3() const { 
	return daysToComplete[2]; 
}

DegreeProgram Student::getDegreeProgram() const { 
	return degreeProgram; 
}

// Constructor definition

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToComplete[0] = 0;
	this->daysToComplete[1] = 0;
	this->daysToComplete[2] = 0;
	this->degreeProgram;
}

Student::~Student()
{
}

//Print method definition
void Student::print() {
	string degProg;
	switch (degreeProgram) {
	case SECURITY:
		degProg = "SECURITY";
		break;
	case NETWORK:
		degProg = "NETWORK";
		break;
	case SOFTWARE:
		degProg = "SOFTWARE";
		break;
	}

	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t"; 
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t ";
	cout << " daysInCourse: {" << daysToComplete[0] << ", "<< daysToComplete[1] << ", "<< daysToComplete[2] << "}\t ";
	cout << "Degree Program : " << degProg << "." << endl;
}


