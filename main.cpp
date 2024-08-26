#include "student.h"
#include <iostream>

using namespace std;

int main() {
    // Array for days to complete
    int daysToComplete[3] = { 10, 20, 30 };

    // Create a Student object
    Student student1("A1", "John", "Doe", "john.doe@example.com", 25, daysToComplete, DegreeProgram::SOFTWARE);

    // Test print method
    student1.print();

    return 0;
}
