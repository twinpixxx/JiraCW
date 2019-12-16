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


int main() {
	//	Add russian locale
	setlocale(LC_ALL, "Russian");
	system("color F0"); //	Color of console window

	//	Get console window and some size/console settings
	HWND consoleWindow = GetForegroundWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect);
	MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1700, 720, TRUE);

	//	Getting the desktop hadle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen = GetDesktopWindow();
	GetWindowRect(hwndScreen, &rectScreen);
	EnableWindow(consoleWindow, false);

	//	Get the current width and height of the console
	RECT rConsole;
	GetWindowRect(consoleWindow, &rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//	Caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(consoleWindow, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);




	return 0;
}