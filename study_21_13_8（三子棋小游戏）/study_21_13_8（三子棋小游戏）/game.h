#pragma once
//库函数头文件包含
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//定义行和列
#define ROW 3 //行
#define COL 3 //列

//菜单
void menu();

//创建游戏函数
void game();

//初始化棋盘
void InBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

//玩家行动
void Player(char board[ROW][COL], int row, int col);

//电脑行动
void PC(char board[ROW][COL], int row, int col);

//判断游戏结果
//返回*为玩家胜利
//返回#为电脑胜利
//返回N为平局
//返回G为游戏继续
char Win(char board[ROW][COL], int row, int col);

int FULL(char board[ROW][COL], int row, int col);