#include "cInternationalProject.h"
#include "cException.h"
#include <iomanip>


cInternationalProject::cInternationalProject(const cInternationalProject& tempObject) 
	: cProject(tempObject.projectTitle, tempObject.execFirstName, tempObject.execLastName), country(tempObject.country) {};

//	body of constructor w/ params

cInternationalProject::cInternationalProject(std::string _name, cCountry _country, std::string _execFN, std::string _execLN)
	: cProject(_name, _execFN, _execLN), country(_country) {};


//input override

std::istream& operator >> (std::istream& is, cInternationalProject& tempObject)
{
	inputExceptions tryThis;
	std::string tempString;
	system("cls");
	rewind(stdin);

	is >> (cProject&)tempObject;

	cout << "������� �������� ������: ";
	tempObject.country.setCountryName(tryThis.inputString());

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cInternationalProject& tempObject)
{

	os << (cProject&)tempObject;

	os << setiosflags(ios::left) << setw(20) << tempObject.country.getCountryName();

	return os;
}