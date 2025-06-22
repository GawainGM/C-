#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
  int elem[MAXSIZE];
  int f, r;
} queue;

typedef struct node {
  int data; // 存储子节点在数组中的索引
  struct node *next;
} nodetree;

typedef struct info {
  int data;
  nodetree *head;
} infotree;

void init(queue *q) {
  q->f = q->r = 0;
}

int in(queue *q, int x) {
  if ((q->r + 1) % MAXSIZE == q->f)
    return 0;
  q->r = (q->r + 1) % MAXSIZE;
  q->elem[q->r] = x;
  return 1;
}

int out(queue *q, int *x)
{
  if (q->f == q->r)//为空时
    return 0; 
  q->f = (q->f + 1) % MAXSIZE;
  *x = q->elem[q->f];
  return 1;
}

void createtree(infotree *T,int p[],int n)
{
   int i=0;//正在创建这个节点在数组中的下标
  int parent=-1;//正在创建的这个结点的父结点的下标
  int pre;//存放数据
  int j=0;//正在创建的这个结点的父结点的下标
   nodetree *r,*teil;//用于创建孩子节点
   queue q;
   init(&q);
   in(&q, p[i]);//根结点入队
   T[j].data=p[i];
   T[j].head=NULL;
   i++;
  while(i<n)//队列不为空
  {
    if(p[i]==-1)//代表该节点的兄弟节点结束
    {
      out(&q,&pre);
      parent++;
      i++;
    }
    else if(p[i]==-2)//－2表示该节点的孩子结点为空
        {  T[parent].head=NULL;
            if(q.r!=q.f)
            {
            out(&q,&pre);
            parent++;
             }
            i++;
        }
    else
    {
      in(&q,p[i]);
      j++;
      T[j].data=p[i];
      T[j].head=NULL;
      r=(nodetree*)malloc(sizeof(nodetree));
      r->data=j;
      r->next=NULL;
      teil=T[parent].head;
      if (teil==NULL) {//使该节点的孩子节点链接在后面
         T[parent].head=r;
       }
      else
      {
        while(teil->next!=NULL)//找到孩子节点的最后一个
        {
        teil=teil->next;
        }
        teil->next=r;
      }
      i++;
    }
  }
}

void pre(infotree *T, int i)
{
  if (T+i==NULL) return;
  printf("%d ", T[i].data);
  nodetree *t = T[i].head;
  while (t)
  {
    pre(T, t->data);
    t = t->next;
  }
}

int main()
{
  int n;
  int m;
  infotree *T;
  int p[MAXSIZE];
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
  	scanf("%d", &p[i]);
  	if(p[i]>=0)
  	m++;
  }
  T=(infotree*)malloc(sizeof(infotree)*m);  
  createtree(T, p, n);
  pre(T, 0);
  printf("\n");
  
  return 0;
}
