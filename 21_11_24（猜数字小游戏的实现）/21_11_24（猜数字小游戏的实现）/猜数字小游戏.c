#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()//�˵�
{
	printf("************************\n");
	printf("****** 1.��ʼ��Ϸ ******\n");
	printf("****** 0.�˳���Ϸ ******\n");
	printf("************************\n");
}
void game()//��������Ϸ
{
	//1.���������
	int r = rand()%100 + 1;//%100 = 0-99 + 1 =1-100
	//printf("%d\n", r);  ����������õ�
	//2.��������ȥ�Ƚ�
	while (1)
	{
		int num = 0;
		scanf("%d", &num);
		if (num < r)
		{
			printf("С�ˣ��ٲ�:>");
		}
		else if (num > r)
		{
			printf("���ˣ��ٲ�:>");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int begin = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ���Ƿ�ʼ��Ϸ:>");
		scanf("%d", &begin);
		switch (begin)
		{
		case 1:
			printf("������1-100����:>");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (begin);
	return 0;
}


