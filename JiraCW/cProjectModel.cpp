#include "cProjectModel.h"
#include "cException.h"
#include <iostream>
#include <iomanip>


//	body of copy constructor

cProjectModel::cProjectModel(const cProjectModel& tempObj) 
	: projectTittle(tempObj.projectTittle), projectPriority(tempObj.projectPriority) {};

//	body of constructor w/ params

cProjectModel::cProjectModel(std::string _title, int _priority) 
	: projectTittle(_title), projectPriority(_priority) {};


//input override

std::istream& operator >> (std::istream& is, cProjectModel& tempObj)
{
	inputExceptions tryThis;
	system("cls");


	std::cout << "Введите название проекта: ";
	rewind(stdin);
	tempObj.projectTittle = tryThis.inputString();
	std::cout << "Введите приоритет проекта (0-3): ";
	rewind(stdin);
	tempObj.projectPriority = tryThis.inputNumber(0,3);


	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProjectModel& tempObj)
{

	os << setiosflags(ios::left) << setw(20) << tempObj.projectTittle
		<< setw(20) << tempObj.projectPriority;
	

	return os;
}