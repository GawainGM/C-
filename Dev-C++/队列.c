#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
typedef struct
{
	int data[SIZE];
	int f;
	int r;
}sqStack;
void init(sqStack *s)//��ʼ�� 
{
	s->f=0;
	s->r=1;
}
int en(sqStack *s,int i)//��� 
{
	if(s->f==s->r)
	return 0;
	s->data[s->r]=i;
	s->r++;
	return 1;
}
int de(sqStack *s,int *i)//���� 
{
	if((s->f+1)%SIZE==s->r)
	return 0;
	s->f++;
	*i=s->data[s->f];
	return 1;
}
void print(sqStack s)//��ӡ 
{
	int i;
	while((s.f+1)%SIZE!=s.r)
	{
		de(&s,&i);
		printf("%d ",i);
	}
	printf("\n");
}
