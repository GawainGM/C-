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
void init(linkList *l)//初始化链表 
{
    *l=(linkList)malloc(sizeof(linkNode));
    (*l)->next=NULL;
}
void input(linkList l)//采用尾插法录入学生信息,falg为1继续创建，为0停止创建
{
    linkNode *r,*s;
    int flag=1;
    r=l;
    while (flag==1)
   {
	s=(linkList)malloc(sizeof(linkNode));
	printf("请输入数字和名字(eg:1 Gawain):");
   	scanf("%d %s",&s->data.num,s->data.name);
   	r->next=s;
   	r=s;
   	getchar();
   	printf("\n是否要继续输入(1/0):");
   	scanf("%d",&flag);
   }
   r->next=NULL;
}
void output(linkList l)//输出学生信息
{
	linkList a;
	a=l->next;
	while(a!=NULL)
	{
		printf("%d %s\n",a->data.num,a->data.name);//输出学生信息
		a=a->next;//指向下一个数据
	}
}
linkList find(linkList l,int i)//查找序号为i的结点，找到返回该结点的地址，没有找到返回NULL,即l->data.num 
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
