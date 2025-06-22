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
	printf("请输入(%d人):\n姓名 性别 年龄 电话\n",N);
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",robot[i].name);
		scanf("%s",robot[i].sex);
		scanf("%d",&robot[i].age);
		scanf("%s",robot[i].phonenum);
	}
	printf("输入结束\n");
}
void putdata(strpeo *robot)
{
	int i;
	printf("姓名\t性别\t年龄\t电话\n");
	for(i=0;i<N;i++)
	{
		printf("%-8s",robot[i].name);
		printf("%-8s",robot[i].sex);
		printf("%-8d",robot[i].age);
		printf("%-8s\n",robot[i].phonenum);
	}
	printf("输出结束\n");
}
int main()
{

strpeo robot[N];
ins(robot);
putdata(robot);
return 0;
}
