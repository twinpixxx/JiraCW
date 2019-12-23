#include "cProject.h"
#include "cException.h"
#include <iomanip>


cProject::cProject(const cProject& tempObject) : projectTitle(tempObject.projectTitle), execFirstName(tempObject.execFirstName),
	execLastName(tempObject.execLastName) {};

//	body of constructor w/ params

cProject::cProject(std::string _title, std::string _execFN, std::string _execLN) : projectTitle(_title), execFirstName(_execFN),
	execLastName(_execLN) {};


//input override

std::istream& operator >> (std::istream& is, cProject& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	cout << "¬ведите название проекта: ";
	tempObject.projectTitle = tryThis.inputString();
	rewind(stdin);
	cout << "¬ведите им€ исполнител€: ";
	tempObject.execFirstName = tryThis.inputString();
	rewind(stdin);
	cout << "¬ведите фамилию исполнител€: ";
	tempObject.execLastName = tryThis.inputString();

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProject& tempObject)
{
	os << setiosflags(ios::left) << setw(25) << tempObject.projectTitle << setw(20)
		<< setw(15) << tempObject.execFirstName << setw(45)
		<< tempObject.execLastName;
	return os;
}