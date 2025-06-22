#include<stdio.h> 
int main()
/*{						//第一种方法 （只可以输入三位数 
int a,b,c,A;

printf("输入一个三位数\n"); 

scanf("%d",&A);

a=A/1%10;

b=A/10%10;

c=A/100%10;

printf("%d%d%d",a,b,c);

return 0;
}*/

/*{					//第二种方法 (只可以输入三位数
	int a,b,c;
	scanf("%1d%1d%1d",&a,&b,&c);
	printf("%d%d%d",c,b,a);
	return 0;
}*/
{					//第三种方法 （可以输入任意位数字 
	int x;
	printf("请输入一位数字\n");
	scanf("%d",&x);
	while(x!=0)
	{	
		
		printf("%d",x%10);
		x=x/10;
		
	} 
	return 0;
	
}
