#pragma once
#include "Lib.h"
#include "WorkDB.h"


class Menu
{
	int size;
	string* arr;

public:
	Menu() 
	{
		size = 7;
		arr = new string[size];
		arr[0] = "  Delete from tb";
		arr[1] = "  Add to tb";
		arr[2] = "  Menu 3";
		arr[3] = "  Menu 4";
		arr[4] = "  Menu 5";
		arr[5] = "  Menu 6";
		arr[6] = "  Menu 7";
	};
	void menu(WorkDB wDb);
	~Menu();
};

