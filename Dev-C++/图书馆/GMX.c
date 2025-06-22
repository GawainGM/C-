#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define USERMAX 100
#define BOOKMAX 1000
#define BORROWBOOK 1000
//图书结构体 
typedef struct
{
	long id;
	char name[30];
	float money;
	int tai;
}book;
//时间结构体 
typedef struct
{
	int year;
	int month;
	int day;
}dateTime;
//借出的书 
typedef struct
{
	char userID[10];
	long bookID;
	char name[30];
	dateTime jie;
	dateTime huan;
	dateTime shi;
	int tai;//0是首次借,1是续借,2是归还 
}borrowBook;
//用户 
typedef struct
{
	char id[10];
	char name[8];
	char buMen[10];
	int jue;
	char email[15];
	char miMa[6];
	int currBorrow;
	borrowBook max[10];
}user;

void showtime(int k)//输出问候语 
{
	system("cls");
	time_t currtime;
	struct tm *time_info;
	time(&currtime);
	time_info=localtime(&currtime);
	int hour=time_info->tm_hour;
	if(hour>=0&&hour<8)
	printf("早上好\n");
	else if(hour>=8&&hour<11)
	printf("上午好\n");
	else if(hour>=11&&hour<14)
	printf("中午好\n");
	else if(hour>=14&&hour<18)
	printf("下午好\n");
	else
	printf("晚上好\n");
	if(k==1)
	printf("欢迎使用图书管理系统\n");
	else
	printf("谢谢使用图书管理系统\n");
}
int mainMenu()//首要菜单 
{
	int k;
	printf("    小型图书管理系统    \n");
	printf("========================\n");
	printf("      1  登录系统\n");
	printf("      0  退出系统\n");
	printf("========================\n");
	printf("请输入选项[ ]\b\b");
	scanf("%d",&k);
	return k;
}
void getCaptcha(char *captcha,int length)//生成一串长度length随机验证码 
{
	char cs[]="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
	int cslen=strlen(cs);
	int i;
	for(i=0;i<length;i++)
		captcha[i]=cs[rand()%cslen];
	captcha[length]='\0';
}
void signIn()//待完善 
{
	system("cls");
	char captcha[10];
	char usercap[10];
	getCaptcha(captcha,4);
	printf("小型图书管理系统->用户登录    \n");
	printf("==============================\n");
	printf("请输入用户名:\n");
	printf("请输入密码:\n");
	
	printf("请输入验证码:  ");
	printf("[%s]\n",captcha);
	scanf("%s",usercap);
	while(strcmp(usercap,captcha)!=0)
	{
		printf("验证码错误,请重新输入:\n");
		scanf("%s",usercap);
	}
	
}
int login(char currUserID[])//ID匹配返回身份代码 
{
	FILE *fp=fopen("user.dat","rb");
	user s;
	while(fread(&s,sizeof(user),1,fp)==1)
	{
		if(strcmp(s.id,currUserID)==0)
		{
			fclose(fp);
		return s.jue;
		}
	}
	fclose(fp);
	return -1;
}
void displayTopic(int c,char currUserID[])//显示不同身份的主题 待完善 
{
	switch(c)
	{
		case 0:
			adminSystem(currUserID);
			break;
		case 1:
			librarySystem(currUserID);
			break;
		case 2:
			studentSystem(currUserID);
			break;
		case 3:
			teacherSystem(currUserID);
		default :
			break;
	}
	
}
void enterSystem(int c,char currUserID[])//判断身份 
{
	if(c==0)
	printf("管理员%s",currUserID);
	else
	printf("%s",currUserID);
	displayTopic(c,currUserID);
}

