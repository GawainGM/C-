#include<stdio.h>
int plus(int n)
{
	int p,i;
	for(i=1,p=0;i<=n;i++)
	p=p+i;
	return p;
}
int main()
{
	int a,b;
	printf("�ۼ�����\n����������:"); 
	scanf("%d",&a);
	b=plus(a);
	printf("�����%d\n",b);
	return 0;
}
 
