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
int yue(int n,int m)//�����������������ؽ�� 
{
	sqStack s;
	init(&s);
	int i=0;//���� 
	int j;//���� 
	int x;//���Ƴ������� 
	for(i=1;i<=n;i++)//
	en(&s,i);
	while((s.f+2)%SIZE!=s.r)
	{
		for(j=1;j<m;j++)//����m������ 
		{
			de(&s,&x);
			en(&s,x);
		}
		de(&s,&x);//ɾ����m���� 
		print(s);//��ӡ 
	}
	de(&s,&x);
	return x;
}
int main()
{
	int i;
	int m,n;
	printf("����������������һ�����������ڶ��������������(�ÿո����)\n");
	scanf("%d %d",&n,&m);
	i=yue(n,m);
	printf("ʣ�µ�%dλ��",i);
	return 0;
}
