#include<stdio.h>
#include<stdlib.h>
#define SIZE 200
typedef struct
{
	int data[SIZE];
	int top;
}Stack;
int isempty(Stack h);
void init(Stack *h)//��ʼ�� 
{
	h->top=-1;
}
int push(Stack *h,int n)//��ջ 
{
	if(h->top==SIZE-1)
	return 0;
	else
	h->top++;
	h->data[h->top]=n;
	return 1;
}
int pop(Stack *h,int *m)//��ջ 
{
	if(h->top==-1)
	return 0;
	else
	*m=h->data[h->top];
	h->top--;
	return 0;
}
void print(Stack s)//��ӡ 
{
	int k;
	for(k=s.top;k>=0;k--)
	printf("%d ",s.data[k]);
	printf("\n");
}
int isempty(Stack h)//�п� 
{
	if(h.top==-1)
	return 1;
	else
	return 0;
}
int yue(int n,int m)//Լɪ�� 
{
	Stack h;
	Stack mid;
	int i;
	int k;
	init(&h);
	init(&mid);
	for(i=n;i>0;i--)
	push(&h,i);
	while(h.top+mid.top!=-1)//ֻʣһ�� 
	{
		for(i=1;i<m;i++)//���� 
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
	if(!isempty(h))//�ж�����Ԫ������ 
	pop(&h,&k);
	else
	pop(&mid,&k);
	return k;
}
int main()//�� 
{
	int n;
	int m;
	printf("����������������һ�����������ڶ��������������(�ÿո����)\n");
	scanf("%d %d",&n,&m);
	n=yue(n,m);
	printf("ʣ�µ�%dλ��",n);
	return 0;
}
