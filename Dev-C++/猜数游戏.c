#include<stdio.h>
#include<windows.h>
int main()
{
	int a,b=0;
	printf("请输入猜的数(100-999):");
	scanf("%3d",&a);
	system("cls");
	printf("猜数游戏\n请输入一个三位数字(100-999)\n");
	 while(b!=a)
	 {
	 	 scanf("%3d",&b);
	 	if(b<a) 
	 	printf("猜小了\n");
	 	else if(b>a)
		printf("猜大了\n");
		else
		{
			printf("恭喜你，猜对了");
		break;
		}
	 }
	  	 return 0;
}
