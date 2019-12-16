#include <iostream>
#include "cProject.h"
#include "cProjectWithDeadline.h"
#include "cProjectWithPriority.h"
#include "cProjectWithPriorityAndDeadline.h"
#include "cInternationalProject.h"
#include "cInternationalProjectWithPriority.h"
#include "cInternationalProjectWithDeadline.h"
#include "cInternationalProjectWithDeadlineAndPriority.h"
//#include "cList.h"
//#include "cFile.h"
#include "cException.h"
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <vector>


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
			cout << "��� ������� ������: " << currentProject << std::endl << std::endl;
		} else {
			cout << "� ��� ��� ������� ��������." << currentProject << std::endl << std::endl;
		}
			cout << "�������� ��������, ������� ������ ���������:" << std::endl
			<< "1. �������� ������" << std::endl
			<< "2. ���������� ������ ��������" << std::endl
			<< "3. ������� ������" << std::endl
			<< "4. �������� ������" << std::endl
			<< "5. ����� �� ��������" << std::endl
			<< "6. ������ ����������� ��������" << std::endl
			<< "7. �������� ���������" << std::endl
			<< "0. ����� �� ���������" << std::endl << std::endl
			<< "���� ��������: ";
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
					cout << setiosflags(ios::left) << setw(3) << "" << setw(20) << "��������" << setw(20) << "���������"
						<< setw(20) << "����" << setw(13) << "���� ������" << setw(13)
						<< "���� ���������" << setw(30) << "��������" << setw(20) << "�����������" << setw(20) << "������" << endl;
					cout << setiosflags(ios::left) << setw(3) << "" << setw(20) << "�������" << setw(20) << "�������"
						<< setw(20) << "�������" << setw(13) << "�������" << setw(13)
						<< "�������" << setw(30) << "�������" << setw(20) << "�������" << setw(20) << "�������" << endl;
					projectsList.output();
					cout << endl;
				}
				else {
					cout << "������ ����!" << endl;
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
					cout << "������ " << tempTitle << " ������� ������" << endl;
				}
				if (projectsList.size() > 1)
				{
					cInternationalProject tmpObj = projectsList[projectsList.size()];
					std::string tempTitle = tmpObj.getTitle();
					actionRevert.insert(actionRevert.end(), tmpObj);
					actionRevertIndex.insert(actionRevertIndex.end(), 2);
					projectsList.pop_tail();
					cout << "������ " << tempTitle << " ������� ������" << endl;
				}
				system("pause");
				break;
			}
			case '4':
			{
				system("cls");
				cout << "������� ����� ����������� �������: ";
				int tempNumber = inputException.inputNumber(1, projectsList.size());
				cInternationalProject tmpObj;
				cin >> tmpObj;
				std::string tempTitle = projectsList[tempNumber - 1].getTitle();
				actionRevert.insert(actionRevert.end(), projectsList[tempNumber - 1]);
				actionRevertIndex.insert(actionRevertIndex.end(), 3);
				objRevertIndex.insert(objRevertIndex.end(), (tempNumber - 1));
				projectsList[tempNumber - 1] = tmpObj;
				cout << "������ " << tempTitle << " ������� �������" << endl;
				system("pause");
				break;
			}
			case '5':		//�������� �� ���� ������
			{
				system("cls");
				cout << "1. ��������" << endl;
				cout << "2. ���������" << endl;
				cout << "3. �����������" << endl;
				cout << "�������� �������� ��� ������: ";
				int tempType = inputException.inputNumber(1, 3);
				system("cls");
				if (tempType == 1)
				{
					cout << "������� �������� ������� ��� ������: ";
					std::string projectName = inputException.inputString();
					cout << endl;
					projectsList.outputByName(projectName);
				}
				else if (tempType == 2) {
					cout << "������� ��������� ������� ��� ������: ";
					int projectPriority = inputException.inputNumber(0, 3);
					cout << endl;
					projectsList.outputByPriority(projectPriority);
				}
				else if (tempType == 3) {
					cout << "������� ��� ����������� ������� ��� ������: ";
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
