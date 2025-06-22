#include<stdio.h>
#define max 100
typedef int elemType;
typedef struct
{
	elemType elem[max];
	int len;
}seqList;
void init(seqList *l)
{
	l->len=0;
}
void creat(seqList *l)
{
	int i;
	printf("请输入顺序表长度:");
	scanf("%d",&l->len);
	printf("请输入数据:");
	for(i=0;i<l->len;i++)
	scanf("%d",&l->elem[i]);
}
int insert(seqList *l,int num)
{
	int i=0,k;
	if(l->len==max)
	return -1;
	while(num>l->elem[i]&&i<l->len)
		i++;
	for(k=l->len;k>=i;k--)
		l->elem[k]=l->elem[k-1];
	l->elem[i]=num;
	l->len++;
	return i;
}
int find(seqList l, int x)
{
	int i;
	for(i=0;i<l.len;i++)
	{
		if(l.elem[i]==x)
		return i+1;
	}
return 0;
	
}
int del(seqList *l,int i)
{
	int num;
	if(i>=1&&i<=l->len)
	{
		for(num=i;num<l->len;num++)
		l->elem[num-1]=l->elem[num];
		l->len--;
		return 1;
	}
	else return 0;
}
void List(seqList l)
{
	int i;
	for(i=0;i<l.len;i++)
	{
		printf("%d",l.elem[i]);
		printf("\n");
	}
}
int main()
{
	int i;
	int x;
	seqList l;
	init(&l);
	creat(&l);
	List(l);
	printf("请输入要查找的数据(按数据查找):");
	scanf("%d",&x);
	i=find(l,x);
	if(i==0)
		printf("no find\n");
	else printf("key=%d\n",i);
	printf("请输入要插入的数据(按数据插入):");
	scanf("%d",&x);
	if(insert(&l,x)>=0)
	List(l);
	else printf("插入失败\n");
	printf("请输入要删除的数据(按序号删除):");
	scanf("%d",&x); 
	if(del(&l,x))
	List(l);
	else printf("删除失败");
	return 0;
}
