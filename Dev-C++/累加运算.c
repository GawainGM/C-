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
	printf("累加运算\n请输入数字:"); 
	scanf("%d",&a);
	b=plus(a);
	printf("结果是%d\n",b);
	return 0;
}
 
