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
			case 1 ://�ӷ�
			add(num,cha); break;
		/*	case 2 ://����
			sub(num,cha); break;
			case 3 ://�˷�
			mul(num,cha); break;
			case 4 ://����
			div(num,cha); break;
			case 5 ://������Ŀ���� 
			num=setnum(); break;
			case 6 ://���ô������ 
			cha=setcha(); break;
		*/	default : //���� 
			printf("ллʹ�ã�\n");
			loop=0;
		}
	}
	return 0;
}
