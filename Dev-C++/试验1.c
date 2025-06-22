#include<stdio.h>
#define MAX 100
typedef char vextype;
typedef int edgetype;
typedef struct
{
  vextype vex[MAX];
  edgetype arcs[MAX][MAX];
  int vexnum;
  int arcsnum;
}map;
typedef struct
{
  int elem[MAX];
  int top;
}seq;
void initseq(seq *S)//初始化栈
{
  S->top=-1;
}
int push(seq *S,int x)//入栈
{
  if(S->top==MAX-1)
    return 0;
  S->top++;
  S->elem[S->top]=x;
  return 1;
}
int pop(seq *S,int *x)//出栈
{
  if(S->top==-1)
    return 0;
  *x=S->elem[S->top];
  S->top--;
  return 1;
}
int isempty(seq S)//判断栈空
{
  if(S.top==-1)
    return 1;
  else
    return 0;
}
int locate(map M,char vi)//定位
{
  for(int i=0;i<M.vexnum;i++)
    {
      if(M.vex[i]==vi)
        return i;
    }
  return -1;
}
void createmap(map *M)//创建图
{
  int i,j,k;
  vextype vi,vj;
  printf("请输入顶点数和边数:");
  scanf("%d,%d",&(M->vexnum),&(M->arcsnum));
  getchar();//吞回车键
  printf("输入顶点:");
  for(i=0;i<M->vexnum;i++)
    {
      M->vex[i]=getchar();
    }
  getchar();//吞回车键
  for(i=0;i<M->arcsnum;i++)
    {
      printf("请输入第%d条边:",i+1);
      scanf("%c,%c",&vi,&vj);
      getchar();
      j=locate(*M,vi);
      k=locate(*M,vj);
      M->arcs[j][k]=1;
      M->arcs[k][j]=1;
    }
  return;
}
int visited[MAX]={0};
void DFSM(map M,int i)
{
  seq S;
  initseq(&S);
  int j=0;
  printf("%c",M.vex[i]);
  visited[i]=1;
  push(&S,i);
  while(!isempty(S))
    {
          if(M.arcs[i][j]==1&&visited[j]==0)
           {
             printf("%c",M.vex[j]);
             visited[j]=1;
             push(&S,j);
             i=j;
             j=0;
             continue;
           }
      if(j==M.vexnum)
        {
			pop(&S,&i);
			j=0;
			continue;
        }
      j++;
    }
    return; 
}
void DFSMdisp(map M)
{
  int i,j;
  char vi;
  printf("请输入开始遍历的节点：");
  scanf("%c",&vi);
  i=locate(M,vi);
  DFSM(M,i);
  for(j=0;j<M.vexnum;j++)
    {
      if(visited[j]==0)
        DFSM(M,j);
    }
  
  return;
}
int main()
{
  map M;
  createmap(&M);
  DFSMdisp(M);
  printf("\n");
  return 0;
}
