//简单链表的头文件
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

//特定程序的声明
#define TSIZE 45 //储存电影名的数组大小

//定义每个节点储存信息的部分的别名为Item 
typedef struct film
{
	char title[TSIZE];
	int rating;
} Item; 
//定义节点结构类型的别名为Node 
typedef struct node
{
	Item item;
	struct node *next;
} Node;
//定义链表的别名为list，包含一个头指针 
typedef struct list
{
	Node *head;
} List;

//函数原型
//操作：初始化一个链表
//前提：plist指向一个链表 
//结果： 链表初始化为空
void InitializeList(List *plist);

//操作：确定链表是否为空，plist指向一个已初始化的链表 
//结果： 如果链表为空，该函数返回真，否则返回假
bool ListIsEmpty(const List *plist);

//操作：确定链表是否已满，plist指向一个已初始化的链表 
//结果： 如果链表已满，该函数返回真，否则返回假
bool ListIsFull(const List *plist);

//操作：确定链表中的项数，plist指向一个已初始化的链表 
//结果： 该函数返回链表中的项数
unsigned int ListItemCount(const List *plist);

//操作：在链表的末尾添加项 
//前提：item是一个待添加至链表的项，plist指向一个已初始化的链表 
//结果： 如果可以，该函数在链表末尾添加一个项且返回真，否则返回假
bool AddItem(Item item, List *plist);

//操作：使用该函数调用的子函数遍历链表中的所有项 
//前提：plist指向一个已初始化的链表，pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值 
//结果： pfun中的函数作用于链表中的每一项一次
void Traverse(const List *plist, void(*pfun)(Item item));

//操作：释放已分配的内存（如果有的话） ，plist指向一个已初始化的指针 
//结果： 释放了为链表分配的所有内存，链表设置为空
void EmptyTheList(List *plist);

#endif 
