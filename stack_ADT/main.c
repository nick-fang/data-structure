#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	Stack cards;//抽取数字0~9的纸牌，声明这些纸牌组成一个栈 
	Item temp=(Item){0};//利用结构的复合字面量来初始化待添加条目-temp 
	InitializeStack(&cards);//初始化栈 

	//获取纸牌的序列
	puts("Please input first card, press 'q' to quit:");
	while(scanf("%d",&temp.num)==1)
	{
		Push(temp,&cards);
		puts("input next card, press 'q' to quit:");
	} 
	//显示纸牌的序列
	printf("top is %d\n",cards.top); 
	ShowStack(&cards);
	
	//剔除最上层的纸牌
	Pop(&temp,&cards);
	printf("top is %d\n",cards.top);
	printf("The card you deleted is: %d\n",temp.num); 
	
	//显示剩余的纸牌序列
	puts("Now you cards sequence is:");
	ShowStack(&cards); 
	
	return 0;
}
