#pragma once
//�⺯��ͷ�ļ�����
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//�����к���
#define ROW 3 //��
#define COL 3 //��

//�˵�
void menu();

//������Ϸ����
void game();

//��ʼ������
void InBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);

//����ж�
void Player(char board[ROW][COL], int row, int col);

//�����ж�
void PC(char board[ROW][COL], int row, int col);

//�ж���Ϸ���
//����*Ϊ���ʤ��
//����#Ϊ����ʤ��
//����NΪƽ��
//����GΪ��Ϸ����
char Win(char board[ROW][COL], int row, int col);

int FULL(char board[ROW][COL], int row, int col);