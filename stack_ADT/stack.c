//ջADT���Զ��庯��
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//��������ʼ��ջ
//ǰ�᣺pstackָ��һ��ջ
//�������ջ����ʼ��Ϊ��
void InitializeStack(Stack *pstack)
{
	pstack->top=0;
	pstack->item[pstack->top]=(Item){0};
}

//���������ջ�Ƿ�Ϊ�գ�pstackָ��һ���ѳ�ʼ����ջ
//����� ���ջΪ�գ��ú��������棬���򷵻ؼ�
bool StackIsEmpty(const Stack *pstack)
{
	bool ret;
	if(0==pstack->top)
		ret=1;
	else
		ret=0;
	return ret;
}

//���������ջ�Ƿ�������pstackָ��һ���ѳ�ʼ����ջ
//����� ���ջ�������ú��������棬���򷵻ؼ�
bool StackIsFull(const Stack *pstack)
{
	bool ret;
	if(MAXSTACK-1==pstack->top)
		ret=1;
	else
		ret=0;
	return ret;
}

//��������һ����Ŀѹ��ջ��
//ǰ�᣺item��һ����ѹ��ջ������Ŀ��pstackָ��һ���ѳ�ʼ����ջ
//����� ���ջδ�����ú�����itemѹ��ջ���������棬���򷵻ؼ�
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

//��������ջ������һ����Ŀ
//ǰ�᣺pstackָ��һ���ѳ�ʼ����ջ
//��������ջ��Ϊ�գ��ú�����ջ����item������*pitem�����գ��������棬����ջ���䲢���ؼ�
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

