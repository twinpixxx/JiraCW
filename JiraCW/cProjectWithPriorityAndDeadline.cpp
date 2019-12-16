#include "cProjectWithPriorityAndDeadline.h"
#include "cException.h"
#include <iomanip>


cProjectWithPriorityAndDeadline::cProjectWithPriorityAndDeadline(const cProjectWithPriorityAndDeadline& tempObject)
{
	this->projectTitle = tempObject.projectTitle;
	this->projectPriority = tempObject.projectPriority;
	this->projectStartDate = tempObject.projectStartDate;
	this->projectEndDate = tempObject.projectEndDate;
};

//	body of constructor w/ params

cProjectWithPriorityAndDeadline::cProjectWithPriorityAndDeadline(std::string projectName, int _priority, std::string _start, std::string _end)
{
	this->projectTitle = projectName;
	this->projectPriority = _priority;
	this->projectStartDate = _start;
	this->projectEndDate = _end;
}


//input override

std::istream& operator >> (std::istream& is, cProjectWithPriorityAndDeadline& tempObject)
{
	inputExceptions tryThis;
	system("cls");
	rewind(stdin);

	is >> (cProjectWithPriority&)tempObject;

	rewind(stdin);
	cout << "Введите дату начала проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectStartDate = tryThis.inputDate();
	rewind(stdin);
	cout << "Введите дату окончания проекта (ДД.ММ.ГГГГ): ";
	tempObject.projectEndDate = tryThis.inputDate();

	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProjectWithPriorityAndDeadline& tempObject)
{
	os << (cProjectWithPriority&)tempObject;

	os << setiosflags(ios::left) << setw(13) << tempObject.projectStartDate
		<< setw(13) << tempObject.projectEndDate;

	return os;
}