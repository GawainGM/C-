#include<stdio.h>
#include<windows.h>
int main()
{
	int a,b=0;
	printf("������µ���(100-999):");
	scanf("%3d",&a);
	system("cls");
	printf("������Ϸ\n������һ����λ����(100-999)\n");
	 while(b!=a)
	 {
	 	 scanf("%3d",&b);
	 	if(b<a) 
	 	printf("��С��\n");
	 	else if(b>a)
		printf("�´���\n");
		else
		{
			printf("��ϲ�㣬�¶���");
		break;
		}
	 }
	  	 return 0;
}
