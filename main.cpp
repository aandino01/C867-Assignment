#include "student.h"
#include "roster.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Course Title: C867-Scripting and Programming - Applications\n";
    cout << "Programming Language Used: C++\n";
    cout << "Student ID: 012011493\n";
    cout << "Name: Alfredo Andino\n\n";

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom, 19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19, 20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22, 50,58,40,SECURITY",
    "A5,Alfredo,Andino,aandi14@wgu.edu,37, 45,20,30,SOFTWARE"
    };

    Roster classRoster(5);

    int numOfstudents = sizeof(studentData) / sizeof(studentData[0]);
    
    for (int i = 0; i < numOfstudents; i++) {
        classRoster.add(studentData[i]);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < numOfstudents; i++) {
        string studentID = classRoster.classRosterArray[i]->getStudentID(); // Access the student ID
        classRoster.printAverageDaysInCourse(studentID);
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    classRoster.~Roster();

    return 0;
}
