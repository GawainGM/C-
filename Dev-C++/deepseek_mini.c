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
	printf("**********̽��δ֪֮��************\n");
	printf("**********************************\n");
	printf("��DS����Ϣ:\n");
	scanf("%s",cs);
	printf("˼����");
	for(i=0;i<6;i++)
	{
		Sleep(1000);
		printf(".");
	}
	printf("\nϵͳ��æ�����Ժ�����\n");
	printf("\n�Ƿ����¶Ի�(y/n):");
	getchar();
	scanf("%c",&end);
	}while(end=='y'||end=='Y');
	printf("\n��ӭ�´�����");
	return 0;
}
