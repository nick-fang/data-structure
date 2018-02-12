#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	Stack cards;//��ȡ����0~9��ֽ�ƣ�������Щֽ�����һ��ջ 
	Item temp=(Item){0};//���ýṹ�ĸ�������������ʼ���������Ŀ-temp 
	InitializeStack(&cards);//��ʼ��ջ 

	//��ȡֽ�Ƶ�����
	puts("Please input first card, press 'q' to quit:");
	while(scanf("%d",&temp.num)==1)
	{
		Push(temp,&cards);
		puts("input next card, press 'q' to quit:");
	} 
	//��ʾֽ�Ƶ�����
	printf("top is %d\n",cards.top); 
	ShowStack(&cards);
	
	//�޳����ϲ��ֽ��
	Pop(&temp,&cards);
	printf("top is %d\n",cards.top);
	printf("The card you deleted is: %d\n",temp.num); 
	
	//��ʾʣ���ֽ������
	puts("Now you cards sequence is:");
	ShowStack(&cards); 
	
	return 0;
}
