#pragma once
#include "student.h"
#include "degree.h"
#include <array>

class Roster {

private:
	Student* classRosterArray[5];

public:
	Roster(int amountOfStu);
	~Roster();
};