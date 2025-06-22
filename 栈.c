#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 50
typedef struct//定义栈
{
int elem[STACKSIZE];
int top;
}seqStack;

void conversion(seqStack *s);

void initStack(seqStack *s)//初始化栈
{
s->top=-1;
}

int push(seqStack *s,int x)//入栈
{
if(s->top==STACKSIZE-1)
return 0;
s->top++;
s->elem[s->top]=x;
return 1;
}

int pop(seqStack *s,int *x)//出栈
{
if(s->top==-1)
return 0;
*x=s->elem[s->top];
s->top--;
return 1;
}

int isEmpty(seqStack s)//判断栈为空
{
if(s.top==-1)
return 1;
else
return 0;
}

void input(seqStack *s)//输入栈
{
	int x;
	char zf='y';
	while(zf=='y'||zf=='Y')
	{
		printf("请输入数据:\n");
		scanf("%d",&x);
		push(s,x);
		printf("是否继续输入(y/n)\n");
		scanf("%s",&zf);
	}
}

void printstack(seqStack *s)//输出栈
{
	int x;
	while(isEmpty(*s)==0)
		{
			pop(s,&x);
			printf("%d",x);
		}
	printf("\n");
}

void conversion(seqStack *s)//十进制转化成二进制
{
	int n;
	printf("输入要转化成二进制的十进制数:\n");
	in:scanf("%d",&n);
	if(n<0)
	{
		printf("输入有误，请重新输入:");
		goto in;
	}
	if(n==0)
	printf("0");
	else
	while(n>0)
	{
		push(s,n%2);
		n=n/2;
	}
}

int main()
{
	seqStack s;
	initStack(&s);
	conversion(&s);
	printf("栈内数据为:\n");
	printstack(&s);
	return 0;
}
