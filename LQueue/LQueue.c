#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node* head = (Node*)malloc(sizeof(Node));
	while (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
	}
	Q->front =  head;
	Q->rear = head;
	head->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node* p = Q->front;
	while (p)
	{
		Q->front = p->next;
		free(p);
		p = Q->front;
	}
	Q->rear = NULL;
	Q->length = 0;
	detimes = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	unsigned int typeSize;
	if (datatype[detimes] == 'i') 
	{
		typeSize = sizeof(int);
	}
	else if (datatype[detimes] == 'd')
	{
		typeSize = sizeof(double);
	}
	else if (datatype[detimes] == 'c')
	{
		typeSize = sizeof(char);
	}
	else 
	{
		return FALSE;
	}
	memcpy(e, Q->front->next->data, typeSize);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return FALSE;
	p->data = (void*)malloc(21);
	if(p->data == NULL)
		return FALSE;
	memcpy(p->data, data, 20);
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	p->next = NULL;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	Q->length--;
	detimes++;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node* p = Q->front->next;
	while (p)
	{
		Q->front->next = p->next;
		free(p);
		p = Q->front->next;
	}	
	Q->rear = Q->front;
	Q->length = 0;
	detimes = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node* p = Q->front->next;
	if (IsEmptyLQueue(Q))
		return FALSE;
	while (p) 
	{
		foo(p->data);
		p = p->next;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q)
{
	 int pprint = detimes;
	if (datatype[pprint] == 'i')
	{
		printf("%d  ", *(int*)q);
		pprint++;
	}
	else if (datatype[pprint] == 'd')
	{
		printf("%.2f  ", *(double*)q);
		pprint++;
	}
	else if (datatype[pprint] == 'c')
	{
		printf("%c  ", *(char*)q);
		pprint++;
	}
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED


