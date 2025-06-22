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
	printf("大写字母%d个\n小写字母%d个\n数字%d个\n其他字符%d个\n",a,b,c,d);//中文算其他字符，且中文占两个字节 
	
	return 0;
}
