#include "cInternationalProject.h"
#include <iostream>
#include <iomanip>
#include "cException.h"

//	body of copy constructor

cInternationalProject::cInternationalProject(const cInternationalProject& tempObj)
	: cProject(tempObj.projectTittle, tempObj.projectTopic, tempObj.projectStartDate,
		tempObj.projectDeadlineDate, tempObj.projectDescription, tempObj.projectExecutor, tempObj.projectPriority),
	projectCountry(tempObj.projectCountry) {};

//	body of constructor w/ params

cInternationalProject::cInternationalProject(std::string _title, std::string _topic, std::string _startDate, std::string _deadline,
	std::string _description, std::string _exec, int _priority, std::string _country) : cProject(_title, _topic, _startDate,
		_deadline, _description, _exec, _priority), projectCountry(_country) {};


//input override

std::istream& operator >> (std::istream& is, cInternationalProject& tempObj)
{
	inputExceptions tryThis;
	system("cls");

	is >> (cProject&)tempObj;
	
	cout << "¬ведите страну проекта: ";
	tempObj.projectCountry = tryThis.inputString();
	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cInternationalProject& tempObj)
{

	os << (cProject&)tempObj;

	os << setiosflags(ios::left) << setw(20) << tempObj.projectCountry;


	return os;
}
