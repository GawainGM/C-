#include<stdio.h> 
int main()
/*{						//��һ�ַ��� ��ֻ����������λ�� 
int a,b,c,A;

printf("����һ����λ��\n"); 

scanf("%d",&A);

a=A/1%10;

b=A/10%10;

c=A/100%10;

printf("%d%d%d",a,b,c);

return 0;
}*/

/*{					//�ڶ��ַ��� (ֻ����������λ��
	int a,b,c;
	scanf("%1d%1d%1d",&a,&b,&c);
	printf("%d%d%d",c,b,a);
	return 0;
}*/
{					//�����ַ��� ��������������λ���� 
	int x;
	printf("������һλ����\n");
	scanf("%d",&x);
	while(x!=0)
	{	
		
		printf("%d",x%10);
		x=x/10;
		
	} 
	return 0;
	
}
