//栈ADT的自定义函数
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//操作：初始化栈
//前提：pstack指向一个栈
//结果：该栈被初始化为空
void InitializeStack(Stack *pstack)
{
	pstack->top=0;
	pstack->item[pstack->top]=(Item){0};
}

//操作：检查栈是否为空，pstack指向一个已初始化的栈
//结果： 如果栈为空，该函数返回真，否则返回假
bool StackIsEmpty(const Stack *pstack)
{
	bool ret;
	if(0==pstack->top)
		ret=1;
	else
		ret=0;
	return ret;
}

//操作：检查栈是否已满，pstack指向一个已初始化的栈
//结果： 如果栈已满，该函数返回真，否则返回假
bool StackIsFull(const Stack *pstack)
{
	bool ret;
	if(MAXSTACK-1==pstack->top)
		ret=1;
	else
		ret=0;
	return ret;
}

//操作：把一个条目压入栈顶
//前提：item是一个待压入栈顶的条目，pstack指向一个已初始化的栈
//结果： 如果栈未满，该函数把item压入栈顶并返回真，否则返回假
bool Push(Item item1, Stack *pstack)
{
	bool ret=1;
	if(1==StackIsFull(pstack))
		ret=0;
	else
	{
		pstack->item[pstack->top]=item1;
		(pstack->top)++;
	}
	return ret;
}

//操作：从栈顶弹出一个条目
//前提：pstack指向一个已初始化的栈
//结果：如果栈不为空，该函数把栈顶的item拷贝给*pitem后就清空，并返回真，否则栈不变并返回假
bool Pop(Item *pitem, Stack *pstack)
{
	bool ret=1;
	if(1==StackIsEmpty(pstack))
		ret=0;
	else
	{
		(pstack->top)--;
		*pitem=pstack->item[pstack->top];
		pstack->item[pstack->top].num=0;
	}
	return ret;
}

void ShowStack(const Stack *pstack)
{
	int i=0;
	for(i=0;i<pstack->top;i++)
		printf("num: %d\n",pstack->item[i].num);
} 

