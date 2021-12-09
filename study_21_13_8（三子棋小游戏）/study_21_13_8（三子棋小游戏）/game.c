#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("*********** 1.游戏开始 ***********\n");
	printf("*********** 0.游戏结束 ***********\n");
	printf("**********************************\n");
}

void game()
{
	char out;
	//存储游戏内部数据
	char board[ROW][COL];
	//初始化棋盘（空格）
	InBoard(board, ROW, COL);
	//打印棋盘
	PrintBoard(board, ROW, COL);
	while (1)
	{

		//玩家行动
		Player(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		//判断游戏是否结束
		out = Win(board, ROW, COL);
		if (out != 'G')
		{
			break;
		}
		//电脑行动
		PC(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		//判断游戏是否结束
		out = Win(board, ROW, COL);
		if (out != 'G')
		{
			break;
		}
	}
	//游戏结束判断胜负
	if (out == '*')
	{
		printf("玩家胜利\n");
	}
	else if (out == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}

void InBoard(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			board[a][b] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			printf(" %c ", board[a][b]);
			if (b < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (a < row - 1)
		{
			for (b = 0; b < col; b++)
			{
				printf("---");
				if (b < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void Player(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	printf("玩家行动\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &a, &b);
		//判断输入的坐标是否合法
		if (a >= 1 && a <= col && b >= 1 && b <= row)
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("输入的坐标内已有棋子，请重新输入\n");
			}
		}
		else
		{
			printf("坐标输入错误，请重新输入\n");
		}

	}
}

void PC(char board[ROW][COL], int row, int col)
{
	printf("电脑行动\n");
	while (1)
	{
		int a = rand() % row;
		int b = rand() % col;
		if (board[a][b] == ' ')
		{
			board[a][b] = '#';
			break;
		}
	}
}

int FULL(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			if (board[a][b] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;
}

char Win(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	char c;
	//判断一行
	for (a = 0; a < row; a++)
	{
		//if (board[a][0] == board[a][1] && board[a][1] == board[a][2] && board[a][1] != ' ')
		//{
		//	return board[a][1];
		//}
		for (b = 0; b < col - 1; b++)
		{
			if ((board[a][b] == board[a][b + 1] && board[a][b + 1] == ' ') || board[a][b] != board[a][b + 1])
			{
				break;
			}
			if (b == row - 2)
			{
				return board[a][b];
			}
		}
	}
	//判断一列
	for (b = 0; b < col; b++)
	{
		//if (board[0][a] == board[1][a] && board[1][a] == board[2][a] && board[1][a] != ' ')
		//{
		//	return board[1][a];
		//}
		for (a = 0; a < row - 1; a++)
		{
			if (board[a][b] == board[a + 1][b] && board[a + 1][b] == ' ' || board[a][b] != board[a + 1][b])
			{
				break;
			}
			if (a == row - 2)
			{
				return board[a][b];
			}
		}
	}
	//判断左上到右下对角线
	while (1)
	{
		for (a = 0; a < row-1; a++)
		{
			for (b = 0; b < col-1; b++)
			{
				if (a == b && board[a][b] != ' ')
				{
					c = board[a][b];
					if (c != board[a + 1][b + 1])
					{
						goto right;
					}
				}
				if (a == b && board[a][b] == ' ')
				{
					goto right;
				}
			}
		}
		return board[a][b];
	}
	right:
	//判断右上到左下对角线
	while (1)
	{
		for (a = 0; a < row-1; a++)
		{
			for (b = col-1; b > 0; b--)
			{
				if ((a + b) == (row - 1) && board[a][b] != ' ')
				{
					c = board[a][b];
					if (c != board[a + 1][b - 1])
					{
						goto third;
					}
				}
				if ((a + b) == (row - 1) && board[a][b] == ' ')
				{
					goto third;
				}
			}
		}
		return board[a][b];
	}
	third:
	//判断平局
	int tmp = FULL(board, row, col);
	if (tmp == 1)
	{
		return 'N';
	}
	return 'G';
}

