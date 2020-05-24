#include <iostream>
#include <Windows.h>
using namespace std;
int board[20][10];
int bloktest[5][5] =
{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
};
int main()
{
	int x;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		int licznik = i;
		cin >> x;

		if (x == 1)
		{
			system("cls");
			if (licznik <= 15)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						board[i + licznik][j] = bloktest[i][j];
					}
				}
			}
		}
			
		if (x == 2)
		{
			system("cls");
			if (licznik <= 5)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						board[i][j + licznik] = bloktest[i][j];
					}
				}

			}
	    
		}
			
		{
		for (int i = 0; i < 20; i++)
			{
				if (i == 19)
				{
					for (int j = 0; j < 10; j++)
					{
						cout << board[i][j];
					}
					break;
				}
				for (int j = 0; j < 10; j++)
				{
					if (j == 0 || j == 9 || board[i][j] == 1)
					{
						cout << board[i][j];
					}
					else
					{
						cout << " ";
					}
				}
				cout << endl;
			}
			
		}
	}
	
	
	
	
	return 0;
}