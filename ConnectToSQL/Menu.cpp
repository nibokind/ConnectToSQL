#include "Menu.h"
#include "Draw.h"


void Menu::menu(WorkDB wDb)
{
	char ch;
	int pos = 0;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	draw(pos * 16);
	while (true)
	{
		if (kbhit)
		{
			ch = getch();
			switch (ch)
			{
				case 119://вверх
					drawBl(pos * 16);
					if (pos == 0)
					{
						pos = size - 1;
					}
					else
					{
						pos--;
					}
					
					draw(pos * 16);
					break;
				case 115://вниз
					drawBl(pos * 16);
					
					if (pos == size - 1)
					{
						pos = 0;
					}
					else
					{
						pos++;
					}
					draw(pos * 16);
					break;
				case 102:
					wDb.query(pos + 1);
					break;
			}
		}

	}
}


Menu::~Menu()
{
}
