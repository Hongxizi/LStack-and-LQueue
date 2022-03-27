#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h" 

int GetRight(int swi);
void Menu();

int  main()
{
	LinkStack Stact ;
	int flag = 0;
	int i = 0;
	int length = 0;
	int data = 0;
	while (1)
	{
		system("cls");
		Menu();
		i = GetRight(0);
		while (i > 8 || i < 0)
		{
			printf("输入错误，请输入0-8的指令\n");
			i = GetRight(0);
		}
		switch (i)
		{
			case 1:
			{
				if (flag != 1 && initLStack(&Stact) == SUCCESS)
				{
					printf("初始化链栈成功\n");
					flag = 1;
				}
				else
					printf("链栈已存在，无需初始化\n");
				break;
			}
			case 2:
			{
				if (flag && isEmptyLStack(&Stact) == SUCCESS)
					printf("操作完成，");
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 3:
			{
				if (flag && getTopLStack(&Stact, &data) == SUCCESS)
					printf("栈顶的值为%d\n", data);
				else if (flag)
					printf("链栈为空，操作失败\n");
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 4:
			{
				if (flag && clearLStack(&Stact) == SUCCESS)
					printf("清空栈完成\n");
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 5:
			{
				if (flag && destroyLStack(&Stact) == SUCCESS)
				{
					printf("销毁栈完成\n");
					flag = 0;
				}
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 6:
			{
				if (flag && LStackLength(&Stact, &length) == SUCCESS)
					printf("当前链栈的长度为%d\n", length);
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 7:
			{
				printf("请输入要进栈的值\n");
				if (flag && pushLStack(&Stact, GetRight(0)) == SUCCESS)
					printf("进栈完成\n");
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 8:
			{
				if (flag && popLStack(&Stact, &data) == SUCCESS)
					printf("出栈的值为%d\n", data);
				else if (flag)
					printf("链栈为空，操作失败\n");
				else
					printf("未初始化链栈，操作失败\n");
				break;
			}
			case 0:
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

void Menu()
{
	printf("*************************系统功能菜单*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.初始化栈         * *   2.判断栈是否为空  *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.得到栈顶元素     * *   4.清空栈          *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.销毁栈           * *   6.检测栈长度      *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.入栈             * *    8.出栈           *\n");
	printf("\t***********************************************\n");
	printf("\t*                 0.退出系统                  *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("请选择菜单编号:\n");
}
