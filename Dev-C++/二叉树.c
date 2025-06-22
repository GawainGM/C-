#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
char data;
struct tree *lchild,*rchild;
}datatree,*bintree;

void createtree(bintree *T)//������������ǰ���������
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

void preorder(bintree T)//ǰ����� 
{
if(T==NULL)
return;
printf("%c",T->data);
preorder(T->lchild);
preorder(T->rchild);
}

void inorder(bintree T)//������� 
{
if(T==NULL)
return;
inorder(T->lchild);
printf("%c",T->data);
inorder(T->rchild);
}

void postorder(bintree T)//������� 
{
if(T==NULL)
return;
postorder(T->lchild);
postorder(T->rchild);
printf("%c",T->data);
}

void changetree(bintree T)//������������ 
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

int gethigh(bintree T)//��������߶�
{
if(T==NULL)
return 0;
return gethigh(T->lchild)>gethigh(T->rchild)?gethigh(T->lchild)+1:gethigh(T->rchild)+1;
//���ؽϴ�������߶� 
}

void inleafes(bintree T)//���Ҷ�ӽڵ�
{
if(T==NULL)
return;
inleafes(T->lchild);
if(T->lchild==NULL&&T->rchild==NULL)//����ýڵ�����������Ϊ�գ���˵��ΪҶ�ӽڵ� 
printf("%c",T->data);
inleafes(T->rchild);
}

void copytree(bintree T,bintree *T2)//����T����T2�� 
{
if(T==NULL)
{*T2=NULL;
return;}
*T2=(bintree)malloc(sizeof(datatree));
(*T2)->data=T->data;
copytree(T->lchild,&(*T2)->lchild);
copytree(T->rchild,&(*T2)->rchild);
}

int main()//������ 
{
bintree T,T2;
createtree(&T);//��������Ϊ��ABC...ED..F..
preorder(T);
printf("\n������\n");
changetree(T);
preorder(T);
printf("\n");
copytree(T,&T2);
printf("T2\n");
preorder(T2);
return 0;
}
