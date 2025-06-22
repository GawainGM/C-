#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
char data;
struct tree *lchild,*rchild;
}datatree,*bintree;

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

void inorder(bintree T)//中序遍历 
{
if(T==NULL)
return;
inorder(T->lchild);
printf("%c",T->data);
inorder(T->rchild);
}

void postorder(bintree T)//后序遍历 
{
if(T==NULL)
return;
postorder(T->lchild);
postorder(T->rchild);
printf("%c",T->data);
}

void changetree(bintree T)//交换左右子树 
{
if(T==NULL)
return;
changetree(T->lchild);
changetree(T->rchild);
bintree Z;
Z=(T)->lchild;
(T)->lchild=(T)->rchild;
(T)->rchild=Z;
}

int gethigh(bintree T)//求二叉树高度
{
if(T==NULL)
return 0;
return gethigh(T->lchild)>gethigh(T->rchild)?gethigh(T->lchild)+1:gethigh(T->rchild)+1;
//返回较大的子树高度 
}

void inleafes(bintree T)//输出叶子节点
{
if(T==NULL)
return;
inleafes(T->lchild);
if(T->lchild==NULL&&T->rchild==NULL)//如果该节点左右子树都为空，则说明为叶子节点 
printf("%c",T->data);
inleafes(T->rchild);
}

void copytree(bintree T,bintree *T2)//复制T树到T2树 
{
if(T==NULL)
{*T2=NULL;
return;}
*T2=(bintree)malloc(sizeof(datatree));
(*T2)->data=T->data;
copytree(T->lchild,&(*T2)->lchild);
copytree(T->rchild,&(*T2)->rchild);
}

int main()//主函数 
{
bintree T,T2;
createtree(&T);//输入样例为：ABC...ED..F..
preorder(T);
printf("\n交换后\n");
changetree(T);
preorder(T);
printf("\n");
copytree(T,&T2);
printf("T2\n");
preorder(T2);
return 0;
}
