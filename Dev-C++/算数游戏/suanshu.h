#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int meun()
{
	int a;
	system("cls");
	printf("算数游戏\n");
	printf("****************\n");
	printf("[1]加法\n");
	printf("[2]减法\n");
	printf("[3]乘法\n");
	printf("[4]除法\n");
	printf("[5]设置题量\n");
	printf("[6]设置答题机会\n");
	printf("[0]退出\n");
	printf("****************\n");
	printf("请输入选择[ ]\b\b");
	scanf("%d",&a);
	return a;
}
void good()//答对鼓励语句 
{
	int k;
	srand(time(NULL));
	k=rand()%6+1;
	switch(k)
	{
		case 1 : printf("Good!\n");break;
		case 3 : printf("Perfert!\n");break;
		case 2 : printf("Great!\n");break;
	}
}
void add(int n,int cha)
{
	int a,b,c,i,sum;
	int flag;
	int ans;
	srand(time(NULL));
	for(i=1;i<=n;i++)
	{
		ans=0;
		flag=0;
		a=rand()%100+1;
		b=rand()%100+1;
		c=a+b;
		while(ans<cha&&flag==0)
		{
			printf("(%d)  %d+%d=",i,a,b);
			scanf("%d",&sum);
			ans++;
			if(sum==c)
			{
				good();
				flag=1;
				break;
			}
			else if(ans<cha)
			printf("再来一次\n"); 
		}
		if(flag==0)
		{
			printf("菜就多练:(%d)  %d+%d=%d\n",i,a,b,c);
			system("pause");
		}
	}
	system("pause");
}
