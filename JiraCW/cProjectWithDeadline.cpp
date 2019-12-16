#include "cProjectWithDeadline.h"
#include "cException.h"
#include <iomanip>


cProjectWithDeadline::cProjectWithDeadline(const cProjectWithDeadline& tempObject)
	: cProject(tempObject.projectTitle, tempObject.executor), projectStartDate(tempObject.projectStartDate), projectEndDate(tempObject.projectEndDate) {};

//	body of constructor w/ params

cProjectWithDeadline::cProjectWithDeadline(std::string projectName, std::string _start, std::string _end, cCompanyEmployee _exec)
	: cProject(projectName, _exec), projectStartDate(_start), projectEndDate(_end) {};


//input override

std::istream& operator >> (std::istream& is, cProjectWithDeadline& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cProject&)tempObject;

	cout << "Введите дату начала проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectStartDate = tryThis.inputDate();
	rewind(stdin);
	cout << "Введите дату окончания проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectEndDate = tryThis.inputDate();

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProjectWithDeadline& tempObject)
{
	os << (cProject&)tempObject;

	os << setiosflags(ios::left) << setw(13) << tempObject.projectStartDate
		<< setw(13) << tempObject.projectEndDate;

	return os;
}