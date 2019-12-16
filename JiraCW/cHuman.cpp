#include "cHuman.h"
#include "cException.h"
#include <iomanip>


cHuman::cHuman(const cHuman& tempObject) 
	: firstName(tempObject.firstName), lastName(tempObject.lastName), country(tempObject.country) {};

//	body of constructor w/ params

cHuman::cHuman(std::string _firstName, std::string _lastName, cCountry _country)
	: firstName(_firstName), lastName(_lastName), country(_country) {};


//input override

std::istream& operator >> (std::istream& is, cHuman& tempObject)
{
	inputExceptions tryThis;
	std::string tempString;
	system("cls");
	rewind(stdin);

	cout << "������� ���: ";
	rewind(stdin);
	tempObject.firstName = tryThis.inputString();
	rewind(stdin);
	cout << "������� �������: ";
	tempObject.lastName = tryThis.inputString();
	rewind(stdin);
	cout << "������� �������� ������: ";
	tempObject.country.setCountryName(tryThis.inputString());
	

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cHuman& tempObject)
{
	os << setiosflags(ios::left) << setw(20) << tempObject.firstName
		<< setw(20) << tempObject.lastName;

	return os;
}