#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int num;
    char name[10];
}stuType;
typedef stuType elemType;
typedef struct  node
{
    elemType data;
    struct  node * next;
}linkNode,*linkList;
void init(linkList *l)//��ʼ������ 
{
    *l=(linkList)malloc(sizeof(linkNode));
    (*l)->next=NULL;
}
void input(linkList l)//����β�巨¼��ѧ����Ϣ,falgΪ1����������Ϊ0ֹͣ����
{
    linkNode *r,*s;
    int flag=1;
    r=l;
    while (flag==1)
   {
	s=(linkList)malloc(sizeof(linkNode));
	printf("���������ֺ�����(eg:1 Gawain):");
   	scanf("%d %s",&s->data.num,s->data.name);
   	r->next=s;
   	r=s;
   	getchar();
   	printf("\n�Ƿ�Ҫ��������(1/0):");
   	scanf("%d",&flag);
   }
   r->next=NULL;
}
void output(linkList l)//���ѧ����Ϣ
{
	linkList a;
	a=l->next;
	while(a!=NULL)
	{
		printf("%d %s\n",a->data.num,a->data.name);//���ѧ����Ϣ
		a=a->next;//ָ����һ������
	}
}
linkList find(linkList l,int i)//�������Ϊi�Ľ�㣬�ҵ����ظý��ĵ�ַ��û���ҵ�����NULL,��l->data.num 
{
	linkList a;
	a=l->next;
	while(a!=NULL&&a->data.num!=i)
	{
		a=a->next;
	}
	return a;
}
int main()
{
    linkList l;
    init(&l);
    input(l);
    output(l);
    return 0;
}
