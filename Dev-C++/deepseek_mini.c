#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
int main()
{
	char end;
	int i;
	char cs[100];
	do{
	system("cls");
	printf("**********************************\n");
	printf("***************DS*****************\n");
	printf("**********探索未知之境************\n");
	printf("**********************************\n");
	printf("给DS发消息:\n");
	scanf("%s",cs);
	printf("思考中");
	for(i=0;i<6;i++)
	{
		Sleep(1000);
		printf(".");
	}
	printf("\n系统繁忙，请稍后再试\n");
	printf("\n是否开启新对话(y/n):");
	getchar();
	scanf("%c",&end);
	}while(end=='y'||end=='Y');
	printf("\n欢迎下次再来");
	return 0;
}
