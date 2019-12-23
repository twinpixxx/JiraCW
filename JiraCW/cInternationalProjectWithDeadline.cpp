#include "cInternationalProjectWithDeadline.h"
#include "cException.h"
#include <iomanip>


cInternationalProjectWithDeadline::cInternationalProjectWithDeadline(const cInternationalProjectWithDeadline& tempObject)
{
	this->projectTitle = tempObject.projectTitle;
	this->country = tempObject.country;
	this->projectStartDate = tempObject.projectStartDate;
	this->projectEndDate = tempObject.projectEndDate;
	this->execFirstName = tempObject.execFirstName;
	this->execLastName = tempObject.execLastName;
};

//	body of constructor w/ params

cInternationalProjectWithDeadline::cInternationalProjectWithDeadline(std::string projectName, std::string _countryName, std::string _start, std::string _end,
	std::string _execFirstName, std::string _execLastName)
{
	this->projectTitle = projectName;
	this->country.setCountryName(_countryName);
	this->projectStartDate = _start;
	this->projectEndDate = _end;
	this->execFirstName = _execFirstName;
	this->execLastName = _execLastName;
}


//input override

std::istream& operator >> (std::istream& is, cInternationalProjectWithDeadline& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cInternationalProject&)tempObject;

	rewind(stdin);
	cout << "Введите дату начала проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectStartDate = tryThis.inputDate();
	rewind(stdin);
	cout << "Введите дату окончания проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectEndDate = tryThis.inputDate();

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cInternationalProjectWithDeadline& tempObject)
{
	os << (cInternationalProject&)tempObject;

	os << setiosflags(ios::left)  << setw(30) << tempObject.projectStartDate
		<< setw(35) << tempObject.projectEndDate;

	return os;
}