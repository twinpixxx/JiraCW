#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <vector>
#include "cProjectModel.h"
#include "cProject.h"
#include "cInternationalProject.h"
#include "cList.h"
#include "cFile.h"
#include "cException.h"


using namespace std;

int main()
{
	// add russian locale
	setlocale(LC_ALL, "Russian");
	
	//get console window and some size/console settings
	HWND consoleWindow = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect);
	MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1400, 720, TRUE);
	HWND preventClosing = GetForegroundWindow();	//prevent error console closing
	EnableWindow(preventClosing, false);

	//	implement input exceptions
	inputExceptions inputException;

	// lists
	List<cInternationalProject> projectsList;

	// files
	File<cInternationalProject> workFile;
	workFile.openFile(projectsList, "projectFile.txt");

	//	current project is the last project in a list
	std::string currentProject;
	if (projectsList.size() > 0) {
		currentProject = projectsList[projectsList.size()].getTitle();

	}

	//	revert last action
	//	doesn't work after program reload
	vector<cInternationalProject> actionRevert;
	vector<int> actionRevertIndex;
	vector<int> objRevertIndex;

	// main program loop
	while (true)
	{
		system("cls");
		std::cout << "JiraCW (MIT License)" << std::endl;
		if (currentProject.length() > 0) {
			cout << "Ваш текущий проект: " << currentProject << std::endl << std::endl;
		} else {
			cout << "У Вас нет текущих проектов." << currentProject << std::endl << std::endl;
		}
			cout << "Выберите действие, которое хотите совершить:" << std::endl
			<< "1. Добавить проект" << std::endl
			<< "2. Посмотреть список проектов" << std::endl
			<< "3. Удалить проект" << std::endl
			<< "4. Изменить проект" << std::endl
			<< "5. Поиск по проектам" << std::endl
			<< "6. Отмена предыдущего действия" << std::endl
			<< "7. Обновить состояние" << std::endl
			<< "0. Выход из программы" << std::endl << std::endl
			<< "Ваше действие: ";
		switch (_getch())
		{
			case '1':
				{
				cInternationalProject project;
				cin >> project;
				projectsList.push_head(project);
				cout << endl;
				actionRevert.insert(actionRevert.end(), project);
				actionRevertIndex.insert(actionRevertIndex.end(), 1);
				system("pause");
				break;
				}
			case '2':
				{
				system("cls");
				if (projectsList.size() > 0)
				{
					cout << setiosflags(ios::left) << setw(3) << "" << setw(20) << "Название" << setw(20) << "Приоритет"
						<< setw(20) << "Тема" << setw(13) << "Дата начала" << setw(13)
						<< "Дата окончания" << setw(30) << "Описание" << setw(20) << "Исполнитель" << setw(20) << "Страна" << endl;
					cout << setiosflags(ios::left) << setw(3) << "" << setw(20) << "проекта" << setw(20) << "проекта"
						<< setw(20) << "проекта" << setw(13) << "проекта" << setw(13)
						<< "проекта" << setw(30) << "проекта" << setw(20) << "проекта" << setw(20) << "проекта" << endl;
					projectsList.output();
					cout << endl;
				}
				else {
					cout << "Список пуст!" << endl;
				}
					system("pause");
					break;
				}
			case '3':
			{
				system("cls");
				if (projectsList.size() == 1)
				{
					cInternationalProject tmpObj = projectsList[projectsList.size()];
					std::string tempTitle = tmpObj.getTitle();
					actionRevert.insert(actionRevert.end(), tmpObj);
					actionRevertIndex.insert(actionRevertIndex.end(), 2);
					projectsList.pop_head();
					cout << "Проект " << tempTitle << " успешно удален" << endl;
				}
				if (projectsList.size() > 1)
				{
					cInternationalProject tmpObj = projectsList[projectsList.size()];
					std::string tempTitle = tmpObj.getTitle();
					actionRevert.insert(actionRevert.end(), tmpObj);
					actionRevertIndex.insert(actionRevertIndex.end(), 2);
					projectsList.pop_tail();
					cout << "Проект " << tempTitle << " успешно удален" << endl;
				}
				system("pause");
				break;
			}
			case '4':
			{
				system("cls");
				cout << "Введите номер изменяемого проекта: ";
				int tempNumber = inputException.inputNumber(1, projectsList.size());
				cInternationalProject tmpObj;
				cin >> tmpObj;
				std::string tempTitle = projectsList[tempNumber - 1].getTitle();
				actionRevert.insert(actionRevert.end(), projectsList[tempNumber - 1]);
				actionRevertIndex.insert(actionRevertIndex.end(), 3);
				objRevertIndex.insert(objRevertIndex.end(), (tempNumber - 1));
				projectsList[tempNumber - 1] = tmpObj;
				cout << "Проект " << tempTitle << " успешно изменен" << endl;
				system("pause");
				break;
			}
			case '5':		//Просмотр по типу дохода
			{
				system("cls");
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
					projectsList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "Введите приоритет проекта для поиска: ";
					int projectPriority = inputException.inputNumber(0, 3);
					cout << endl;
					projectsList.outputByPriority(projectPriority);
				}
				else if (tempType == 3) {
					cout << "Введите имя исполнителя проекта для поиска: ";
					std::string projectExecName = inputException.inputString();
					cout << endl;
					projectsList.outputByExec(projectExecName);
				}

				system("pause");
				break;
			}
			case '6':
			{
				if (actionRevertIndex.back() == 1)
				{
					projectsList.pop_tail();
					actionRevertIndex.erase(actionRevertIndex.end() - 1);
					actionRevert.erase(actionRevert.end() - 1);
				}
				if (actionRevertIndex.back() == 2)
				{
					projectsList.push_tail(actionRevert.back());
					actionRevertIndex.erase(actionRevertIndex.end() - 1);
					actionRevert.erase(actionRevert.end() - 1);
				}
				if (actionRevertIndex.back() == 3)
				{
					projectsList.delete_element(objRevertIndex.back());
					projectsList.push_tail(actionRevert.back());
					actionRevertIndex.erase(actionRevertIndex.end() - 1);
					actionRevert.erase(actionRevert.end() - 1);
				}
				break;
			}
			case '7':
			{
				if (projectsList.size() > 0) {
					currentProject = projectsList[projectsList.size()].getTitle();
				}
				else {
					currentProject = "";
				}
				break;
			}
			case '0':
				{
					//save info into file
					workFile.saveFile(projectsList, "projectFile.txt");
					//closes console window and terminate task
					PostMessage(consoleWindow, WM_CLOSE, 0, 0);
				}

		}
	}
}
