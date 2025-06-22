#include<stdio.h>
#define MAX 100
typedef char vextype;
typedef int edgetype;
typedef struct 
{
  vextype vex[MAX];//顶点
  edgetype arcs[MAX][MAX];//边数据
  int vexnum,edgenum;//实际顶点数，实际边数
  int dig;//有向（0）或无向（1）
}map;

typedef struct
{
  vextype data[MAX];
  int f,r;
}dui;

void initdui(dui *Q)//初始化
{
  Q->f=Q->r=0;
}

int endui(dui *Q,int x)//入队
{
  if((Q->r+1)%MAX==Q->f)
    return 0;
  Q->r=(Q->r+1)%MAX;
  Q->data[Q->r]=x;
  return 1;
}

int outdui(dui *Q,int *x)//出队
{
  if(Q->r==Q->f)
    return 0;
  Q->f=(Q->f+1)%MAX;
  *x=Q->data[Q->f];
  return 1;
}

int iskong(dui Q)//队判空
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
  return -1;//没找到返回-1
}
void createmap(map *G)//创建图 
{
  int i,j,k;
  char vi,vj;
  G->dig=1;//无向图 
  printf("请输入顶点数，边数\n"); 
  scanf("%d,%d",&(G->vexnum),&(G->edgenum));
  getchar();//吞掉回车符
  printf("请输入顶点(连续输入):");
  for(i=0;i<G->vexnum;i++)
  {
    scanf("%c",&(G->vex[i]));//输入顶点
    for(j=0;j<G->vexnum;j++)//初始化
      G->arcs[i][j]=0;
  }
  getchar();//吞掉回车符
  for(i=0;i<G->edgenum;i++)//输入边，创建边
  {
  	printf("输入第%d条边:",i+1);
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
int visited[MAX]={0};//初始化
void DESM(map G,int i)//递归输出顶点 
{
  if(visited[i]==0)
  {
    printf("%c",G.vex[i]);
  visited[i]=1;
  for(int j=0;j<G.vexnum;j++)//遍历相连的边 
  {
    if(G.arcs[i][j]==1)
      DESM(G,j);
  }
  }
  return;
}
void DESMdisp(map G)//深度优先搜索 
{
  char vi;
  int i;
  int pos;
  printf("请输入开始的顶点:");
  scanf("%c",&vi);
  printf("遍历结果:\n");
  pos=locate(G,vi);
  DESM(G,pos);
  for(i=0;i<G.vexnum;i++)//遍历全部，如果图有多个连通分量，可以遍历另一个分量 
  {
    if(visited[i]==0)
      DESM(G,i);
  }
  printf("\n");
}

void BFSM(map M,int i)//广度遍历
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
void BFSMdisp(map M)//广度遍历 
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
