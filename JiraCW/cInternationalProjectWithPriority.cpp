#include "cInternationalProjectWithPriority.h"
#include "cException.h"
#include <iomanip>


cInternationalProjectWithPriority::cInternationalProjectWithPriority(const cInternationalProjectWithPriority& tempObject)
{
	this->projectTitle = tempObject.projectTitle;
	this->country = tempObject.country;
	this->projectPriority = tempObject.projectPriority;
};

//	body of constructor w/ params

cInternationalProjectWithPriority::cInternationalProjectWithPriority(std::string projectName, std::string _countryName, int _priority)
{
	this->projectTitle = projectName;
	this->country.setCountryName(_countryName);
	this->projectPriority = _priority;
}


//input override

std::istream& operator >> (std::istream& is, cInternationalProjectWithPriority& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cInternationalProject&)tempObject;

	rewind(stdin); 
	cout << "Введите приоритет проекта (0-3): ";
	tempObject.projectPriority = tryThis.inputNumber(0, 3);

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cInternationalProjectWithPriority& tempObject)
{
	os << (cInternationalProject&)tempObject;

	os << setiosflags(ios::left) << setw(20) << tempObject.projectPriority;

	return os;
}