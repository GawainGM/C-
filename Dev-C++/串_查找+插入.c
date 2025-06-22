#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct
{
char elem[MAX];
int len;
}strType;

int find(strType *s1,strType s2,int pos)//’“s2 
{
int i,j;
int k;
for(i=pos-1;i<s1->len-s2.len;i++)
{
k=i;
for(j=0;j<s2.len;j++)
{
if(s1->elem[k]==s2.elem[j])
k++;
else
break;
}
if(j>=s2.len)
return i+1;
}
return 0;
}

int zzy(strType *s1,strType s2,int pos)//≤Â»Îs2 
{
if(pos<1||pos>s1->len+1||pos>MAX)
return 0;
int i,j;
for(i=s1->len-1;i>pos-1;i--)
s1->elem[i+s2.len]=s1->elem[i];
for(i=pos,j=0;j<s2.len;i++,j++)
s1->elem[i]=s2.elem[j];
s1->len=s1->len+s2.len;
return 1;
}

int main()
{
strType s1,s2;
int pos;
gets(s1.elem);
s1.len=strlen(s1.elem);
gets(s2.elem);
s2.len=strlen(s2.elem);
scanf("%d",&pos);
printf("%d",find(&s1,s2,pos));
return 0;
}
