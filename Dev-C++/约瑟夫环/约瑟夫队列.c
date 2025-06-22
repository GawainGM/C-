#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
typedef struct
{
	int data[SIZE];
	int f;
	int r;
}sqStack;
void init(sqStack *s)//初始化 
{
	s->f=0;
	s->r=1;
}
int en(sqStack *s,int i)//入队 
{
	if(s->f==s->r)
	return 0;
	s->data[s->r]=i;
	s->r++;
	return 1;
}
int de(sqStack *s,int *i)//出队 
{
	if((s->f+1)%SIZE==s->r)
	return 0;
	s->f++;
	*i=s->data[s->f];
	return 1;
}
void print(sqStack s)//打印 
{
	int i;
	while((s.f+1)%SIZE!=s.r)
	{
		de(&s,&i);
		printf("%d ",i);
	}
	printf("\n");
}
int yue(int n,int m)//输入总数与间隔，返回结果 
{
	sqStack s;
	init(&s);
	int i=0;//人数 
	int j;//数数 
	int x;//控制出来的数 
	for(i=1;i<=n;i++)//
	en(&s,i);
	while((s.f+2)%SIZE!=s.r)
	{
		for(j=1;j<m;j++)//数到m就跳出 
		{
			de(&s,&x);
			en(&s,x);
		}
		de(&s,&x);//删除第m的数 
		print(s);//打印 
	}
	de(&s,&x);
	return x;
}
int main()
{
	int i;
	int m,n;
	printf("请输入两个数，第一个是总数，第二个是数间隔的数(用空格隔开)\n");
	scanf("%d %d",&n,&m);
	i=yue(n,m);
	printf("剩下第%d位置",i);
	return 0;
}
