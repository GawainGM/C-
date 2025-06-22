#include<stdio.h>
#include<stdlib.h>
#define PEOPLE 200//控制总数
typedef struct
{
	int data[PEOPLE];
	int len;
}list;
void init(list *s,int i)//初始化 
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
	int i=0;//报数的次数 
	int g=-1;//报数的位置 
	init(&s,n);
	int x=s.len;
	while(x>1)//只留下一个 
	{
		while(i<m)//每数三次跳出
		{
			g=(g+1)%n;
			if(s.data[g]==0) 
			i++;//数数
		}
		s.data[g]=1;
		x--;
		print(s);
		i=0;
	}
	g=0;
	while(s.data[g]==1)//查找最后的位置
	g++;
	return g+1;
}
int main()//主 
{
	int n;
	int m;
	printf("请输入两个数，第一个是总数，第二个是数间隔的数(用空格隔开)\n");
	scanf("%d %d",&n,&m);
	n=ring(n,m);
	printf("剩下第%d位置",n);
	return 0;
}
