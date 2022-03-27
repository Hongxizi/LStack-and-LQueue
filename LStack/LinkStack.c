#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack* s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	if (s->count == 0)
		printf("链表为空\n");
	else
		printf("链表不为空\n");
	return SUCCESS;
};

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s == NULL || s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p;
	while (s->count)
	{
		p = s->top;
		s->top = p->next;
		free(p);
		s->count--;
	}
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	clearLStack(s);
	//free(s);
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, ElemType* length)
{
	if (s == NULL)
	{
		return ERROR;
	}
	length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	if (s == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p)
	{
		p->next = s->top;
		s->top = p;
		p->data = data;
		s->count++;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//出栈
Status popLStack(LinkStack* s, ElemType* data)
{
	if (s == NULL || s->top == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	s->count--;
	return SUCCESS;
}

