#include<stdio.h>
void plan(int n);
int main()
{
	int a=0;
	printf("ÇëÊäÈëÊı×Ö:");
	scanf("%d",&a);
	plan(a);
	return 0; 
} 
void plan(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{	for(j=1;j<=i;j++)
			printf("%d*%d=%2d ",i,j,i*j);
		printf("\n");
	}		
}

