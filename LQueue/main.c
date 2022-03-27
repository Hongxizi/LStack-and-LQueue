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
				printf("�������������0-8��ָ��\n");
			else
				printf("����δ��ʼ��������������ָ��\n");
			i = GetRight(0);
		}		
		switch (i)
		{
			case 1:			//��ʼ������
			{
				InitLQueue(Q);
				printf("���г�ʼ�����\n");
				flag = 1;
				break;
			}
			case 2:			//���ٶ���
			{
				DestoryLQueue(Q);
				printf("�����������\n");
				flag = 0;
				break;
			}
			case 3:			//�������Ƿ�Ϊ��
			{
				if (IsEmptyLQueue(Q))
					printf("����Ϊ��\n");
				else
					printf("���в�Ϊ��\n");
				break;
			}
			case 4:			//�鿴��ͷԪ��
			{
				if (GetHeadLQueue(Q, D) == TRUE)
				{
					printf("��ͷԪ��Ϊ��");
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
					printf("����Ϊ�գ�û��ͷԪ��\n");
				break;
			}
			case 5:			//ȷ�����г���
			{
				printf("���еĳ���Ϊ%d\n", LengthLQueue(Q));
				break;
			}
			case 6:			//���
			{
				tip();
				if (EnLQueue(Q, GetFan(Q)))
					printf("��ӳɹ�\n");
				else
					printf("���ʧ��\n");
				break;
			}
			case 7:			//����
			{
				if (DeLQueue(Q))
					printf("���ӳɹ�\n");
				else
					printf("�����ʧ��\n");
				break;
			}
			case 8:			//��ն���
			{
				ClearLQueue(Q);
				printf("��ն��гɹ�\n");
				break;
			}
			case 9:			//��������
			{
				if (TraverseLQueue(Q, Foo))
					printf("�������гɹ�\n");
				else
					printf("����Ϊ�գ���������ʧ��\n");
				break;
			}
			case 0:			//�˳�ϵͳ
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

//��������
void* GetFan(LQueue* Q)
{
	void* data = (void*)malloc(20);
	printf("������Ҫ�������ݵ�����i,d,c\n");
	scanf_s("%c", &type,1);
	while (getchar() != '\n');
	while (type != 'i' && type != 'd' && type != 'c')
	{
		printf("���������ѡ����ȷ���������ͣ����Σ������ͣ������ַ���\n");
		scanf_s("%c", &type,1);
		while (getchar() != '\n');
	}
	printf("��������Ҫ���������\n");
	switch (type)
	{
		case 'i':
		{
			while (!scanf_s("%d", (int*)data))
			{
				while (getchar() != '\n');
				printf("�����������������\n");
			}
			break;
		}
		case 'd':
		{
			while (!scanf_s("%lf", (double*)data))
			{
				while (getchar() != '\n');
				printf("�����������������\n");
			}
			break;
		}
		case 'c':
		{
			while (!scanf_s("%c", (char*)data,1))
			{
				while (getchar() != '\n');
				printf("�����������������\n");
			}
			break;
		}
	}
	while (getchar() != '\n');
	datatype[Q->length - detimes] = type;
	return data;
}

//�˵���ʾ
void Menu()
{
	printf("*************************ϵͳ���ܲ˵�*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.��ʼ������       * *   2.���ٶ���        *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.�������Ƿ�Ϊ�� * *   4.�鿴��ͷԪ��    *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.ȷ�����г���     * *   6.���            *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.����             * *   8.��ն���        *\n");
	printf("\t***********************************************\n");
	printf("\t*  9.��������         * *   0.�˳�ϵͳ        *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("��ѡ��˵����:\n");
}

//С��ʾ
void tip()
{
	printf("----------------------\n");
	printf("Tip:���������밴 i\n");
	printf("    �����������밴 d\n");
	printf("    �ַ��������밴 c\n");
	printf("----------------------\n");
}
