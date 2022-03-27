#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

int GetRight(int swi);
void* GetFan(LQueue* Q);
void Menu();
void tip();

int main()
{
	int i,flag = 0;
	void* D = (void*)malloc(20);
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	void* Foo = LPrint;
	while (1)
	{
		system("cls");
		Menu();
		i = GetRight(0);
		while (i > 9 || i < 0 || (i != 1 && flag == 0))
		{
			if (flag == 1)
				printf("输入错误，请输入0-8的指令\n");
			else
				printf("队列未初始化，请重新输入指令\n");
			i = GetRight(0);
		}		
		switch (i)
		{
			case 1:			//初始化队列
			{
				InitLQueue(Q);
				printf("队列初始化完成\n");
				flag = 1;
				break;
			}
			case 2:			//销毁队列
			{
				DestoryLQueue(Q);
				printf("队列销毁完成\n");
				flag = 0;
				break;
			}
			case 3:			//检查队列是否为空
			{
				if (IsEmptyLQueue(Q))
					printf("队列为空\n");
				else
					printf("队列不为空\n");
				break;
			}
			case 4:			//查看队头元素
			{
				if (GetHeadLQueue(Q, D) == TRUE)
				{
					printf("队头元素为：");
					if (datatype[detimes] == 'i')
					{
						printf("%d\n", *(int*)D);
					}
					else if (datatype[detimes] == 'd')
					{
						printf("%.2f\n", *(double*)D);
					}
					else if (datatype[detimes] == 'c')
					{
						printf("%c\n", *(char*)D);
					}
				}
				else
					printf("队列为空，没有头元素\n");
				break;
			}
			case 5:			//确定队列长度
			{
				printf("队列的长度为%d\n", LengthLQueue(Q));
				break;
			}
			case 6:			//入队
			{
				tip();
				if (EnLQueue(Q, GetFan(Q)))
					printf("入队成功\n");
				else
					printf("入队失败\n");
				break;
			}
			case 7:			//出队
			{
				if (DeLQueue(Q))
					printf("出队成功\n");
				else
					printf("入出队失败\n");
				break;
			}
			case 8:			//清空队列
			{
				ClearLQueue(Q);
				printf("清空队列成功\n");
				break;
			}
			case 9:			//遍历函数
			{
				if (TraverseLQueue(Q, Foo))
					printf("遍历对列成功\n");
				else
					printf("链表为空，遍历队列失败\n");
				break;
			}
			case 0:			//退出系统
			{
				system("cls");
				return 0;
			}
		}
		printf("按回车返回\n");
		while (getchar() != '\n');
	}
return 0;
}

//获取整数并检测非法字符,swi为0允许输入负数，swi为1则不允许
int GetRight(int swi)
{
	int ret;
	int i;
	ret = scanf_s("%d", &i);
	while (ret != 1 || (swi && i < 0))			//swi相当于一个开关，当swi为1时开关开启，需判断i是否小于0；当swi为0时则不用判断
	{
		while (getchar() != '\n');
		printf("输入错误，请重新输入\n");
		ret = scanf_s("%d", &i);
	}
	while (getchar() != '\n');
	return i;
}

//泛型输入
void* GetFan(LQueue* Q)
{
	void* data = (void*)malloc(20);
	printf("请问你要输入数据的类型i,d,c\n");
	scanf_s("%c", &type,1);
	while (getchar() != '\n');
	while (type != 'i' && type != 'd' && type != 'c')
	{
		printf("输入错误，请选择正确的数据类型，整形，浮点型，或者字符型\n");
		scanf_s("%c", &type,1);
		while (getchar() != '\n');
	}
	printf("请输入你要输入的数据\n");
	switch (type)
	{
		case 'i':
		{
			while (!scanf_s("%d", (int*)data))
			{
				while (getchar() != '\n');
				printf("输入错误，请重新输入\n");
			}
			break;
		}
		case 'd':
		{
			while (!scanf_s("%lf", (double*)data))
			{
				while (getchar() != '\n');
				printf("输入错误，请重新输入\n");
			}
			break;
		}
		case 'c':
		{
			while (!scanf_s("%c", (char*)data,1))
			{
				while (getchar() != '\n');
				printf("输入错误，请重新输入\n");
			}
			break;
		}
	}
	while (getchar() != '\n');
	datatype[Q->length - detimes] = type;
	return data;
}

//菜单显示
void Menu()
{
	printf("*************************系统功能菜单*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.初始化队列       * *   2.销毁队列        *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.检查队列是否为空 * *   4.查看队头元素    *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.确定队列长度     * *   6.入队            *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.出队             * *   8.清空队列        *\n");
	printf("\t***********************************************\n");
	printf("\t*  9.遍历函数         * *   0.退出系统        *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("请选择菜单编号:\n");
}

//小提示
void tip()
{
	printf("----------------------\n");
	printf("Tip:整形数据请按 i\n");
	printf("    浮点型数据请按 d\n");
	printf("    字符形数据请按 c\n");
	printf("----------------------\n");
}
