#include "student.h"
#include <iostream>

using namespace std;

int main() {

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom, 19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19, 20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22, 50,58,40,SECURITY",
    "A5,Alfredo,Andino,aandi14@wgu.edu,37, 45,20,30,SOFTWARE"
    };

    // Create a Student object
    Student student1("A1", "John", "Doe", "john.doe@example.com", 25, 15,26,26, DegreeProgram::SOFTWARE);

    // Test print method
    student1.print();

    return 0;
}
