#include<stdio.h>
#define MAX 100
#include <stdlib.h>
#include <time.h>
#include<limits.h>
void create(int **s,int userand)
{
	int num=0;
	printf("���������������С(0<num<100)��");
	scanf("%d",&num);
	(*s)=(int*)malloc(sizeof(int)*(num+1));
	if(userand)
	{
		for(int j=0;j<num;j++)
		(*s)[j]=rand()%50+1;
	}
	else
	{
		printf("����������(�ո����)��");
		for(int j=0;j<num;j++)
		scanf("%d",&(*s)[j]);
	}
	(*s)[num] = 0;
}
void disp(int *s)
{
	for(int i=0;s[i];i++)
	printf("%d ",s[i]);
	printf("\n");
	return;
}
void sort(int **s)
{
	int hash[MAX]={0};
	int max=INT_MIN,min=INT_MAX;
	int i=0;
	for(i=0;(*s)[i];i++)
	{
		max=max>(*s)[i]?max:(*s)[i];
		min=min<(*s)[i]?min:(*s)[i];
		hash[(*s)[i]]++;
	}
	int j=0;
	while(min<=max)
	{
		if(hash[min])
		{(*s)[j]=min;
		hash[min]--;
		j++;}
		else
		min++;
	}
	return;
}
int main()
{
	srand(time(NULL));
	int (*s);
	create(&s,0);//1����������ɣ�0�����û����� 
	printf("����ǰ��\n");
	disp(s);
	sort(&s);//��С���� 
	printf("�����(��С����)��\n");
	disp(s);
	free(s);
	return 0;
}
