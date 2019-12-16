#include "cCountry.h"
#include <iostream>
#include <iomanip>
#include "cException.h"



//	body of copy constructor

cCountry::cCountry(const cCountry& tempObj) 
{
	countryName = tempObj.countryName;
};

//	body of constructor w/ params

cCountry::cCountry(std::string _name) : countryName(_name) {};


//input override

std::istream& operator >> (std::istream& is, cCountry& tempObj)
{
	inputExceptions tryThis;
	system("cls");

	cout << "¬ведите название страны: ";
	tempObj.countryName = tryThis.inputString();
		
	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cCountry& tempObj)
{
	os << setiosflags(ios::left) << setw(20) << tempObj.countryName;

	return os;
}