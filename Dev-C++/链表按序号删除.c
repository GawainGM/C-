#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int num;
    char name[5];
}stuType;
typedef stuType elemType;
typedef struct  node
{
    elemType data;
    struct  node * next;
}linkNode,*linkList;
void init(linkList *l)//初始化带头结点的单链表
{
    *l=(linkList)malloc(sizeof(linkNode));
    (*l)->next=NULL;
}
void input(linkList l,stuType stu[])//根据学生数组创建单链表
{
    linkNode *r,*s;
    int i;
    r=l;
    for (i=0; i<5; i++) {
        s=(linkNode*)malloc(sizeof(linkNode));
        s->data.num=stu[i].num;
        strcpy(s->data.name,stu[i].name);
        r->next=s; 
        r=s;
    }
    r->next=NULL;
}

int del(linkList l,int num)//删除学号为num的学生信息，删除成功返回1，删除失败返回0 
{
	linkList i=l;
	linkList j;
	if(l->next==NULL)
	return 0;
	while(i->next!=NULL)
	{	
		if(i->next->data.num==num)
		{
			j=i->next;
			i->next=i->next->next;
			free(j);
			return 1;
		}
	i=i->next;
	}
	return 0;
}

void output(linkList l)//输出学生信息
{
    linkNode *p=l;
    while (p->next!=NULL)
	{
        p=p->next;
        printf("%d %s\n",p->data.num,p->data.name);
    }
}
int main()
{
    linkList l;
    int num,result;
    stuType stu[5]={{3,'a'},{1,'b'},{4,'c'},{5,'d'},{2,'e'}};//学生数组 
    init(&l);//初始化带头结点的单链表
    input(l,stu);//根据学生数组创建单链表
    output(l);//输出学生信息
    printf("请输入要删除的数据的序号:");
    scanf("%d",&num);
        result=del(l,num);
    if (result==0)
        printf("error");
    else
        output(l);//输出学生信息
    return 0;
}
