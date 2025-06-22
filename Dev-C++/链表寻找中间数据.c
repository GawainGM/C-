#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct node{

    int data;

   struct node *next;

}Lnode,*Linklist;

Linklist Initlist();

void Creatlist(Linklist L);

Lnode *find(Linklist L);

int main()//寻找未知长度的链表的中间数据 

{

 Lnode *pos;

 Linklist L;

 L=Initlist();

 Creatlist(L);

 pos=find(L);

 if(pos!=NULL) {

 printf("%d",pos->data);

 }else {

 printf("null");

 }

 return 0;

}

Linklist Initlist()//初始化链表 

{

 Linklist L;

 L=(Linklist)malloc(sizeof(Linklist));

 L->next=NULL;

 return L;

}

void Creatlist(Linklist L)//输入链表 

{

 char c='y';

 Lnode *p,*r;

 r=L;

 while(c=='y') {

 p=(Lnode *)malloc(sizeof(Lnode));

 scanf("%d",&p->data);

 p->next=NULL;

 r->next=p;

 r=p;
 printf("是否继续输入(y/n)\n");

 scanf("%s",&c);

 }

}

Lnode *find(Linklist L)//寻找中间数据 

{

Linklist i,j;

i=L;

j=L;

if(L->next==NULL||L->next->next==NULL) return NULL;

while(i!=NULL&&i->next!=NULL)

{

i=i->next->next;

j=j->next;

}

return j;

}
