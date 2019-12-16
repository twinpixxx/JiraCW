#include "cInternationalProjectWithDeadlineAndPriority.h"
#include "cException.h"
#include <iomanip>


cInternationalProjectWithDeadlineAndPriority::cInternationalProjectWithDeadlineAndPriority
(const cInternationalProjectWithDeadlineAndPriority& tempObject)
{
	this->projectTitle = tempObject.projectTitle;
	this->country = tempObject.country;
	this->projectStartDate = tempObject.projectStartDate;
	this->projectEndDate = tempObject.projectEndDate;
	this->projectPriority = tempObject.projectPriority;

};

//	body of constructor w/ params

cInternationalProjectWithDeadlineAndPriority::cInternationalProjectWithDeadlineAndPriority
(std::string projectName, std::string _countryName, std::string _start, std::string _end, int _priority)
{
	this->projectTitle = projectName;
	this->country.setCountryName(_countryName);
	this->projectStartDate = _start;
	this->projectEndDate = _end;
	this->projectPriority = projectPriority;

}


//input override

std::istream& operator >> (std::istream& is, cInternationalProjectWithDeadlineAndPriority& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cInternationalProject&)tempObject;

	rewind(stdin);
	cout << "������� ���� ������ ������� (��.��.����): ";
	tempObject.projectStartDate = tryThis.inputDate();
	rewind(stdin);
	cout << "������� ���� ��������� ������� (��.��.����): ";
	tempObject.projectEndDate = tryThis.inputDate();
	rewind(stdin);
	cout << "������� ��������� ������� (0-3): ";
	tempObject.projectPriority = tryThis.inputNumber(0, 3);

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cInternationalProjectWithDeadlineAndPriority& tempObject)
{
	os << (cInternationalProject&)tempObject;

	os << setiosflags(ios::left) << setw(13) << tempObject.projectStartDate
		<< setw(13) << tempObject.projectEndDate 
		<< setw(20) << tempObject.projectPriority;

	return os;
}