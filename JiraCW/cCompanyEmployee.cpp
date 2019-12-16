#include "cCompanyEmployee.h"
#include "cException.h"
#include <iomanip>


//	body of constructor w/ params

cCompanyEmployee::cCompanyEmployee(std::string _firstName, std::string _lastName, cCountry _country, std::string _company, std::string _position)
	: cHuman(_firstName, _lastName, _country), position(_position), companyName(_company) {};


//	copy constructor
cCompanyEmployee::cCompanyEmployee(const cCompanyEmployee& tempObject)
{
	firstName = tempObject.firstName;
	lastName = tempObject.lastName;
	country = tempObject.country;
	position = tempObject.position;
	companyName = tempObject.companyName;
};


//input override

std::istream& operator >> (std::istream& is, cCompanyEmployee& tempObject)
{
	inputExceptions tryThis;
	std::string tempString;
	system("cls");
	rewind(stdin);

	is >> (cHuman&)tempObject;
	rewind(stdin);
	cout << "Введите название компании: ";
	tempObject.companyName = tryThis.inputString();
	rewind(stdin);
	cout << "Введите должность сотрудника: ";
	tempObject.position = tryThis.inputString();

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cCompanyEmployee& tempObject)
{

	os << (cHuman&)tempObject;

	os << setiosflags(ios::left) << setw(20) << tempObject.position;

	return os;
}