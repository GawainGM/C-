#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 50
typedef struct//����ջ
{
int elem[STACKSIZE];
int top;
}seqStack;

void conversion(seqStack *s);

void initStack(seqStack *s)//��ʼ��ջ
{
s->top=-1;
}

int push(seqStack *s,int x)//��ջ
{
if(s->top==STACKSIZE-1)
return 0;
s->top++;
s->elem[s->top]=x;
return 1;
}

int pop(seqStack *s,int *x)//��ջ
{
if(s->top==-1)
return 0;
*x=s->elem[s->top];
s->top--;
return 1;
}

int isEmpty(seqStack s)//�ж�ջΪ��
{
if(s.top==-1)
return 1;
else
return 0;
}

void input(seqStack *s)//����ջ
{
	int x;
	char zf='y';
	while(zf=='y'||zf=='Y')
	{
		printf("����������:\n");
		scanf("%d",&x);
		push(s,x);
		printf("�Ƿ��������(y/n)\n");
		scanf("%s",&zf);
	}
}

void printstack(seqStack *s)//���ջ
{
	int x;
	while(isEmpty(*s)==0)
		{
			pop(s,&x);
			printf("%d",x);
		}
	printf("\n");
}

void conversion(seqStack *s)//ʮ����ת���ɶ�����
{
	int n;
	printf("����Ҫת���ɶ����Ƶ�ʮ������:\n");
	in:scanf("%d",&n);
	if(n<0)
	{
		printf("������������������:");
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
	printf("ջ������Ϊ:\n");
	printstack(&s);
	return 0;
}
