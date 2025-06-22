#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define USERMAX 100
#define BOOKMAX 1000
#define BORROWBOOK 1000
//ͼ��ṹ�� 
typedef struct
{
	long id;
	char name[30];
	float money;
	int tai;
}book;
//ʱ��ṹ�� 
typedef struct
{
	int year;
	int month;
	int day;
}dateTime;
//������� 
typedef struct
{
	char userID[10];
	long bookID;
	char name[30];
	dateTime jie;
	dateTime huan;
	dateTime shi;
	int tai;//0���״ν�,1������,2�ǹ黹 
}borrowBook;
//�û� 
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

void showtime(int k)//����ʺ��� 
{
	system("cls");
	time_t currtime;
	struct tm *time_info;
	time(&currtime);
	time_info=localtime(&currtime);
	int hour=time_info->tm_hour;
	if(hour>=0&&hour<8)
	printf("���Ϻ�\n");
	else if(hour>=8&&hour<11)
	printf("�����\n");
	else if(hour>=11&&hour<14)
	printf("�����\n");
	else if(hour>=14&&hour<18)
	printf("�����\n");
	else
	printf("���Ϻ�\n");
	if(k==1)
	printf("��ӭʹ��ͼ�����ϵͳ\n");
	else
	printf("ллʹ��ͼ�����ϵͳ\n");
}
int mainMenu()//��Ҫ�˵� 
{
	int k;
	printf("    С��ͼ�����ϵͳ    \n");
	printf("========================\n");
	printf("      1  ��¼ϵͳ\n");
	printf("      0  �˳�ϵͳ\n");
	printf("========================\n");
	printf("������ѡ��[ ]\b\b");
	scanf("%d",&k);
	return k;
}
void getCaptcha(char *captcha,int length)//����һ������length�����֤�� 
{
	char cs[]="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
	int cslen=strlen(cs);
	int i;
	for(i=0;i<length;i++)
		captcha[i]=cs[rand()%cslen];
	captcha[length]='\0';
}
void signIn()//������ 
{
	system("cls");
	char captcha[10];
	char usercap[10];
	getCaptcha(captcha,4);
	printf("С��ͼ�����ϵͳ->�û���¼    \n");
	printf("==============================\n");
	printf("�������û���:\n");
	printf("����������:\n");
	
	printf("��������֤��:  ");
	printf("[%s]\n",captcha);
	scanf("%s",usercap);
	while(strcmp(usercap,captcha)!=0)
	{
		printf("��֤�����,����������:\n");
		scanf("%s",usercap);
	}
	
}
int login(char currUserID[])//IDƥ�䷵����ݴ��� 
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
void displayTopic(int c,char currUserID[])//��ʾ��ͬ��ݵ����� ������ 
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
void enterSystem(int c,char currUserID[])//�ж���� 
{
	if(c==0)
	printf("����Ա%s",currUserID);
	else
	printf("%s",currUserID);
	displayTopic(c,currUserID);
}

int readUserFromFile(user userArray[],char *f)//���û����ݴ��ļ��ж��� 
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
void writeUserToFile(user userArray[],int n,char *f)//д���û����� 
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(userArray,sizeof(user),n,fp);
	fclose(fp);
}
int readBookFromFile(book bookArray[],char *f)//���鼮���ļ��ж���
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
void writeBookToFile(book bookArray[],int bookTotal,char *f)//д���鼮���� 
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(bookArray,sizeof(book),bookTotal,fp);
	fclose(fp);
}
int readBorrowFromFile(borrowBook borrowArray[],char *f)//�ѽ������ݴ��ļ��ж���
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
void writeBorrowBookToFile(borrowBook borrowArray[],int borrowTotal,char *f)//д���������
{
	FILE *fp;
	fp=fopen(f,"w");
	fwrite(borrowArray,sizeof(borrowBook),borrowTotal,fp);
	fclose(fp);
}
//ok
void inputPassWord(char password[],int n)//��������
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
int menuStudent()//ѧ������
{
	printf("С��ͼ�����ϵͳ--ѧ���û�\n");
	printf("==========================\n");
	printf("1.ͼ���ѯ\n");
	printf("2.��ѯ��ǰ�ѽ�Ŀ¼\n");
	printf("3.����\n");
	printf("4.�޸ĸ�����Ϣ\n");
	printf("0.�˳���¼\n");
	printf("==========================\n");
	printf("������ѡ��[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
int menuTeacher()// ��ʦ����
{
	printf("С��ͼ�����ϵͳ--��ʦ�û�\n");
	printf("==========================\n");
	printf("1.ͼ���ѯ\n");
	printf("2.��ѯ��ǰ�ѽ�Ŀ¼\n");
	printf("3.����\n");
	printf("4.�޸ĸ�����Ϣ\n");
	printf("0.�˳���¼\n");
	printf("==========================\n");
	printf("������ѡ��[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
void dispUser(user userArray[],int i)
{
	user s;
	s=userArray[i];
	printf("�û���Ϣ->�޸���Ϣ:\n");
	printf("1.�û�����:%s\n",s.name);
	printf("2.����:%s\n",s.buMen);
	printf("3.E-mail:%s\n",s.email);
	printf("4.����:******\n");
	printf("0.�˳�\n");
} 
void dispBook(user userArray[],int i)//
{
	user s;
	s=userArray[i];
	printf("�û���Ϣ->����:\n");
	printf("�û�ID:%s\n",s.id);
	printf("�û�����:%s\n",s.name);
	printf("����:%s\n",s.buMen);
	printf("��ǰ������:%d\n",s.currBorrow);
	printf("===========================================\n");
	printf("ͼ����     ����     ��������     Ӧ������");
	printf("===========================================\n");
	for(int i=0;i<s.currBorrow;i++)
	{printf("%ld  %6s  %d��%2d��%d��  ",s.max[i].bookID,s.max[i].name,s.max[i].jie.year,s.max[i].jie.month,s.max[i].jie.day);
	printf("%d��%2d��%d��\n",s.max[i].huan.year,s.max[i].huan.month,s.max[i].huan.day);
	}
	printf("===========================================\n");
} 
void modifyUserInfo(user userArray[],char userID[])//�޸��û����� 
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
	printf("��ѡ��Ҫ�޸ĵ�ѡ��:");
	scanf("%d",&n);
	switch (n) {
		case 1:
			printf("������������:");
			scanf("%s",s.name);
			printf("�޸ĳɹ�\n");
			break;
		case 2:
			printf("�������²���:");
			scanf("%s",s.buMen);
			printf("�޸ĳɹ�\n");
			break;
		case 3:
			printf("��������E-mail:");
			scanf("%s",s.email);
			printf("�޸ĳɹ�\n");
			break;
		case 4:
			printf("������������:");
			inputPassWord(mi,6);
			printf("���ٴ�����������:");
			inputPassWord(ma,6);
			if(strcmp(mi,ma)==0)
			{printf("�޸ĳɹ�\n");
			strcpy(s.miMa,mi);}
			else
			printf("�޸�ʧ��\n");
			break;
		default:
			printf("�˳�\n");
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
		printf("������ͼ����(����0����):"); 
		scanf("%ld",&n);
		if(n==0)
		break;
		s.max->huan.month++;
		printf("��%s��,����ɹ�!\n",s.max->name);
	}while(1);
	
}
void teacherSystem(char currUserID[])//������ 
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
void studentSystem(char currUserID[])//������
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

int main()//������
{
	char s[10];
	teacherSystem(s);
	return 0;
}
