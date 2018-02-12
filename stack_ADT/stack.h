//栈的头文件
#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

//特定程序的声明
#define MAXSTACK 100 //栈最多可以容纳的条目数量 

//定义每个节点储存信息的部分的别名为Item，ADT的第一层 
typedef struct _item 
{
	int num;
} Item; 
//定义栈ADT的别名为Stack，ADT的第三层 
typedef struct stack
{
	//定义栈的所有节点都是item[]数组的元素 ，即栈节点的别名是item[i]，ADT的第二层 
	Item item[MAXSTACK];
	int top;//top用于记录数组中第一个空位的下标，即栈顶元素的下标+1 
} Stack;

//函数原型
//操作：初始化栈
//前提：pstack指向一个栈 
//结果：该栈被初始化为空
void InitializeStack(Stack *pstack);

//操作：检查栈是否为空，pstack指向一个已初始化的栈  
//结果： 如果栈为空，该函数返回真，否则返回假
bool StackIsEmpty(const Stack *pstack);

//操作：检查栈是否已满，pstack指向一个已初始化的栈 
//结果： 如果栈已满，该函数返回真，否则返回假
bool StackIsFull(const Stack *pstack);

//操作：把一个条目压入栈顶 
//前提：item是一个待压入栈顶的条目，pstack指向一个已初始化的栈 
//结果： 如果栈未满，该函数把item压入栈顶并返回真，否则返回假
bool Push(Item item, Stack *pstack);

//操作：从栈顶弹出一个条目 
//前提：pstack指向一个已初始化的栈 
//结果：如果栈不为空，该函数把栈顶的item拷贝给*pitem后就清空，并返回真，否则栈不变并返回假
bool Pop(Item *pitem, Stack *pstack);

//操作：显示栈中所有元素的信息 
void ShowStack(const Stack *pstack);

#endif 
