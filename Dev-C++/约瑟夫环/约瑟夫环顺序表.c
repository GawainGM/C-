#include<stdio.h>
#include<stdlib.h>
#define PEOPLE 200//��������
typedef struct
{
	int data[PEOPLE];
	int len;
}list;
void init(list *s,int i)//��ʼ�� 
{
	int n;
	s->len=i;
	for(n=0;n<i;n++)
	s->data[n]=0;
}
void print(list s)
{
	int i;
	for(i=0;i<s.len;i++)
	if(s.data[i]==0)
	printf("%d ",i+1);
	printf("\n");
}
int ring(int n,int m)
{
	list s;
	int i=0;//�����Ĵ��� 
	int g=-1;//������λ�� 
	init(&s,n);
	int x=s.len;
	while(x>1)//ֻ����һ�� 
	{
		while(i<m)//ÿ����������
		{
			g=(g+1)%n;
			if(s.data[g]==0) 
			i++;//����
		}
		s.data[g]=1;
		x--;
		print(s);
		i=0;
	}
	g=0;
	while(s.data[g]==1)//��������λ��
	g++;
	return g+1;
}
int main()//�� 
{
	int n;
	int m;
	printf("����������������һ�����������ڶ��������������(�ÿո����)\n");
	scanf("%d %d",&n,&m);
	n=ring(n,m);
	printf("ʣ�µ�%dλ��",n);
	return 0;
}
