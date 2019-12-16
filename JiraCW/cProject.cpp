#include "cProject.h"
#include "cException.h"
#include <iomanip>


cProject::cProject(const cProject& tempObject) : projectTitle(tempObject.projectTitle), executor(tempObject.executor) {};

//	body of constructor w/ params

cProject::cProject(std::string _title, cCompanyEmployee _exec) : projectTitle(_title), executor(_exec) {};


//input override

std::istream& operator >> (std::istream& is, cProject& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	cout << "¬ведите название проекта: ";
	tempObject.projectTitle = tryThis.inputString();
	rewind(stdin);
	cout << "¬ведите им€: ";
	tempObject.executor.setFirstName(tryThis.inputString());
	rewind(stdin);
	cout << "¬ведите фамилию: ";
	tempObject.executor.setLastName(tryThis.inputString());
	rewind(stdin);
	cout << "¬ведите гражданство: ";
	tempObject.executor.setCountryName(tryThis.inputString());
	rewind(stdin);
	cout << "¬ведите название компании: ";
	tempObject.executor.setCompanyName(tryThis.inputString());
	rewind(stdin);
	cout << "¬ведите должность: ";
	tempObject.executor.setPosition(tryThis.inputString());


	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProject& tempObject)
{
	os << setiosflags(ios::left) << setw(20) << tempObject.projectTitle;

	os << setw(20) << tempObject.executor.getCompanyName() << setw(20) << tempObject.executor.getCountryName() << setw(20)
		<< tempObject.executor.getFirstName() << setw(20) << tempObject.executor.getLastName()<< setw(20)
		<< tempObject.executor.getPosition();
	return os;
}