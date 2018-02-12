//ջ��ͷ�ļ�
#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

//�ض����������
#define MAXSTACK 100 //ջ���������ɵ���Ŀ���� 

//����ÿ���ڵ㴢����Ϣ�Ĳ��ֵı���ΪItem��ADT�ĵ�һ�� 
typedef struct _item 
{
	int num;
} Item; 
//����ջADT�ı���ΪStack��ADT�ĵ����� 
typedef struct stack
{
	//����ջ�����нڵ㶼��item[]�����Ԫ�� ����ջ�ڵ�ı�����item[i]��ADT�ĵڶ��� 
	Item item[MAXSTACK];
	int top;//top���ڼ�¼�����е�һ����λ���±꣬��ջ��Ԫ�ص��±�+1 
} Stack;

//����ԭ��
//��������ʼ��ջ
//ǰ�᣺pstackָ��һ��ջ 
//�������ջ����ʼ��Ϊ��
void InitializeStack(Stack *pstack);

//���������ջ�Ƿ�Ϊ�գ�pstackָ��һ���ѳ�ʼ����ջ  
//����� ���ջΪ�գ��ú��������棬���򷵻ؼ�
bool StackIsEmpty(const Stack *pstack);

//���������ջ�Ƿ�������pstackָ��һ���ѳ�ʼ����ջ 
//����� ���ջ�������ú��������棬���򷵻ؼ�
bool StackIsFull(const Stack *pstack);

//��������һ����Ŀѹ��ջ�� 
//ǰ�᣺item��һ����ѹ��ջ������Ŀ��pstackָ��һ���ѳ�ʼ����ջ 
//����� ���ջδ�����ú�����itemѹ��ջ���������棬���򷵻ؼ�
bool Push(Item item, Stack *pstack);

//��������ջ������һ����Ŀ 
//ǰ�᣺pstackָ��һ���ѳ�ʼ����ջ 
//��������ջ��Ϊ�գ��ú�����ջ����item������*pitem�����գ��������棬����ջ���䲢���ؼ�
bool Pop(Item *pitem, Stack *pstack);

//��������ʾջ������Ԫ�ص���Ϣ 
void ShowStack(const Stack *pstack);

#endif 
