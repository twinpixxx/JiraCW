#include "cProjectWithPriority.h"
#include "cException.h"
#include <iomanip>


cProjectWithPriority::cProjectWithPriority(const cProjectWithPriority& tempObject)
	: cProject(tempObject.projectTitle, tempObject.executor), projectPriority(tempObject.projectPriority) {};

//	body of constructor w/ params

cProjectWithPriority::cProjectWithPriority(std::string projectName, int _priority, cCompanyEmployee _exec)
	: cProject(projectName, _exec), projectPriority(_priority) {};


//input override

std::istream& operator >> (std::istream& is, cProjectWithPriority& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cProject&)tempObject;

	cout << "Введите приоритет проекта (0-3): ";
	tempObject.projectPriority = tryThis.inputNumber(0, 3);

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProjectWithPriority& tempObject)
{
	os << (cProject&)tempObject;

	os << setiosflags(ios::left) << setw(20) << tempObject.projectPriority;

	return os;
}