#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int meun()
{
	int a;
	system("cls");
	printf("������Ϸ\n");
	printf("****************\n");
	printf("[1]�ӷ�\n");
	printf("[2]����\n");
	printf("[3]�˷�\n");
	printf("[4]����\n");
	printf("[5]��������\n");
	printf("[6]���ô������\n");
	printf("[0]�˳�\n");
	printf("****************\n");
	printf("������ѡ��[ ]\b\b");
	scanf("%d",&a);
	return a;
}
void good()//��Թ������ 
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
			printf("����һ��\n"); 
		}
		if(flag==0)
		{
			printf("�˾Ͷ���:(%d)  %d+%d=%d\n",i,a,b,c);
			system("pause");
		}
	}
	system("pause");
}
