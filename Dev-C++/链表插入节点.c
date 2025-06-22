#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 5
typedef struct
{
    int num;
    char name[9];
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
    for (i=0; i<NUM; i++) {
        s=(linkNode*)malloc(sizeof(linkNode));
        s->data.num=stu[i].num;
        strcpy(s->data.name,stu[i].name);
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

int insert(linkList l,int i,stuType n)//插入结点n作为第i个结点，插入成功返回1，插入失败返回0
{
	linkList p,r=l;
	int num=1;
	if(i<1)
	return 0;
	p=(linkNode*)malloc(sizeof(linkNode));
	p->data=n;
	while(r->next!=NULL||num==i)
	{
		if(num==i)
		{
			p->next=r->next;
			r->next=p;
			free(p);
			return 1;
		}
		num++;
		r=r->next;
	}
	free(p);
	return 0;
}

void output(linkList l)//输出学生信息
{
    linkNode *p=l;
    while (p->next!=NULL) {
        p=p->next;
        printf("%d %s\n",p->data.num,p->data.name);
    }
}

int main()
{
    linkList l;
    int pos;
    int result;
    stuType stu[NUM]={{3,'a'},{1,'b'},{4,'c'},{5,'d'},{2,'e'}};
    stuType newStu;
    init(&l);//初始化带头结点的单链表
    input(l,stu);//根据学生数组创建单链表
    scanf("%d",&pos);
    scanf("%d %s",&newStu.num,newStu.name);
    result=insert(l,pos,newStu);//插入结点newStu作为第pos个结点，插入成功返回1，插入失败返回0
    if (result==0)
        printf("error");
    else
        output(l);//输出学生信息
    return 0;
}
