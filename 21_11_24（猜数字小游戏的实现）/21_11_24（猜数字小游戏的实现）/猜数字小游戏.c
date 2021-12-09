#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()//菜单
{
	printf("************************\n");
	printf("****** 1.开始游戏 ******\n");
	printf("****** 0.退出游戏 ******\n");
	printf("************************\n");
}
void game()//猜数字游戏
{
	//1.生成随机数
	int r = rand()%100 + 1;//%100 = 0-99 + 1 =1-100
	//printf("%d\n", r);  测试随机数用的
	//2.输入数字去比较
	while (1)
	{
		int num = 0;
		scanf("%d", &num);
		if (num < r)
		{
			printf("小了，再猜:>");
		}
		else if (num > r)
		{
			printf("大了，再猜:>");
		}
		else
		{
			printf("恭喜你，猜对了\n");
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
		menu();//打印菜单
		printf("请选择是否开始游戏:>");
		scanf("%d", &begin);
		switch (begin)
		{
		case 1:
			printf("请输入1-100数字:>");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (begin);
	return 0;
}


