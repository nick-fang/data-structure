//简单链表的自定义函数
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//初始化链表
void InitializeList(List *plist)
{
	plist->head=NULL;
}
//如果链表为空，则返回真
bool ListIsEmpty(const List *plist)
{
	bool ret; 
	if(plist->head==NULL)
		ret=true;
	else
		ret=false;
	return ret;
}
//如果链表已满（即当前内存装不下新节点），则返回真
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
//返回节点的数量
unsigned int ListItemCount(const List *plist)
{
	unsigned int count=0;
	Node *pnode=plist->head;//设置链表的开始
	while(pnode!=NULL)
	{
		++count;
		pnode=pnode->next;//设置下一个节点
	}
	return count;
}
//创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）
bool AddItem(Item item, List *plist)
{
	Node *pnew;
	Node *scan=plist->head;
	pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL)
		return false;//失败时退出函数，这里必须用return语句强制退出，因为一旦pnew==NULL，后面的pnew->item就会导致程序报错 
	pnew->item=item;
	pnew->next=NULL;
	if(scan==NULL)//空链表，所以把pnew放在链表的开头
		plist->head=pnew;
	else
	{
		while(scan->next!=NULL)
			scan=scan->next;//找到链表的末尾
		scan->next=pnew;//把pnew添加到链表的末尾
	}
	return true;
}
//访问每个节点并执行pfun指向的函数
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode=plist->head;
	while(pnode!=NULL)
	{
		(*pfun)(pnode->item);
		pnode=pnode->next;
	}
}
//释放由malloc()分配的内存，并且设置链表指针为NULL
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

