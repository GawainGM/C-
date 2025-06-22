#include<stdio.h>
#include<stdlib.h>
#define SIZE 200
typedef struct
{
	int data[SIZE];
	int top;
}Stack;
int isempty(Stack h);
void init(Stack *h)//初始化 
{
	h->top=-1;
}
int push(Stack *h,int n)//入栈 
{
	if(h->top==SIZE-1)
	return 0;
	else
	h->top++;
	h->data[h->top]=n;
	return 1;
}
int pop(Stack *h,int *m)//出栈 
{
	if(h->top==-1)
	return 0;
	else
	*m=h->data[h->top];
	h->top--;
	return 0;
}
void print(Stack s)//打印 
{
	int k;
	for(k=s.top;k>=0;k--)
	printf("%d ",s.data[k]);
	printf("\n");
}
int isempty(Stack h)//判空 
{
	if(h.top==-1)
	return 1;
	else
	return 0;
}
int yue(int n,int m)//约瑟夫 
{
	Stack h;
	Stack mid;
	int i;
	int k;
	init(&h);
	init(&mid);
	for(i=n;i>0;i--)
	push(&h,i);
	while(h.top+mid.top!=-1)//只剩一个 
	{
		for(i=1;i<m;i++)//数数 
		{
			if(!isempty(h))
			{
				pop(&h,&k);
				push(&mid,k);
			}
			else
			{
				while(!isempty(mid))
				{
					pop(&mid,&k);
					push(&h,k);
				}
				pop(&h,&k);
				push(&mid,k);
			}
		}
		if(!isempty(h))
		{
			pop(&h,&k);
		}
		else
		{
			while(isempty(mid)!=1)
			{
				pop(&mid,&k);
				push(&h,k);
			}
			pop(&h,&k);
		}
	}
	if(!isempty(h))//判断最后的元素在哪 
	pop(&h,&k);
	else
	pop(&mid,&k);
	return k;
}
int main()//主 
{
	int n;
	int m;
	printf("请输入两个数，第一个是总数，第二个是数间隔的数(用空格隔开)\n");
	scanf("%d %d",&n,&m);
	n=yue(n,m);
	printf("剩下第%d位置",n);
	return 0;
}
