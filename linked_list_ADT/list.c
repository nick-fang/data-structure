//��������Զ��庯��
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//��ʼ������
void InitializeList(List *plist)
{
	plist->head=NULL;
}
//�������Ϊ�գ��򷵻���
bool ListIsEmpty(const List *plist)
{
	bool ret; 
	if(plist->head==NULL)
		ret=true;
	else
		ret=false;
	return ret;
}
//�����������������ǰ�ڴ�װ�����½ڵ㣩���򷵻���
bool ListIsFull(const List *plist)
{
	Node *pt;
	bool ret;
	pt=(Node *)malloc(sizeof(Node));
	if(pt==NULL)
		ret=true;
	else
		ret=false;
	free(pt);
	return ret;
}
//���ؽڵ������
unsigned int ListItemCount(const List *plist)
{
	unsigned int count=0;
	Node *pnode=plist->head;//��������Ŀ�ʼ
	while(pnode!=NULL)
	{
		++count;
		pnode=pnode->next;//������һ���ڵ�
	}
	return count;
}
//����������Ľڵ㣬�������������plistָ�������ĩβ��������ʵ�֣�
bool AddItem(Item item, List *plist)
{
	Node *pnew;
	Node *scan=plist->head;
	pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL)
		return false;//ʧ��ʱ�˳����������������return���ǿ���˳�����Ϊһ��pnew==NULL�������pnew->item�ͻᵼ�³��򱨴� 
	pnew->item=item;
	pnew->next=NULL;
	if(scan==NULL)//���������԰�pnew��������Ŀ�ͷ
		plist->head=pnew;
	else
	{
		while(scan->next!=NULL)
			scan=scan->next;//�ҵ������ĩβ
		scan->next=pnew;//��pnew��ӵ������ĩβ
	}
	return true;
}
//����ÿ���ڵ㲢ִ��pfunָ��ĺ���
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode=plist->head;
	while(pnode!=NULL)
	{
		(*pfun)(pnode->item);
		pnode=pnode->next;
	}
}
//�ͷ���malloc()������ڴ棬������������ָ��ΪNULL
void EmptyTheList(List *plist)
{
	Node *psave;
	while(plist->head!=NULL)
	{
		psave=(plist->head)->next;
		free(plist->head);
		plist->head=psave;
	}
}

