#include<stdio.h>
#define MAX 100
typedef char vextype;
typedef int edgetype;
typedef struct 
{
  vextype vex[MAX];//����
  edgetype arcs[MAX][MAX];//������
  int vexnum,edgenum;//ʵ�ʶ�������ʵ�ʱ���
  int dig;//����0��������1��
}map;

typedef struct
{
  vextype data[MAX];
  int f,r;
}dui;

void initdui(dui *Q)//��ʼ��
{
  Q->f=Q->r=0;
}

int endui(dui *Q,int x)//���
{
  if((Q->r+1)%MAX==Q->f)
    return 0;
  Q->r=(Q->r+1)%MAX;
  Q->data[Q->r]=x;
  return 1;
}

int outdui(dui *Q,int *x)//����
{
  if(Q->r==Q->f)
    return 0;
  Q->f=(Q->f+1)%MAX;
  *x=Q->data[Q->f];
  return 1;
}

int iskong(dui Q)//���п�
{
  if(Q.r==Q.f)
    return 1;
  else
    return 0;
}

int locate(map G,vextype v)
{
  int i=0;
  for(;i<G.vexnum;i++)
  {
    if(G.vex[i]==v)
      return i;
  }
  return -1;//û�ҵ�����-1
}
void createmap(map *G)//����ͼ 
{
  int i,j,k;
  char vi,vj;
  G->dig=1;//����ͼ 
  printf("�����붥����������\n"); 
  scanf("%d,%d",&(G->vexnum),&(G->edgenum));
  getchar();//�̵��س���
  printf("�����붥��(��������):");
  for(i=0;i<G->vexnum;i++)
  {
    scanf("%c",&(G->vex[i]));//���붥��
    for(j=0;j<G->vexnum;j++)//��ʼ��
      G->arcs[i][j]=0;
  }
  getchar();//�̵��س���
  for(i=0;i<G->edgenum;i++)//����ߣ�������
  {
  	printf("�����%d����:",i+1);
    scanf("%c,%c",&vi,&vj);
    getchar();
    j=locate(*G,vi);
    k=locate(*G,vj);
    G->arcs[j][k]=1;
    if(G->dig==1)
    G->arcs[k][j]=1;
  }
  return;
}
int visited[MAX]={0};//��ʼ��
void DESM(map G,int i)//�ݹ�������� 
{
  if(visited[i]==0)
  {
    printf("%c",G.vex[i]);
  visited[i]=1;
  for(int j=0;j<G.vexnum;j++)//���������ı� 
  {
    if(G.arcs[i][j]==1)
      DESM(G,j);
  }
  }
  return;
}
void DESMdisp(map G)//����������� 
{
  char vi;
  int i;
  int pos;
  printf("�����뿪ʼ�Ķ���:");
  scanf("%c",&vi);
  printf("�������:\n");
  pos=locate(G,vi);
  DESM(G,pos);
  for(i=0;i<G.vexnum;i++)//����ȫ�������ͼ�ж����ͨ���������Ա�����һ������ 
  {
    if(visited[i]==0)
      DESM(G,i);
  }
  printf("\n");
}

void BFSM(map M,int i)//��ȱ���
{
  dui Q;
  int ans;
  initdui(&Q);
  if(endui(&Q,i))
  while(!iskong(Q))
    {
      if(outdui(&Q,&ans)&&visited[ans]==0)
      printf("%c",M.vex[ans]);
      visited[ans]=1;
      for(int j=0;j<M.vexnum;j++)
        if(M.arcs[ans][j]==1&&visited[j]==0)
          endui(&Q,j);
    }
  return;
}
void BFSMdisp(map M)//��ȱ��� 
{
  int i,pos;
  vextype vi;
  scanf("%c",&vi);
  pos=locate(M,vi);
  BFSM(M,pos);
  for(i=0;i<M.vexnum;i++)
    {
      if(visited[i]==0)
        BFSM(M,i);
    }
    printf("\n");
  return;
}

int main()
{
  map G;
  createmap(&G);
  DESMdisp(G);
  return 0;
}
