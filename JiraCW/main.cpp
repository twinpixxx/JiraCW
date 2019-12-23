#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cProject.h"
#include "cProjectWithDeadline.h"
#include "cProjectWithPriority.h"
#include "cProjectWithPriorityAndDeadline.h"
#include "cInternationalProject.h"
#include "cInternationalProjectWithPriority.h"
#include "cInternationalProjectWithDeadline.h"
#include "cInternationalProjectWithDeadlineAndPriority.h"
#include <fstream>
#include "cList.h"
#include "cFile.h"
#include "cException.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>


using namespace std;


int main() {
	//	Add russian locale
	setlocale(LC_ALL, "Russian");
	system("color F0"); //	Color of console window

	//	Get console window and some size/console settings
	HWND consoleWindow = GetForegroundWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect);
	MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1700, 720, TRUE);
	//EnableWindow(consoleWindow, false); // Prevent closing window



	//	implement input exceptions
	inputExceptions inputException;

	// lists
	List<cInternationalProject> InternationalProjectsList;
	List<cInternationalProjectWithPriority> InternationalProjectsWithPriorityList;
	List<cInternationalProjectWithDeadline> InternationalProjectsWithDeadlineList;
	List<cInternationalProjectWithDeadlineAndPriority> InternationalProjectsWithDeadlineAndPriorityList;

	// files
	File<cInternationalProject> InternationalProjectsFile;
	File<cInternationalProjectWithPriority> InternationalProjectsWithPriorityFile;
	File<cInternationalProjectWithDeadline> InternationalProjectsWithDeadlineFile;
	File<cInternationalProjectWithDeadlineAndPriority> InternationalProjectsWithDeadlineAndPriorityFile;

	InternationalProjectsFile.openInternationalProjectsFile(InternationalProjectsList, "InternationalProjectsFile.txt");
	InternationalProjectsWithPriorityFile.openInternationalProjectsWithPriorityFile(InternationalProjectsWithPriorityList, "InternationalProjectsWithPriorityFile.txt");
	InternationalProjectsWithDeadlineFile.openInternationalProjectsWithDeadlineFile(InternationalProjectsWithDeadlineList, "InternationalProjectsWithDeadlineFile.txt");
	InternationalProjectsWithDeadlineAndPriorityFile.openInternationalProjectsWithDeadlineAndPriorityFile(InternationalProjectsWithDeadlineAndPriorityList, "InternationalProjectsWithDeadlineAndPriorityFile.txt");




	//	current project is the last project in a list 
	vector<std::string> projectTitles;
	if (InternationalProjectsList.size() > 0) {
		projectTitles.push_back(InternationalProjectsList[InternationalProjectsList.size()].getProjectTitle());

	}
	else if (InternationalProjectsWithPriorityList.size() > 0) {
		projectTitles.push_back(InternationalProjectsWithPriorityList[InternationalProjectsWithPriorityList.size()].getProjectTitle());
	}
	else if (InternationalProjectsWithDeadlineList.size() > 0) {
		projectTitles.push_back(InternationalProjectsWithDeadlineList[InternationalProjectsWithDeadlineList.size()].getProjectTitle());
	}
	else if (InternationalProjectsWithDeadlineList.size() > 0) {
		projectTitles.push_back(InternationalProjectsWithDeadlineList[InternationalProjectsWithDeadlineList.size()].getProjectTitle());
	}
	else if (InternationalProjectsWithDeadlineAndPriorityList.size() > 0) {
		projectTitles.push_back(InternationalProjectsWithDeadlineAndPriorityList[InternationalProjectsWithDeadlineAndPriorityList.size()].getProjectTitle());
	}

	//	revert last action
	//	doesn't work after program reload
	vector<cInternationalProject> InternationalProjectActionRevert;
	vector<cInternationalProjectWithPriority> InternationalProjectWithPriorityActionRevert;
	vector<cInternationalProjectWithDeadline> InternationalProjectWithDeadlineActionRevert;
	vector<cInternationalProjectWithDeadlineAndPriority> InternationalProjectWithDeadlineAndPriorityActionRevert;
	vector<int> actionRevertIndexIntPr;
	vector<int> objRevertIndexIntPr;
	vector<int> actionRevertIndexIntPrWPr;
	vector<int> objRevertIndexIntPrWPr;
	vector<int> actionRevertIndexIntPrWDl;
	vector<int> objRevertIndexIntPrWDl;
	vector<int> actionRevertIndexIntPrWDlAndPr;
	vector<int> objRevertIndexIntPrWDlAndPr;

	// main program loop
	while (true)
	{
		system("cls");
		std::cout << "JiraCW (MIT License)" << std::endl;
		cout << "Выберите действие, которое хотите совершить:" << std::endl
			<< "1. Добавить проект." << std::endl
			<< "2. Посмотреть список проектов." << std::endl
			<< "3. Удалить проект." << std::endl
			<< "4. Изменить проект." << std::endl
			<< "5. Поиск по проектам." << std::endl
			<< "6. Отмена предыдущего действия." << std::endl
			<< "0. Выход из программы." << std::endl << std::endl
			<< "Ваше действие: ";
		switch (_getch())
		{
		case '1':
		{
			system("cls");
			int menu;
			cout << "Какой проект вы хотите добавить?" << std::endl
				<< "1. Международный проект." << std::endl
				<< "2. Международный проект с приоритетом." << std::endl
				<< "3. Лимитированный по времени международный проект." << std::endl
				<< "4. Лимитированный по времени международный проект с приоритетом." << std::endl;
			cout << "Ваше действие (1-4): ";
			rewind(stdin);
			menu = inputException.inputNumber(1, 4);
			if (menu == 1)
			{
				cInternationalProject project;
				cin >> project;
				InternationalProjectsList.push_head(project);
				InternationalProjectActionRevert.insert(InternationalProjectActionRevert.end(), project);
				actionRevertIndexIntPr.insert(actionRevertIndexIntPr.end(), 1);
				system("pause");
			}
			if (menu == 2)
			{
				cInternationalProjectWithPriority project;
				cin >> project;
				InternationalProjectsWithPriorityList.push_head(project);
				InternationalProjectWithPriorityActionRevert.insert(InternationalProjectWithPriorityActionRevert.end(), project);
				actionRevertIndexIntPrWPr.insert(actionRevertIndexIntPrWPr.end(), 1);
				system("pause");
			}
			if (menu == 3)
			{
				cInternationalProjectWithDeadline project;
				cin >> project;
				InternationalProjectsWithDeadlineList.push_head(project);
				InternationalProjectWithDeadlineActionRevert.insert(InternationalProjectWithDeadlineActionRevert.end(), project);
				actionRevertIndexIntPrWDl.insert(actionRevertIndexIntPrWDl.end(), 1);
				system("pause");
			}
			if (menu == 4)
			{
				cInternationalProjectWithDeadlineAndPriority project;
				cin >> project;
				InternationalProjectsWithDeadlineAndPriorityList.push_head(project);
				InternationalProjectWithDeadlineAndPriorityActionRevert.insert(InternationalProjectWithDeadlineAndPriorityActionRevert.end(), project);
				actionRevertIndexIntPrWDlAndPr.insert(actionRevertIndexIntPrWDlAndPr.end(), 1);
				system("pause");
			}
			break;
		}
		case '2':
		{
			system("cls");
			if (InternationalProjectsList.size() > 0)
			{
				cout << "Список интернациональных проектов: " << endl;
				cout << setiosflags(ios::left) << setw(3) << " " << setw(25) << "Название" << setw(60) << "Исполнитель"
					<< setw(20) << "Страна" << endl;
				InternationalProjectsList.output();
				cout << endl;
			}
			else {
				cout << "Список интернациональных проектов пуст!" << endl;
			}
			cout << endl;
			if (InternationalProjectsWithPriorityList.size() > 0)
			{
				cout << "Список интернациональных проектов с приоритетом: " << endl;
				cout << setiosflags(ios::left) << setw(3) << " " << setw(25) << "Название" << setw(60) << "Исполнитель"
					<< setw(20) << "Страна" << setw(20) << "Приоритет" << endl;
				InternationalProjectsWithPriorityList.output();
				cout << endl;
			}
			else {
				cout << "Список интернациональных проектов с приоритетом пуст!" << endl;
			}
			cout << endl;
			if (InternationalProjectsWithDeadlineList.size() > 0)
			{
				cout << "Список лимитированных по времени интернациональных проектов: " << endl;
				cout << setiosflags(ios::left) << setw(3) << " " << setw(25) << "Название" << setw(60) << "Исполнитель"
					<< setw(20) << "Страна" << setw(30) << "Дата начала" << setw(35)
					<< "Дата окончания" << endl;
				InternationalProjectsWithDeadlineList.output();
				cout << endl;
			}
			else {
				cout << "Список лимитированных по времени интернациональных проектов пуст!" << endl;
			}
			cout << endl;
			if (InternationalProjectsWithDeadlineAndPriorityList.size() > 0)
			{
				cout << "Список лимитированных по времени интернациональных проектов с приоритетом: " << endl;
				cout << setiosflags(ios::left) << setw(3) << " " << setw(25) << "Название" << setw(60) << "Исполнитель"
					<< setw(20) << "Страна" << setw(30) << "Дата начала" << setw(35)
					<< "Дата окончания" << setw(20) << "Приоритет" << endl;
				InternationalProjectsWithDeadlineAndPriorityList.output();
				cout << endl;
			}
			else {
				cout << "Список лимитированных по времени интернациональных проектов с приоритетом пуст!" << endl;
			}
			cout << endl;
			system("pause");
			break;
		}
		case '3':
		{
			int menu;
			system("cls");
			cout << "Какой проект вы хотите удалить?" << std::endl
				<< "1. Международный проект." << std::endl
				<< "2. Международный проект с приоритетом." << std::endl
				<< "3. Лимитированный по времени международный проект." << std::endl
				<< "4. Лимитированный по времени международный проект с приоритетом." << std::endl;
			rewind(stdin);
			cout << "Ваше действие (1-4): ";
			menu = inputException.inputNumber(1, 4);
			if (menu == 1)
			{
				if (InternationalProjectsList.size() == 1)
				{
					cInternationalProject tmpObj = InternationalProjectsList[InternationalProjectsList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectActionRevert.insert(InternationalProjectActionRevert.end(), tmpObj);
					actionRevertIndexIntPr.insert(actionRevertIndexIntPr.end(), 2);
					InternationalProjectsList.popFromTAIL();
					cout << "Проект " << tempTitle << " успешно удален." << endl;
				}
				if (InternationalProjectsList.size() > 1)
				{
					cInternationalProject tmpObj = InternationalProjectsList[InternationalProjectsList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectActionRevert.insert(InternationalProjectActionRevert.end(), tmpObj);
					actionRevertIndexIntPr.insert(actionRevertIndexIntPr.end(), 2);
					InternationalProjectsList.popFromTAIL();
					cout << "Проект " << tempTitle << " успешно удален" << endl;
				}
				system("pause");
			}
			if (menu == 2)
			{
				if (InternationalProjectsList.size() == 1)
				{
					cInternationalProjectWithPriority tmpObj = InternationalProjectsWithPriorityList[InternationalProjectsWithPriorityList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithPriorityActionRevert.insert(InternationalProjectWithPriorityActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWPr.insert(actionRevertIndexIntPrWPr.end(), 2);
					InternationalProjectsWithPriorityList.pop_head();
					cout << "Проект " << tempTitle << " успешно удален." << endl;
				}
				if (InternationalProjectsList.size() > 1)
				{
					cInternationalProjectWithPriority tmpObj = InternationalProjectsWithPriorityList[InternationalProjectsWithPriorityList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithPriorityActionRevert.insert(InternationalProjectWithPriorityActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWPr.insert(actionRevertIndexIntPrWPr.end(), 2);
					InternationalProjectsWithPriorityList.popFromTAIL();
					cout << "Проект " << tempTitle << " успешно удален" << endl;
				}
				system("pause");
			}
			if (menu == 3)
			{
				if (InternationalProjectsWithDeadlineList.size() == 1)
				{
					cInternationalProjectWithDeadline tmpObj = InternationalProjectsWithDeadlineList[InternationalProjectsWithDeadlineList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithDeadlineActionRevert.insert(InternationalProjectWithDeadlineActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWDl.insert(actionRevertIndexIntPrWDl.end(), 2);
					InternationalProjectsWithDeadlineList.pop_head();
					cout << "Проект " << tempTitle << " успешно удален." << endl;
				}
				if (InternationalProjectsWithDeadlineList.size() > 1)
				{
					cInternationalProjectWithDeadline tmpObj = InternationalProjectsWithDeadlineList[InternationalProjectsWithDeadlineList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithDeadlineActionRevert.insert(InternationalProjectWithDeadlineActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWDl.insert(actionRevertIndexIntPrWDl.end(), 2);
					InternationalProjectsWithDeadlineList.popFromTAIL();
					cout << "Проект " << tempTitle << " успешно удален" << endl;
				}
				system("pause");
			}
			if (menu == 4)
			{
				if (InternationalProjectsWithDeadlineAndPriorityList.size() == 1)
				{
					cInternationalProjectWithDeadlineAndPriority tmpObj = InternationalProjectsWithDeadlineAndPriorityList[InternationalProjectsWithDeadlineAndPriorityList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithDeadlineAndPriorityActionRevert.insert(InternationalProjectWithDeadlineAndPriorityActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWDlAndPr.insert(actionRevertIndexIntPrWDlAndPr.end(), 2);
					InternationalProjectsWithDeadlineAndPriorityList.pop_head();
					cout << "Проект " << tempTitle << " успешно удален." << endl;
				}
				if (InternationalProjectsWithDeadlineAndPriorityList.size() > 1)
				{
					cInternationalProjectWithDeadlineAndPriority tmpObj = InternationalProjectsWithDeadlineAndPriorityList[InternationalProjectsWithDeadlineAndPriorityList.size()];
					std::string tempTitle = tmpObj.getProjectTitle();
					InternationalProjectWithDeadlineAndPriorityActionRevert.insert(InternationalProjectWithDeadlineAndPriorityActionRevert.end(), tmpObj);
					actionRevertIndexIntPrWDlAndPr.insert(actionRevertIndexIntPrWDlAndPr.end(), 2);
					InternationalProjectsWithDeadlineAndPriorityList.popFromTAIL();
					cout << "Проект " << tempTitle << " успешно удален" << endl;

				}
				system("pause");
			}
			break;
		}
		case '4':
		{
			int menu;
			system("cls");
			cout << "Какой проект вы хотите изменить?" << std::endl
				<< "1. Международный проект." << std::endl
				<< "2. Международный проект с приоритетом." << std::endl
				<< "3. Лимитированный по времени международный проект." << std::endl
				<< "4. Лимитированный по времени международный проект с приоритетом." << std::endl;
			cout << "Ваше действие (1-4): ";
			rewind(stdin);
			menu = inputException.inputNumber(1, 4);
			if (menu == 1 && InternationalProjectsList.size() > 0)
			{
				cout << "Введите номер изменяемого проекта: ";
				int tempNumber = inputException.inputNumber(1, InternationalProjectsList.size());
				cInternationalProject tmpObj;
				cin >> tmpObj;
				std::string tempTitle = InternationalProjectsList[tempNumber - 1].getProjectTitle();
				InternationalProjectActionRevert.insert(InternationalProjectActionRevert.end(), InternationalProjectsList[tempNumber - 1]);
				actionRevertIndexIntPr.insert(actionRevertIndexIntPr.end(), 3);
				objRevertIndexIntPr.insert(objRevertIndexIntPr.end(), (tempNumber - 1));
				InternationalProjectsList[tempNumber - 1] = tmpObj;
				cout << "Проект " << tempTitle << " успешно изменен." << endl;
				system("pause");
			}
			else {
				cout << "Не найдено проектов такого типа. Добавьте проект!" << endl;
				system("pause");
				break;
			}
			if (menu == 2 && InternationalProjectsWithPriorityList.size() > 0)
			{
				cout << "Введите номер изменяемого проекта: ";
				int tempNumber = inputException.inputNumber(1, InternationalProjectsWithPriorityList.size());
				cInternationalProjectWithPriority tmpObj;
				cin >> tmpObj;
				std::string tempTitle = InternationalProjectsWithPriorityList[tempNumber - 1].getProjectTitle();
				InternationalProjectWithPriorityActionRevert.insert(InternationalProjectWithPriorityActionRevert.end(), InternationalProjectsWithPriorityList[tempNumber - 1]);
				actionRevertIndexIntPrWPr.insert(actionRevertIndexIntPrWPr.end(), 3);
				objRevertIndexIntPrWPr.insert(objRevertIndexIntPrWPr.end(), (tempNumber - 1));
				InternationalProjectsWithPriorityList[tempNumber - 1] = tmpObj;
				cout << "Проект " << tempTitle << " успешно изменен." << endl;
				system("pause");
			}
			else {
				cout << "Не найдено проектов такого типа. Добавьте проект!" << endl;
				system("pause");
				break;
			}
			if (menu == 3 && InternationalProjectsWithDeadlineList.size() > 0)
			{
				cout << "Введите номер изменяемого проекта: ";
				int tempNumber = inputException.inputNumber(1, InternationalProjectsWithDeadlineList.size());
				cInternationalProjectWithDeadline tmpObj;
				cin >> tmpObj;
				std::string tempTitle = InternationalProjectsWithDeadlineList[tempNumber - 1].getProjectTitle();
				InternationalProjectWithDeadlineActionRevert.insert(InternationalProjectWithDeadlineActionRevert.end(), InternationalProjectsWithDeadlineList[tempNumber - 1]);
				actionRevertIndexIntPrWDl.insert(actionRevertIndexIntPrWDl.end(), 3);
				objRevertIndexIntPrWDl.insert(objRevertIndexIntPrWDl.end(), (tempNumber - 1));
				InternationalProjectsWithDeadlineList[tempNumber - 1] = tmpObj;
				cout << "Проект " << tempTitle << " успешно изменен" << endl;
				system("pause");
			}
			else {
				cout << "Не найдено проектов такого типа. Добавьте проект!" << endl;
				system("pause");
				break;
			}
			if (menu == 4 && InternationalProjectsWithDeadlineAndPriorityList.size() > 0)
			{
				cout << "Введите номер изменяемого проекта: ";
				int tempNumber = inputException.inputNumber(1, InternationalProjectsWithDeadlineAndPriorityList.size());
				cInternationalProjectWithDeadlineAndPriority tmpObj;
				cin >> tmpObj;
				std::string tempTitle = InternationalProjectsWithDeadlineAndPriorityList[tempNumber - 1].getProjectTitle();
				InternationalProjectWithDeadlineAndPriorityActionRevert.insert(InternationalProjectWithDeadlineAndPriorityActionRevert.end(), InternationalProjectsWithDeadlineAndPriorityList[tempNumber - 1]);
				actionRevertIndexIntPrWDlAndPr.insert(actionRevertIndexIntPrWDlAndPr.end(), 3);
				objRevertIndexIntPrWDlAndPr.insert(objRevertIndexIntPrWDlAndPr.end(), (tempNumber - 1));
				InternationalProjectsWithDeadlineAndPriorityList[tempNumber - 1] = tmpObj;
				cout << "Проект " << tempTitle << " успешно изменен" << endl;
				system("pause");
			}
			else {
				cout << "Не найдено проектов такого типа. Добавьте проект!" << endl;
				system("pause");
				break;
			}
			break;
		}
		case '5':
		{
			int menu;
			system("cls");
			cout << "По какому проекту вы хотите совершить поиск?" << std::endl
				<< "1. Международный проект." << std::endl
				<< "2. Международный проект с приоритетом." << std::endl
				<< "3. Лимитированный по времени международный проект." << std::endl
				<< "4. Лимитированный по времени международный проект с приоритетом." << std::endl;
			cout << "Ваше действие (1-4): ";
			rewind(stdin);
			menu = inputException.inputNumber(1, 4);
			if (menu == 1)
			{
				cout << "1. Название" << endl;
				cout << "2. Исполнитель" << endl;
				cout << "Выберите критерий для поиска: ";
				int tempType = inputException.inputNumber(1, 3);
				system("cls");
				if (tempType == 1)
				{
					cout << "Введите название проекта для поиска: ";
					std::string projectName = inputException.inputString();
					cout << endl;
					InternationalProjectsList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "Введите имя исполнителя проекта для поиска: ";
					std::string projectExecName = inputException.inputString();
					cout << endl;
					InternationalProjectsList.outputByExec(projectExecName);
				}
				system("pause");
			}
			if (menu == 2)
			{
				cout << "1. Название" << endl;
				cout << "2. Приоритет" << endl;
				cout << "3. Исполнитель" << endl;
				cout << "Выберите критерий для поиска: ";
				int tempType = inputException.inputNumber(1, 3);
				system("cls");
				if (tempType == 1)
				{
					cout << "Введите название проекта для поиска: ";
					std::string projectName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithPriorityList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "Введите приоритет проекта для поиска: ";
					int projectPriority = inputException.inputNumber(0, 3);
					cout << endl;
					InternationalProjectsWithPriorityList.outputByPriority(projectPriority);
				}
				else if (tempType == 3) {
					cout << "Введите имя исполнителя проекта для поиска: ";
					std::string projectExecName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithPriorityList.outputByExec(projectExecName);
				}
				system("pause");
			}
			if (menu == 3)
			{
				cout << "1. Название" << endl;
				cout << "2. Исполнитель" << endl;
				cout << "Выберите критерий для поиска: ";
				int tempType = inputException.inputNumber(1, 3);
				system("cls");
				if (tempType == 1)
				{
					cout << "Введите название проекта для поиска: ";
					std::string projectName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithDeadlineList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "Введите имя исполнителя проекта для поиска: ";
					std::string projectExecName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithDeadlineList.outputByExec(projectExecName);
				}
				system("pause");
			}
			if (menu == 4)
			{
				cout << "1. Название" << endl;
				cout << "2. Приоритет" << endl;
				cout << "3. Исполнитель" << endl;
				cout << "Выберите критерий для поиска: ";
				int tempType = inputException.inputNumber(1, 3);
				system("cls");
				if (tempType == 1)
				{
					cout << "Введите название проекта для поиска: ";
					std::string projectName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithDeadlineAndPriorityList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "Введите приоритет проекта для поиска: ";
					int projectPriority = inputException.inputNumber(0, 3);
					cout << endl;
					InternationalProjectsWithDeadlineAndPriorityList.outputByPriority(projectPriority);
				}
				else if (tempType == 3) {
					cout << "Введите имя исполнителя проекта для поиска: ";
					std::string projectExecName = inputException.inputString();
					cout << endl;
					InternationalProjectsWithDeadlineAndPriorityList.outputByExec(projectExecName);
				}
				system("pause");
			}
			break;
		}
		case '6':
		{
			int menu;
			system("cls");
			cout << "По какому проекту вы хотите совершить поиск?" << std::endl
				<< "1. Международный проект." << std::endl
				<< "2. Международный проект с приоритетом." << std::endl
				<< "3. Лимитированный по времени международный проект." << std::endl
				<< "4. Лимитированный по времени международный проект с приоритетом." << std::endl;
			cout << "Ваше действие (1-4): ";
			rewind(stdin);
			menu = inputException.inputNumber(1, 4);
			switch (menu)
			{
			case 1:
			{
				if (actionRevertIndexIntPr.back() == 1)
				{
					InternationalProjectsList.popFromTAIL();
					actionRevertIndexIntPr.erase(actionRevertIndexIntPr.end() - 1);
					InternationalProjectActionRevert.erase(InternationalProjectActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPr.back() == 2)
				{
					InternationalProjectsList.pushToTAIL(InternationalProjectActionRevert.back());
					actionRevertIndexIntPr.erase(actionRevertIndexIntPr.end() - 1);
					InternationalProjectActionRevert.erase(InternationalProjectActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPr.back() == 3)
				{
					InternationalProjectsList.delete_element(objRevertIndexIntPr.back());
					InternationalProjectsList.pushToTAIL(InternationalProjectActionRevert.back());
					actionRevertIndexIntPr.erase(actionRevertIndexIntPr.end() - 1);
					InternationalProjectActionRevert.erase(InternationalProjectActionRevert.end() - 1);
					objRevertIndexIntPr.erase(objRevertIndexIntPr.end() - 1);
				}
				break;
			}
			case 2:
			{
				if (actionRevertIndexIntPrWPr.back() == 1)
				{
					InternationalProjectsWithPriorityList.popFromTAIL();
					actionRevertIndexIntPrWPr.erase(actionRevertIndexIntPrWPr.end() - 1);
					InternationalProjectWithPriorityActionRevert.erase(InternationalProjectWithPriorityActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWPr.back() == 2)
				{
					InternationalProjectsWithPriorityList.pushToTAIL(InternationalProjectWithPriorityActionRevert.back());
					actionRevertIndexIntPrWPr.erase(actionRevertIndexIntPrWPr.end() - 1);
					InternationalProjectWithPriorityActionRevert.erase(InternationalProjectWithPriorityActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWPr.back() == 3)
				{
					InternationalProjectsWithPriorityList.delete_element(objRevertIndexIntPrWPr.back());
					InternationalProjectsWithPriorityList.pushToTAIL(InternationalProjectWithPriorityActionRevert.back());
					actionRevertIndexIntPrWPr.erase(actionRevertIndexIntPrWPr.end() - 1);
					InternationalProjectWithPriorityActionRevert.erase(InternationalProjectWithPriorityActionRevert.end() - 1);
					objRevertIndexIntPrWPr.erase(objRevertIndexIntPrWPr.end() - 1);
				}
				break;
			}
			case 3:
			{
				if (actionRevertIndexIntPrWDl.back() == 1)
				{
					InternationalProjectsWithDeadlineList.popFromTAIL();
					actionRevertIndexIntPrWDl.erase(actionRevertIndexIntPrWDl.end() - 1);
					InternationalProjectWithDeadlineActionRevert.erase(InternationalProjectWithDeadlineActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWDl.back() == 2)
				{
					InternationalProjectsWithDeadlineList.pushToTAIL(InternationalProjectWithDeadlineActionRevert.back());
					actionRevertIndexIntPrWDl.erase(actionRevertIndexIntPrWDl.end() - 1);
					InternationalProjectWithDeadlineActionRevert.erase(InternationalProjectWithDeadlineActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWDl.back() == 3)
				{
					InternationalProjectsWithDeadlineList.delete_element(objRevertIndexIntPrWDl.back());
					InternationalProjectsWithDeadlineList.pushToTAIL(InternationalProjectWithDeadlineActionRevert.back());
					actionRevertIndexIntPrWDl.erase(actionRevertIndexIntPrWDl.end() - 1);
					InternationalProjectWithDeadlineActionRevert.erase(InternationalProjectWithDeadlineActionRevert.end() - 1);
					objRevertIndexIntPrWDl.erase(objRevertIndexIntPrWDl.end() - 1);
				}
				break;
			}
			case 4:
			{
				if (actionRevertIndexIntPrWDlAndPr.back() == 1)
				{
					InternationalProjectsWithDeadlineAndPriorityList.popFromTAIL();
					actionRevertIndexIntPrWDlAndPr.erase(actionRevertIndexIntPrWDlAndPr.end() - 1);
					InternationalProjectWithDeadlineAndPriorityActionRevert.erase(InternationalProjectWithDeadlineAndPriorityActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWDlAndPr.back() == 2)
				{
					InternationalProjectsWithDeadlineAndPriorityList.pushToTAIL(InternationalProjectWithDeadlineAndPriorityActionRevert.back());
					actionRevertIndexIntPrWDlAndPr.erase(actionRevertIndexIntPrWDlAndPr.end() - 1);
					InternationalProjectWithDeadlineAndPriorityActionRevert.erase(InternationalProjectWithDeadlineAndPriorityActionRevert.end() - 1);
				}
				if (actionRevertIndexIntPrWDlAndPr.back() == 3)
				{
					InternationalProjectsWithDeadlineAndPriorityList.delete_element(objRevertIndexIntPrWDlAndPr.back());
					InternationalProjectsWithDeadlineAndPriorityList.pushToTAIL(InternationalProjectWithDeadlineAndPriorityActionRevert.back());
					actionRevertIndexIntPrWDlAndPr.erase(actionRevertIndexIntPrWDlAndPr.end() - 1);
					InternationalProjectWithDeadlineAndPriorityActionRevert.erase(InternationalProjectWithDeadlineAndPriorityActionRevert.end() - 1);
					objRevertIndexIntPrWDlAndPr.erase(objRevertIndexIntPrWDlAndPr.end() - 1);
				}
				break;
			}
			}
		}
		case '0':
		{
			//	save info into files
			InternationalProjectsFile.saveInternationalProjectsFile(InternationalProjectsList, "InternationalProjectsFile.txt");
			InternationalProjectsWithPriorityFile.saveInternationalProjectsWithPriorityFile(InternationalProjectsWithPriorityList, "InternationalProjectsWithPriorityFile.txt");
			InternationalProjectsWithDeadlineFile.saveInternationalProjectsWithDeadlineFile(InternationalProjectsWithDeadlineList, "InternationalProjectsWithDeadlineFile.txt");
			InternationalProjectsWithDeadlineAndPriorityFile.saveInternationalProjectsWithDeadlineAndPriorityFile(InternationalProjectsWithDeadlineAndPriorityList, "InternationalProjectsWithDeadlineAndPriorityFile.txt");


			//	closes console window and terminate task
			PostMessage(consoleWindow, WM_CLOSE, 0, 0);
		}
		}
	}

	return 0;
}