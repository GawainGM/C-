#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*LINK;
void create(LINK *s,int n)//����һ��n��Ԫ�ص�ѭ��������
{
	LINK p;
	LINK r;
	int i=1;
	*s=(LINK)malloc(sizeof(NODE));
	(*s)->data=i;
	r=*s;
	for(i=2;i<=n;i++)
	{
	p=(LINK)malloc(sizeof(NODE));
	p->data=i;
	r->next=p;
	r=p;
	}
	p->next=(*s);
}
void print(LINK s)
{
	LINK p;
	p=s;
	while(1)
	{
		printf("%d ",p->data);
		p=p->next;
		if(p==s)
		break;
	}
	printf("\n");
}
int only(int n,int m)
{
	LINK s;
	create(&s,n); 
	int i;
	LINK r,p;
	p=s;
	while(p->next!=p)
	{
		for(i=1;i<m;i++)
		{
			r=p;
			p=p->next;
		}
		r->next=p->next;
		free(p);
		p=r->next;
		//print(s);
	}
	s=p;
	return s->data;
}
int main()
{
	int l;
	int n,m;
	printf("����������������һ�����������ڶ��������������(�ÿո����)\n");
	scanf("%d %d",&n,&m);
	l=only(n,m);
	printf("ʣ�µ�%dλ��",l);
	return 0;
}
