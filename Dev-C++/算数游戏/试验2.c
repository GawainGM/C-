#include<stdio.h>
#include"suanshu.h"
int main()
{
	int select;
	int num=5;
	int cha=3;
	int loop=1;
	while(loop)
	{
		select=meun();
		switch(select)
		{
			case 1 ://加法
			add(num,cha); break;
		/*	case 2 ://减法
			sub(num,cha); break;
			case 3 ://乘法
			mul(num,cha); break;
			case 4 ://除法
			div(num,cha); break;
			case 5 ://设置题目数量 
			num=setnum(); break;
			case 6 ://设置答题次数 
			cha=setcha(); break;
		*/	default : //结束 
			printf("谢谢使用！\n");
			loop=0;
		}
	}
	return 0;
}
