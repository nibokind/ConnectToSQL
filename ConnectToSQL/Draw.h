#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <clocale>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <time.h>


void draw(int y)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	COLORREF COLOR = RGB(0, 128, 128);

	int x = 3;

	for (int i = x; i < x + 10; i++)
	{
		for (int j = y + 3; j < y + 13; j++)
		{
			SetPixel(mydc, i, j, COLOR);
		}
	}
}

void drawBl(int y)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	COLORREF COLOR = RGB(0, 0, 0);

	int x = 3;

	for (int i = x; i < x + 10; i++)
	{
		for (int j = y + 3; j < y + 13; j++)
		{
			SetPixel(mydc, i, j, COLOR);
		}
	}
}