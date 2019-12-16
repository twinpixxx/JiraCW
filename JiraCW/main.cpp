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

	//	Getting the desktop hadle and rectangule
	HWND   hwndScreen;

	//	Get the current width and height of the console
	RECT rConsole;

	//	Caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;




	return 0;
}