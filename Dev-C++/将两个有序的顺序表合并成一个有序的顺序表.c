#include<stdio.h>

#define MAXSIZE 100

typedef int elemtype;

typedef struct

{

elemtype elem[MAXSIZE];

int len;//˳���ĳ���

} sqlist;

void init_sqlist(sqlist *L )//��ʼ��˳���

{  L->len=0;  }

void creatsqlist(sqlist *L)//����˳���

{

int i;
printf("����˳�����:");
scanf("%d",&(L->len));
printf("��������:");
for(i=0;i<=L->len-1;i++)
scanf("%d",&(L->elem[i]));
}
void join(sqlist l1,sqlist l2,sqlist *l3)

//�����������˳���ϲ���һ�������˳���

{

int i=0;

int j=0;

int k=0;

while(i<l1.len||j<l2.len)

{
if(i==l1.len)
l1.elem[i]=9999;
else if(j==l2.len)
l2.elem[j]=9999;
if(l1.elem[i]<l2.elem[j])

{

l3->elem[k]=l1.elem[i];

i++;

}

else

{

l3->elem[k]=l2.elem[j];

j++;

}

k++;

}

l3->len=l1.len+l2.len;

}

void list(sqlist l)  /*�Ա���б���*/

{

int i;

for(i=0;i<l.len;i++)

printf("%d " ,l.elem[i]);

}

int main()

{

sqlist l1,l2,l3;

init_sqlist(&l1);

init_sqlist(&l2);

init_sqlist(&l3);

creatsqlist(&l1);

creatsqlist(&l2);

join(l1,l2,&l3);

list(l3);

return 0;

}
