#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#define KEY_DOWN(vk_code) GetAsyncKeyState(vk_code)&0x8000?1:0
using namespace std;
enum
{
	e_Map_Floor,
	e_Map_wall,
	e_Map_Block,
};
struct SData
{
	int nRow;
	int nCol;
	int nColBK;
	int nRowBK;
};
SData g_arrPlayer[4];
vector<SData> g_vecBullet;
int g_nBlockRowCout = 3;
int g_nTime = 0;
int n_time = 100; 
int g_nscore = 0;
int g_arrMap[25][20]
{
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};
int main()
{
	g_arrPlayer[0].nRow = 22;
	g_arrPlayer[0].nCol = 7;
	for (int i = 1; i < 4; i++)
	{
		g_arrPlayer[i].nRow = 23;
		g_arrPlayer[i].nCol = 5 + i;
	}
	while (true)
	{
		n_time--;
		system("cls");
		for (int i = 0; i < 4; i++)
		{

			g_arrPlayer[i].nRowBK = g_arrPlayer[i].nRow;
			g_arrPlayer[i].nColBK = g_arrPlayer[i].nCol;
		}
		
		if (KEY_DOWN(VK_UP))
		{
			for (int i = 0; i < 4; i++)
			{
				g_arrPlayer[i].nRow--;
			}
		}
		else if (KEY_DOWN(VK_DOWN))
		{
			for (int i = 0; i < 4; i++)
			{
				g_arrPlayer[i].nRow++;
			}
		}
		else if (KEY_DOWN(VK_RIGHT))
		{
			for (int i = 0; i < 4; i++)
			{
				g_arrPlayer[i].nCol++;

			}
		}
		else if (KEY_DOWN(VK_LEFT))
		{
			for (int i = 0; i < 4; i++)
			{
				g_arrPlayer[i].nCol--;
			}
		}

		if (KEY_DOWN(VK_SPACE))
		{
			
			SData sbullet;
			sbullet.nRow = g_arrPlayer[0].nRow;
			sbullet.nCol = g_arrPlayer[0].nCol;
			g_vecBullet.push_back(sbullet);
		}
		for (int i = 0; i < g_vecBullet.size(); i++)
		{
			g_vecBullet[i].nRow--;
		}
		
		for (int i = 0; i < g_vecBullet.size(); i++)
		{
			if (g_vecBullet[i].nRow <= 0)
			{
				g_vecBullet[i].nRow = 0;
			}
		}
		
		for (int i = 0; i < g_vecBullet.size(); i++)
		{
			if (e_Map_Block == g_arrMap[g_vecBullet[i].nRow][g_vecBullet[i].nCol])
			{
				g_arrMap[g_vecBullet[i].nRow][g_vecBullet[i].nCol] = e_Map_Floor;
				g_vecBullet[i].nRow = 0;
				g_vecBullet[i].nCol = 0;
				g_nscore += 1;
			}
		}


		


		for (int i = 0; i < 4; i++)
		{
			if (e_Map_wall == g_arrMap[g_arrPlayer[0].nRow][g_arrPlayer[0].nCol] || e_Map_Block == g_arrMap[g_arrPlayer[0].nRow][g_arrPlayer[0].nCol])
			{
				for (int i = 0; i < 4; i++)
				{
					g_arrPlayer[i].nRow = g_arrPlayer[i].nRowBK;
					g_arrPlayer[i].nCol = g_arrPlayer[i].nColBK;
				}
				break;
			}

		}

		
		g_nTime++;
		if (g_nTime >= 10)
		{
			g_nTime = 0;
			for (int i = g_nBlockRowCout; i >= 1; i--)
			{
				for (int j = 1; j < 19; j++)
				{
					g_arrMap[i + 1][j] = g_arrMap[i][j];
				}
			}
			for (int j = 1; j < 19; j++)
			{
				g_arrMap[1][j] = e_Map_Block;
			}
			g_nBlockRowCout++;
			if (g_nBlockRowCout >= 21)
			{
				g_nBlockRowCout = 20;
			}
		}



		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				bool bDrawPlayer = false;
				for (int m = 0; m < 4; m++)
				{
					if (g_arrPlayer[m].nRow == i && g_arrPlayer[m].nCol == j)
					{
						bDrawPlayer = true;
						break;
					}
				}
				bool bDrawBullet = false;
				for (int m = 0; m < g_vecBullet.size(); m++)
				{
					if (i == g_vecBullet[m].nRow && g_vecBullet[m].nCol == j)
					{
						bDrawBullet = true;
						break;
					}
				}




				if (e_Map_wall == g_arrMap[i][j])
				{
					cout << "■";
				}
				else if (e_Map_Block == g_arrMap[i][j])
				{
					cout << "□";
				}

				else if (bDrawPlayer)
				{
					cout << "■";
				}
				else if (bDrawBullet)
				{
					cout << "射";
				}
				else
				{
					cout << "  ";
				}

			}
			if (1 == i)
			{
				cout << "得分情况:" << g_nscore;
			}
			if (2 == i)
			{
				cout << "倒计时:" << n_time;
			}
			if (3 == i)
			{

				for (int i = 0; i < n_time / 10; i++)
				{

					cout << "*";

				}
			}

			cout << endl;
		}
	}
	return 0;
}