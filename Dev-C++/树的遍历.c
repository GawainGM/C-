#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
  int elem[MAXSIZE];
  int f, r;
} queue;

typedef struct node {
  int data; // �洢�ӽڵ��������е�����
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
  if (q->f == q->r)//Ϊ��ʱ
    return 0; 
  q->f = (q->f + 1) % MAXSIZE;
  *x = q->elem[q->f];
  return 1;
}

void createtree(infotree *T,int p[],int n)
{
   int i=0;//���ڴ�������ڵ��������е��±�
  int parent=-1;//���ڴ�����������ĸ������±�
  int pre;//�������
  int j=0;//���ڴ�����������ĸ������±�
   nodetree *r,*teil;//���ڴ������ӽڵ�
   queue q;
   init(&q);
   in(&q, p[i]);//��������
   T[j].data=p[i];
   T[j].head=NULL;
   i++;
  while(i<n)//���в�Ϊ��
  {
    if(p[i]==-1)//����ýڵ���ֵܽڵ����
    {
      out(&q,&pre);
      parent++;
      i++;
    }
    else if(p[i]==-2)//��2��ʾ�ýڵ�ĺ��ӽ��Ϊ��
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
      if (teil==NULL) {//ʹ�ýڵ�ĺ��ӽڵ������ں���
         T[parent].head=r;
       }
      else
      {
        while(teil->next!=NULL)//�ҵ����ӽڵ�����һ��
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
