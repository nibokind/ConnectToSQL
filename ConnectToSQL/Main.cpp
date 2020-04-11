#pragma once
#include "WorkDB.h"
#include "Menu.h"



int main() {

	int a;

	WorkDB db;

	Menu menu;

	menu.menu(db);

	system("pause");

	db.connectToDB();
	//while (true)
	//{
	//	db.query();
	//}
	

	do
	{
		cout << "1 - Delete" << endl;
		cout << "2 - Insert" << endl;
		cout << "3 - " << endl;
		cin >> a;

		db.query(a);
		system("cls");
	} while (a != 0);
	
	db.disconnectDB();
	system("pause");
}
