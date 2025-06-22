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
    for (i=0; i<5; i++) {
        s=(linkNode*)malloc(sizeof(linkNode));
        s->data.num=stu[i].num;
        strcpy(s->data.name,stu[i].name);
        r->next=s; 
        r=s;
    }
    r->next=NULL;
}

int del(linkList l,int num)//ɾ��ѧ��Ϊnum��ѧ����Ϣ��ɾ���ɹ�����1��ɾ��ʧ�ܷ���0 
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

void output(linkList l)//���ѧ����Ϣ
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
    stuType stu[5]={{3,'a'},{1,'b'},{4,'c'},{5,'d'},{2,'e'}};//ѧ������ 
    init(&l);//��ʼ����ͷ���ĵ�����
    input(l,stu);//����ѧ�����鴴��������
    output(l);//���ѧ����Ϣ
    printf("������Ҫɾ�������ݵ����:");
    scanf("%d",&num);
        result=del(l,num);
    if (result==0)
        printf("error");
    else
        output(l);//���ѧ����Ϣ
    return 0;
}