int readUserFromFile(user userArray[],char *f)//把用户数据从文件中读出 
{
	int n=0;
	FILE *fp;
	fp=fopen(f,"r");
	while(fread(userArray+n,sizeof(user),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}
void writeUserToFile(user userArray[],int n,char *f)//写入用户数据 
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(userArray,sizeof(user),n,fp);
	fclose(fp);
}
int readBookFromFile(book bookArray[],char *f)//把书籍从文件中读出
{
	int n=0;
	FILE *fp;
	fp=fopen(f,"r");
	while(fread(bookArray+n,sizeof(book),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}
void writeBookToFile(book bookArray[],int bookTotal,char *f)//写入书籍数据 
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(bookArray,sizeof(book),bookTotal,fp);
	fclose(fp);
}
int readBorrowFromFile(borrowBook borrowArray[],char *f)//把借书数据从文件中读出
{
	int n=0;
	FILE *fp;
	fp=fopen(f,"r");
	while(fread(borrowArray+n,sizeof(borrowBook),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}
void writeBorrowBookToFile(borrowBook borrowArray[],int borrowTotal,char *f)//写入借书数据
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(borrowArray,sizeof(borrowBook),borrowTotal,fp);
	fclose(fp);
}
//ok
void inputPassWord(char password[],int n)//输入密码
{
	int i=0;
	char ch;
	do{
		ch=getch();
		if(ch!='\r'&&i<=n)
		password[i]=ch;
		else
		break;
		i++;
		putchar('*');
	}while(1);
	password[i]='\0';
	putchar('\n');
}
//ok
int menuStudent()//学生界面
{
	printf("小型图书管理系统--学生用户\n");
	printf("==========================\n");
	printf("1.图书查询\n");
	printf("2.查询当前已借目录\n");
	printf("3.续借\n");
	printf("4.修改个人信息\n");
	printf("0.退出登录\n");
	printf("==========================\n");
	printf("请输入选项[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
int menuTeacher()// 教师界面
{
	printf("小型图书管理系统--教师用户\n");
	printf("==========================\n");
	printf("1.图书查询\n");
	printf("2.查询当前已借目录\n");
	printf("3.续借\n");
	printf("4.修改个人信息\n");
	printf("0.退出登录\n");
	printf("==========================\n");
	printf("请输入选项[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
void dispUser(user userArray[],int i)
{
	user s;
	s=userArray[i];
	printf("用户信息->修改信息:\n");
	printf("1.用户名字:%s\n",s.name);
	printf("2.部门:%s\n",s.buMen);
	printf("3.E-mail:%s\n",s.email);
	printf("4.密码:******\n");
	printf("0.退出\n");
} 
void dispBook(user userArray[],int i)//
{
	user s;
	s=userArray[i];
	printf("用户信息->续借:\n");
	printf("用户ID:%s\n",s.id);
	printf("用户名字:%s\n",s.name);
	printf("部门:%s\n",s.buMen);
	printf("当前借书量:%d\n",s.currBorrow);
	printf("===========================================\n");
	printf("图书编号     书名     借阅日期     应还日期");
	printf("===========================================\n");
	for(int i=0;i<s.currBorrow;i++)
	{printf("%ld  %6s  %d年%2d月%d日  ",s.max[i].bookID,s.max[i].name,s.max[i].jie.year,s.max[i].jie.month,s.max[i].jie.day);
	printf("%d年%2d月%d日\n",s.max[i].huan.year,s.max[i].huan.month,s.max[i].huan.day);
	}
	printf("===========================================\n");
} 
void modifyUserInfo(user userArray[],char userID[])//修改用户参数 
{
	int i;
	int n;
	user s;
	char mi[6],ma[6];
	int total=100;
	i=userSearch(userArray,total,userID);
	s=userArray[i];
	do{
	dispUser(userArray,i);
	printf("请选择要修改的选项:");
	scanf("%d",&n);
	switch (n) {
		case 1:
			printf("请输入新名字:");
			scanf("%s",s.name);
			printf("修改成功\n");
			break;
		case 2:
			printf("请输入新部门:");
			scanf("%s",s.buMen);
			printf("修改成功\n");
			break;
		case 3:
			printf("请输入新E-mail:");
			scanf("%s",s.email);
			printf("修改成功\n");
			break;
		case 4:
			printf("请输入新密码:");
			inputPassWord(mi,6);
			printf("请再次输入新密码:");
			inputPassWord(ma,6);
			if(strcmp(mi,ma)==0)
			{printf("修改成功\n");
			strcpy(s.miMa,mi);}
			else
			printf("修改失败\n");
			break;
		default:
			printf("退出\n");
			break;
	}
	userArray[i]=s;
	}while(n==1||n==2||n==3||n==4);
	
}
void userRenewBook(user userArray[],int userTotal,char userID[])
{
	int i;
	i=userSearch(userArray,userTotal,userID);
	dispBook(userArray,i);
	long n;
	user s;
	s=userArray[i];
	do{
		printf("请输入图书编号(输入0返回):"); 
		scanf("%ld",&n);
		if(n==0)
		break;
		s.max->huan.month++;
		printf("《%s》,续借成功!\n",s.max->name);
	}while(1);
	
}
void teacherSystem(char currUserID[])//待完善 
{
	int i;
	do{
	i=menuTeacher();
	switch (i) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			userRenewBook(userArray,userTotal,currUserID);
			break;
		case 4:
			modifyUserInfo(userArray,currUserID);
			break;
		default:
			
			break;
	}
	
	}
}
void studentSystem(char currUserID[])//待完善
{
	int i;
	do{
	i=menuTeacher();
	switch (i) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			modifyUserInfo(userArray,currUserID);
			break;
		default:
			
			break;
	}
	}
}

int main()//待完善
{
	char s[10];
	teacherSystem(s);
	return 0;
}
