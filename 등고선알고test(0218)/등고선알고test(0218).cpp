// 등고선알고test(0218).cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// 등고선알고리즘
#include "stdafx.h"
	
int x = 0, y = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	char ch;

	int map[X][Y] = {       // 미로의모양
		{ 99, 99, 99, 99, 99, 99, 99 },
		{ 99, ST, 99, -1, 99, -1, 99 },
		{ 99, -1, 99, -1, 99, -1, 99 },
		{ 99, -1, 99, -1, -1, -1, 99 },
		{ 99, -1, 99, -1, 99, -1, 99 },
		{ 99, -1, -1, -1, 99, EN, 99 },
		{ 99, 99, 99, 99, 99, 99, 99 }
	};

	int arr[3] = { 1, 2, 3 };
	cout << arr[-1];

	//int map[X][Y] = {       // 미로의모양
	//	{ 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 },
	//	{ 99, START, 99, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 99, -1, -1, -1, 99 },
	//	{ 99, -1, 99, -1, 99, 99, 99, -1, 99, 99, 99, 99, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, 99, -1, -1, -1, 99, -1, -1, -1, -1, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, 99, 99, 99, -1, 99, 99, 99, 99, 99, 99, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, -1, -1, 99, -1, -1, -1, -1, -1, 99, -1, -1, -1, -1, -1, 99 },
	//	{ 99, -1, 99, 99, 99, -1, 99, -1, 99, 99, 99, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, -1, -1, -1, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, 99, 99, 99, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, -1, -1, -1, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, 99, 99, 99, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, -1, -1, -1, -1, -1, -1, 99, -1, -1, -1, 99, -1, 99, 99, 99, -1, 99 },
	//	{ 99, -1, 99, 99, 99, 99, 99, -1, 99, -1, 99, 99, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, -1, -1, -1, -1, 99, -1, -1, -1, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, 99, 99, 99, 99, 99, 99, 99, 99, 99, -1, 99, -1, 99, -1, 99 },
	//	{ 99, -1, 99, -1, 99, -1, -1, -1, -1, -1, -1, -1, -1, -1, 99, -1, -1, -1, 99 },
	//	{ 99, -1, 99, -1, 99, -1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, -1, 99 },
	//	{ 99, -1, 99, -1, -1, -1, 99, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, END, 99 },
	//	{ 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 }
	//};

	// 길찾기
	for (int step = 0; step < 100; step++)
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (map[i][j] == step)
				{
					if (map[i + 1][j] == -1)
						map[i + 1][j] = step + 1;
					if (map[i - 1][j] == -1)
						map[i - 1][j] = step + 1;
					if (map[i][j + 1] == -1)
						map[i][j + 1] = step + 1;
					if (map[i][j - 1] == -1)
						map[i][j - 1] = step + 1;
				}
			}
		}
	}

	// 현재위치저장
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (map[i][j] == ST)
			{
				x = i;
				y = j;
			}
		}
	}

	// 최단거리
	while (map[x][y] != EN)
	{
		if (map[x + 1][y] < map[x][y])
			x = x + 1;
		else if (map[x - 1][y] < map[x][y])
			x = x - 1;
		else if (map[x][y + 1] < map[x][y])
			y = y + 1;
		else
			y = y - 1;
		system("cls");
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (i == x && j == y)
					printf("■");
				else if (map[i][j] == 99)
					printf("□");
				else
					printf("  ");
			}
			printf("\n");
		}
		_sleep(50);
	}
	scanf("%c", &ch);


	return 0;
}

