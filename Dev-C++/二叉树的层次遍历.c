#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct tree
{
char data;
struct tree *lchild,*rchild;
}datatree,*bintree;

typedef struct
{
	bintree data[SIZE];
	int f;
	int r;
}sqStack;

void init(sqStack *s)//初始化
{
	s->f=0;
	s->r=1;
}
int en(sqStack *s,bintree i)//入队 
{
	if(s->f==s->r)//判断满
	return 0;
	s->data[s->r]=i;
	s->r=(s->r+1)%SIZE;
	return 1;
}
int de(sqStack *s,bintree *i)//出队 
{
	if((s->f+1)%SIZE==s->r)//判断空
	return 0;
	s->f=(s->f+1)%SIZE;
	*i=s->data[s->f];
	return 1;
}
int empty(sqStack s)//队列判空
{
return (s.f+1)%SIZE==s.r?1:0;
}

void createtree(bintree *T)//创建二叉树，前序遍历创建
{
char ch;
ch=getchar();
if(ch=='.')
*T=NULL;
else
{
*T=(bintree)malloc(sizeof(datatree));
(*T)->data=ch;
createtree(&(*T)->lchild);
createtree(&(*T)->rchild);
}
}

void preorder(bintree T)//前序遍历 
{
if(T==NULL)
return;
printf("%c",T->data);
preorder(T->lchild);
preorder(T->rchild);
}
void corder(bintree T)//层次遍历
{
sqStack s;
bintree i;
init(&s);
en(&s,T);
do{
de(&s,&i);
printf("%c",i->data);
if(i->lchild!=NULL)
en(&s,i->lchild);
if(i->rchild!=NULL)
en(&s,i->rchild);
}while(!empty(s));

}

int main()
{
bintree T;
createtree(&T);
preorder(T);
printf("\n");
corder(T);
printf("\n");
return 0;
}
