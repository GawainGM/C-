#include<stdio.h>
int main()
{
	char ch;
	int a=0,b=0,c=0,d=0;
	while((ch=getchar())!=10)
	{
		if(ch>='A'&&ch<='Z')
		a++;
		else if(ch>='a'&&ch<='z')
		b++;
		else if(ch>='0'&&ch<='9')
		c++;
		else
		d++;
	}
	printf("��д��ĸ%d��\nСд��ĸ%d��\n����%d��\n�����ַ�%d��\n",a,b,c,d);//�����������ַ���������ռ�����ֽ� 
	
	return 0;
}
