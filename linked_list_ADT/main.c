#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void showmovies(Item item);
char *s_gets(char *st, int n);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[])
{
	List movies;//movies是个结构，而不是指针了 
	Item temp;
	//初始化
	InitializeList(&movies);
	if(ListIsFull(&movies))
	{
		fprintf(stderr,"No memory available! Bye!\n");
		exit(1);
	}
	//获取用户的输入并储存
	puts("Enter first movie title:");
	while(s_gets(temp.title,TSIZE)!=NULL && temp.title[0]!='\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d",&temp.rating);
		while(getchar()!='\n')
			continue;
		if(AddItem(temp,&movies)==false)
		{
			fprintf(stderr,"Problem allocating memory\n");
			break;
		}
		if(ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title (empty line to stop):");
	}
	//显示链表
	if(ListIsEmpty((&movies)))
		puts("No data enterd.");
	else
	{
		puts("Here is the movies list:");
		Traverse(&movies,showmovies);
	}
	printf("You enterd %d movies.\n",ListItemCount(&movies));
	//释放内存
	EmptyTheList(&movies);
	puts("Bye!\n");

	return 0;
}

//函数定义
void showmovies(Item item)
{
	printf("Movie: %s Rating: %d\n",item.title,item.rating);
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val!=NULL)
	{
		find=strchr(st,'\n');
		if(find!=NULL)
			*find='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}

