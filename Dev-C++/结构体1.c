#include<stdio.h>
#include<stdlib.h>
#define N 1
struct people
{
	char name[10];
	char sex[9];
	int age;
	char phonenum[12];
};
typedef struct people strpeo;
void ins(strpeo *robot)
{
	printf("������(%d��):\n���� �Ա� ���� �绰\n",N);
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",robot[i].name);
		scanf("%s",robot[i].sex);
		scanf("%d",&robot[i].age);
		scanf("%s",robot[i].phonenum);
	}
	printf("�������\n");
}
void putdata(strpeo *robot)
{
	int i;
	printf("����\t�Ա�\t����\t�绰\n");
	for(i=0;i<N;i++)
	{
		printf("%-8s",robot[i].name);
		printf("%-8s",robot[i].sex);
		printf("%-8d",robot[i].age);
		printf("%-8s\n",robot[i].phonenum);
	}
	printf("�������\n");
}
int main()
{

strpeo robot[N];
ins(robot);
putdata(robot);
return 0;
}
