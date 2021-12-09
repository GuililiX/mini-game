#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("*********** 1.��Ϸ��ʼ ***********\n");
	printf("*********** 0.��Ϸ���� ***********\n");
	printf("**********************************\n");
}

void game()
{
	char out;
	//�洢��Ϸ�ڲ�����
	char board[ROW][COL];
	//��ʼ�����̣��ո�
	InBoard(board, ROW, COL);
	//��ӡ����
	PrintBoard(board, ROW, COL);
	while (1)
	{

		//����ж�
		Player(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		//�ж���Ϸ�Ƿ����
		out = Win(board, ROW, COL);
		if (out != 'G')
		{
			break;
		}
		//�����ж�
		PC(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		//�ж���Ϸ�Ƿ����
		out = Win(board, ROW, COL);
		if (out != 'G')
		{
			break;
		}
	}
	//��Ϸ�����ж�ʤ��
	if (out == '*')
	{
		printf("���ʤ��\n");
	}
	else if (out == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
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
	printf("����ж�\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d %d", &a, &b);
		//�ж�����������Ƿ�Ϸ�
		if (a >= 1 && a <= col && b >= 1 && b <= row)
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("������������������ӣ�����������\n");
			}
		}
		else
		{
			printf("���������������������\n");
		}

	}
}

void PC(char board[ROW][COL], int row, int col)
{
	printf("�����ж�\n");
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
				return 0;//����û��
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
	//�ж�һ��
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
	//�ж�һ��
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
	//�ж����ϵ����¶Խ���
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
	//�ж����ϵ����¶Խ���
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
	//�ж�ƽ��
	int tmp = FULL(board, row, col);
	if (tmp == 1)
	{
		return 'N';
	}
	return 'G';
}

