#include "cProject.h"
#include <iostream>
#include <iomanip>
#include "cException.h"

//	body of copy constructor

cProject::cProject(const cProject& tempObj) 
	: cProjectModel(tempObj.projectTittle, tempObj.projectPriority), projectTopic(tempObj.projectTopic),
	projectStartDate(tempObj.projectStartDate), projectDeadlineDate(tempObj.projectDeadlineDate),
	projectDescription(tempObj.projectDescription), projectExecutor(tempObj.projectExecutor) {};

//	body of constructor w/ params

cProject::cProject(std::string _title, std::string _topic, std::string _startDate, std::string _deadline,
	std::string _description, std::string _exec, int _priority) : cProjectModel(_title, _priority),
	projectTopic(_topic), projectStartDate(_startDate), projectDeadlineDate(_deadline),
	projectDescription(_description), projectExecutor(_exec) {};


//input override

std::istream& operator >> (std::istream& is, cProject& tempObj)
{
	inputExceptions tryThis;
	system("cls");

	is >> (cProjectModel&) tempObj;
	rewind(stdin);
	cout << "������� ���� �������: ";
	tempObj.projectTopic = tryThis.inputString();
	rewind(stdin);
	cout << "������� ���� ������ ������� (��.��.����): ";
	tempObj.projectStartDate = tryThis.inputDate();
	rewind(stdin);
	cout << "������� ���� ��������� ������� (��.��.����): ";
	tempObj.projectDeadlineDate = tryThis.inputDate();
	rewind(stdin);
	cout << "������� �������� �������: ";
	tempObj.projectDescription = tryThis.inputString();
	rewind(stdin);
	cout << "������� ����������� �������: ";
	tempObj.projectExecutor = tryThis.inputString();
	return is;
}


//output override

std::ostream& operator << (std::ostream& os, cProject& tempObj)
{
	os << (cProjectModel&) tempObj;

	os << setiosflags(ios::left) << setw(20) << tempObj.projectTopic
		<< setw(13) << tempObj.projectStartDate << setw(13) << tempObj.projectDeadlineDate
		<< setw(30) << tempObj.projectDescription << setw(20) << tempObj.projectExecutor;


	return os;
}
