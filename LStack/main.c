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
			printf("�������������0-8��ָ��\n");
			i = GetRight(0);
		}
		switch (i)
		{
			case 1:
			{
				if (flag != 1 && initLStack(&Stact) == SUCCESS)
				{
					printf("��ʼ����ջ�ɹ�\n");
					flag = 1;
				}
				else
					printf("��ջ�Ѵ��ڣ������ʼ��\n");
				break;
			}
			case 2:
			{
				if (flag && isEmptyLStack(&Stact) == SUCCESS)
					printf("������ɣ�");
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 3:
			{
				if (flag && getTopLStack(&Stact, &data) == SUCCESS)
					printf("ջ����ֵΪ%d\n", data);
				else if (flag)
					printf("��ջΪ�գ�����ʧ��\n");
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 4:
			{
				if (flag && clearLStack(&Stact) == SUCCESS)
					printf("���ջ���\n");
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 5:
			{
				if (flag && destroyLStack(&Stact) == SUCCESS)
				{
					printf("����ջ���\n");
					flag = 0;
				}
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 6:
			{
				if (flag && LStackLength(&Stact, &length) == SUCCESS)
					printf("��ǰ��ջ�ĳ���Ϊ%d\n", length);
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 7:
			{
				printf("������Ҫ��ջ��ֵ\n");
				if (flag && pushLStack(&Stact, GetRight(0)) == SUCCESS)
					printf("��ջ���\n");
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 8:
			{
				if (flag && popLStack(&Stact, &data) == SUCCESS)
					printf("��ջ��ֵΪ%d\n", data);
				else if (flag)
					printf("��ջΪ�գ�����ʧ��\n");
				else
					printf("δ��ʼ����ջ������ʧ��\n");
				break;
			}
			case 0:
			{
				system("cls");
				return 0;
			}
		}
		printf("���س�����\n");
		while (getchar() != '\n');
	}
	return 0;
}

//��ȡ���������Ƿ��ַ�,swiΪ0�������븺����swiΪ1������
int GetRight(int swi)
{
	int ret;
	int i;
	ret = scanf_s("%d", &i);
	while (ret != 1 || (swi && i < 0))			//swi�൱��һ�����أ���swiΪ1ʱ���ؿ��������ж�i�Ƿ�С��0����swiΪ0ʱ�����ж�
	{
		while (getchar() != '\n');
		printf("�����������������\n");
		ret = scanf_s("%d", &i);
	}
	while (getchar() != '\n');
	return i;
}

void Menu()
{
	printf("*************************ϵͳ���ܲ˵�*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.��ʼ��ջ         * *   2.�ж�ջ�Ƿ�Ϊ��  *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.�õ�ջ��Ԫ��     * *   4.���ջ          *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.����ջ           * *   6.���ջ����      *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.��ջ             * *    8.��ջ           *\n");
	printf("\t***********************************************\n");
	printf("\t*                 0.�˳�ϵͳ                  *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("��ѡ��˵����:\n");
}
