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

int Student::getDaysToComplete1() const { 
	return daysToComplete[0]; 
}

int Student::getDaysToComplete2() const { 
	return daysToComplete[1]; 
}

int Student::getDaysToComplete3() const { 
	return daysToComplete[2]; 
}

DegreeProgram Student::getDegreeProgram() const { 
	return degreeProgram; 
}

// Constructor definition
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete[0] = daysToComplete[0];
	this->daysToComplete[1] = daysToComplete[1];
	this->daysToComplete[2] = daysToComplete[2];
	this->degreeProgram = degreeProgram;
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
	cout << " daysInCourse: {" << daysToComplete[0] << ", "<< daysToComplete[1] << ", "<< daysToComplete[2] << "} ";
	cout << "Degree Program : " << degProg << ".\n";
}


