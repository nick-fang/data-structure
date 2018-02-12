//�������ͷ�ļ�
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

//�ض����������
#define TSIZE 45 //�����Ӱ���������С

//����ÿ���ڵ㴢����Ϣ�Ĳ��ֵı���ΪItem 
typedef struct film
{
	char title[TSIZE];
	int rating;
} Item; 
//����ڵ�ṹ���͵ı���ΪNode 
typedef struct node
{
	Item item;
	struct node *next;
} Node;
//��������ı���Ϊlist������һ��ͷָ�� 
typedef struct list
{
	Node *head;
} List;

//����ԭ��
//��������ʼ��һ������
//ǰ�᣺plistָ��һ������ 
//����� �����ʼ��Ϊ��
void InitializeList(List *plist);

//������ȷ�������Ƿ�Ϊ�գ�plistָ��һ���ѳ�ʼ�������� 
//����� �������Ϊ�գ��ú��������棬���򷵻ؼ�
bool ListIsEmpty(const List *plist);

//������ȷ�������Ƿ�������plistָ��һ���ѳ�ʼ�������� 
//����� ��������������ú��������棬���򷵻ؼ�
bool ListIsFull(const List *plist);

//������ȷ�������е�������plistָ��һ���ѳ�ʼ�������� 
//����� �ú������������е�����
unsigned int ListItemCount(const List *plist);

//�������������ĩβ����� 
//ǰ�᣺item��һ���������������plistָ��һ���ѳ�ʼ�������� 
//����� ������ԣ��ú���������ĩβ���һ�����ҷ����棬���򷵻ؼ�
bool AddItem(Item item, List *plist);

//������ʹ�øú������õ��Ӻ������������е������� 
//ǰ�᣺plistָ��һ���ѳ�ʼ��������pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ 
//����� pfun�еĺ��������������е�ÿһ��һ��
void Traverse(const List *plist, void(*pfun)(Item item));

//�������ͷ��ѷ�����ڴ棨����еĻ��� ��plistָ��һ���ѳ�ʼ����ָ�� 
//����� �ͷ���Ϊ�������������ڴ棬��������Ϊ��
void EmptyTheList(List *plist);

#endif 
