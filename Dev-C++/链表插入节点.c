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

void init(linkList *l)//��ʼ����ͷ���ĵ�����
{
    *l=(linkList)malloc(sizeof(linkNode));
    (*l)->next=NULL;
}

void input(linkList l,stuType stu[])//����ѧ�����鴴��������
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

int insert(linkList l,int i,stuType n)//������n��Ϊ��i����㣬����ɹ�����1������ʧ�ܷ���0
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

void output(linkList l)//���ѧ����Ϣ
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
    init(&l);//��ʼ����ͷ���ĵ�����
    input(l,stu);//����ѧ�����鴴��������
    scanf("%d",&pos);
    scanf("%d %s",&newStu.num,newStu.name);
    result=insert(l,pos,newStu);//������newStu��Ϊ��pos����㣬����ɹ�����1������ʧ�ܷ���0
    if (result==0)
        printf("error");
    else
        output(l);//���ѧ����Ϣ
    return 0;
}
