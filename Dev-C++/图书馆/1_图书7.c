#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
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
	long bookArrayID;
	char name[30];
	dateTime jie;
	dateTime huan;
	dateTime shi;
	int tai;//0���״ν�,1������,2�ǹ黹 
}borrowbookArray;

//ͼ��ṹ��
typedef struct
{
	long id;
	char name[30];
	int tai;
}book;

//�û�
typedef struct
{
	char id[10];
	char name[8];
	char buMen[10];
	int jue;
	char email[15];
	char miMa[10];
	int borrow_limit;
	int borrowed_count;
	borrowbookArray max[10];
}user;

#define MAX_userArray 100
#define MAX_bookArray 100

user userArray[MAX_userArray];
int user_count = 0;//�û�����
book bookArray[MAX_bookArray];
int bookArray_count = 0;//ͼ������
user curruser; // ��ǰ��¼�û�

int readUserFromFile()//���û����ݴ��ļ��ж��� 
{
	int n=0;
	FILE *fp;
	fp=fopen("userArray.txt","r");
	if(fp==NULL)
	return 0;
	while(fread(userArray+n,sizeof(user),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}

void writeuserToFile()//д���û�����
{
	FILE *fp;
	fp=fopen("userArray.txt","w");
	if(fp==NULL)
	printf("��ʧ��");
	fwrite(userArray,sizeof(user),user_count,fp);
	fclose(fp);
}

int readbookArrayFromFile()//���鼮���ݴ��ļ��ж���
{
	int n=0;
	FILE *fp;
	fp=fopen("bookArrays.txt","r");
	if(fp==NULL)
	return 0;
	while(fread(bookArray+n,sizeof(book),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}

void writebookArrayToFile()//д���鼮���� 
{
	FILE *fp;
	fp=fopen("bookArrays.txt","w");
	fwrite(bookArray,sizeof(book),bookArray_count,fp);
	fclose(fp);
}

int readBorrowFromFile(borrowbookArray borrowArray[])//�ѽ������ݴ��ļ��ж���
{
	int n=0;
	FILE *fp;
	fp=fopen("borrowbookArray.txt","r");
	if(fp==NULL)
	return 0;
	while(fread(borrowArray+n,sizeof(borrowbookArray),1,fp)==1)
	{
		n++;
	}
	fclose(fp);
	return n;
}

void writeBorrowbookArrayToFile(borrowbookArray borrowArray[],int borrowTotal)//д���������
{
	FILE *fp;
	fp=fopen("borrowbookArray.txt","w");
	fwrite(borrowArray,sizeof(borrowbookArray),borrowTotal,fp);
	fclose(fp);
}

int userSearch(char id[]) //�û���ѯ���������ң�
{
    int i=0;
	for(i=0;i<user_count;i++)
	{
		if(strcmp(userArray[i].id,id)==0)
		return i;
	}
    return -1;
}
//��������
void inputPassWord(char password[],int n)
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

//����һ������length�����֤��
void getCaptcha(char *captcha,int length) 
{
	char cs[]="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
	int cslen=strlen(cs);
	int i;
	srand(time(NULL));
	for(i=0;i<length;i++)
		captcha[i]=cs[rand()%cslen];
	captcha[length]='\0';
}

// ����ģ�飺��¼��֤
int login() 
{
    char account[20], password[20];
    char captcha[10];
    char usercap[10];
	getCaptcha(captcha,4);
    printf("�������˺ţ�");
    scanf("%s", account);
    printf("���������룺");
    inputPassWord(password,10); 
    printf("��������֤��(���ִ�Сд):  ");
	printf("��%s��\n",captcha);
	scanf("%s",usercap);
	while(strcmp(usercap,captcha)!=0)
	{
		printf("��֤�����,����������:\n");
		scanf("%s",usercap);
	}
	
    // �����û�
    for (int i = 0; i < user_count; i++) {
        if (strcmp(userArray[i].id, account) == 0 &&
            strcmp(userArray[i].miMa, password) == 0) {
            curruser = userArray[i];
            return 1; //��¼�ɹ�
        }
    }
    printf("�˺Ż��������\n");
    system("pause");
    return 0;
}

// ����ģ�飺�޸���Ϣ
void dispUser(user userArray[],int i)//�޸Ľ��� 
{
	user s;
	s=userArray[i];
	printf("\n�û���Ϣ->�޸���Ϣ:\n");
	printf("1.�û�����:%s\n",s.name);
	printf("2.����:%s\n",s.buMen);
	printf("3.E-mail:%s\n",s.email);
	printf("4.����:******\n");
	printf("0.�˳�\n");
}

//�޸��û�����
void modifyUserInfo() 
{
	int i;
	int n;
	char mi[10],ma[10];
	i=userSearch(curruser.id);
	if(i<0)
	printf("û�и��û�\n");
	do{
	dispUser(userArray,i);
	printf("��ѡ��Ҫ�޸ĵ�ѡ��:");
	scanf("%d",&n);
	switch (n) {
		case 1:
			printf("������������:");
			scanf("%s",curruser.name);
			printf("�޸ĳɹ�\n");
			break;
		case 2:
			printf("�������²���:");
			scanf("%s",curruser.buMen);
			printf("�޸ĳɹ�\n");
			break;
		case 3:
			printf("��������E-mail:");
			scanf("%s",curruser.email);
			printf("�޸ĳɹ�\n");
			break;
		case 4:
			printf("������������:");
			inputPassWord(mi,10);
			printf("���ٴ�����������:");
			inputPassWord(ma,10);
			if(strcmp(mi,ma)==0)
			{printf("�޸ĳɹ�\n");
			strcpy(curruser.miMa,mi);}
			else
			printf("�޸�ʧ��\n");
			break;
		default:
			printf("�˳�\n");
			break;
	}
	userArray[i]=curruser;
	}while(n==1||n==2||n==3||n==4);
	return; 
}
//������� 
void dispBook()
{
	user s;
	s=curruser;
	printf("�û���Ϣ->����:\n");
	printf("�û�ID:%s\n",s.id);
	printf("�û�����:%s\n",s.name);
	printf("����:%s\n",s.buMen);
	printf("��ǰ������:%d\n",s.borrowed_count);
	printf("===========================================\n");
	printf("ͼ����     ����     ��������     Ӧ������\n");
	printf("===========================================\n");
	for(int i=1;i<=s.borrowed_count;i++)
	{printf("%ld  %6s  %d��%2d��%d��--",s.max[i].bookArrayID,s.max[i].name,s.max[i].jie.year,s.max[i].jie.month,s.max[i].jie.day);
	printf("%d��%2d��%d��\n",s.max[i].huan.year,s.max[i].huan.month,s.max[i].huan.day);
	}
	printf("===========================================\n");
} 
//����ģ��
void userRenewBook()
{
	dispBook();
	long n;
	user s;
	int i;
	s=curruser;
	do{
		printf("������ͼ����(����0����):"); 
		scanf("%ld",&n);
		for(i=0;i<s.borrowed_count;i++)
		if(s.max[i].bookArrayID==n)
		break;
		if(n==0||s.max[i].tai==0)
		{
			printf("����ʧ��\n");
			 break;
		}
		if(s.max[i].huan.month<12)
		s.max[i].huan.month++;
		else
		{
			s.max[i].huan.year++;
			s.max[i].huan.month=1;
		}
		s.max[i].tai++;
		printf("��%s��,����ɹ�!\n",s.max[i].name);
	}while(1);
	curruser=s;
}

// ����ģ�飺��ѯͼ��
void search_bookArray() 
{
    char keyword[50];
    int choice;
    printf("1.����Ų�ѯ 2.��������ѯ��");
    scanf("%d", &choice);
    if (choice == 1) {
        long id;
        printf("�����ţ�");
        scanf("%ld", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id) {
                printf("ͼ����Ϣ�����%ld ������%s�� ״̬��%s\n",
                       bookArray[i].id, bookArray[i].name,bookArray[i].tai == 0 ? "�ɽ�" : "�ѽ�");
                return;
            }
        }
    } else {
        printf("���������ؼ��ʣ�");
        scanf("%s", keyword);
        for (int i = 0; i < bookArray_count; i++) {
            if (strstr(bookArray[i].name, keyword)) {
                printf("ͼ����Ϣ�����%ld ������%s�� ״̬��%s\n",
                bookArray[i].id, bookArray[i].name,bookArray[i].tai == 0 ? "�ɽ�" : "�ѽ�");     
            }
        }
    }
    printf("δ�ҵ�ƥ��ͼ�飡\n");
}


void writedate(int i)//��bookArray�����i������
{
	int n=curruser.borrowed_count;
	curruser.max[n].bookArrayID=bookArray[i].id;
	strcpy(curruser.max[n].name,bookArray[i].name);
	curruser.max[n].tai=0;
	time_t currtime;
	struct tm *time_info;
	time(&currtime);
	time_info=localtime(&currtime);
	curruser.max[n].jie.day=time_info->tm_mday;
	curruser.max[n].huan.day=time_info->tm_mday;
	curruser.max[n].jie.year=time_info->tm_year+1900;
	curruser.max[n].jie.month=time_info->tm_mon+1;
	if(time_info->tm_mon<12)
	{
	curruser.max[n].huan.year=time_info->tm_year+1900;
	curruser.max[n].huan.month=time_info->tm_mon+2;
	}
	else 
	{
		curruser.max[n].huan.year=time_info->tm_year+1901;
		curruser.max[n].huan.month=time_info->tm_mon+2-12;
	}
	
}


// ѧ�����ܣ�����ͼ��
void student_borrow_bookArray() {
    if (curruser.borrowed_count >= curruser.borrow_limit) {
        printf("�Ѵ�������ޣ�%d������\n", curruser.borrow_limit);
        return;
    }
    int choice;
    printf("1. ����Ž��� 2. ���������ģ�");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("����ͼ���ţ�");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai==0) {
                bookArray[i].tai = 1;
                curruser.borrowed_count++;
                writedate(i);
                
                printf("���ĳɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("����ͼ��������");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0&&bookArray[i].tai==0) {
                bookArray[i].tai = 1;
                curruser.borrowed_count++;
                writedate(i);
                printf("���ĳɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("ͼ�鲻�ɽ裡\n");
}

// ѧ�����ܣ��黹ͼ��
void student_return_bookArray() {
    if (curruser.borrowed_count == 0) {
        printf("��û�н����κ�ͼ�飡\n");
        return;
    }
    int choice;
    printf("1. ����Ź黹 2. �������黹��");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("����ͼ���ţ�");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("�黹�ɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("����ͼ��������");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("�黹�ɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("��û�н��ĸ�ͼ�飡\n");
}

// ��ʦ���ܣ���������
void teacher_batch_borrow() {
    int num;
    printf("����������������%d������", curruser.borrow_limit - curruser.borrowed_count);
    scanf("%d", &num);
    if (num <= 0 || num > curruser.borrow_limit - curruser.borrowed_count) {
        printf("������Ч��\n");
        return;
    }
    for (int j = 0; j < num; j++) {
        int choice;
        printf("�� %d ����1. ����Ž��� 2. ���������ģ�", j + 1);
        scanf("%d", &choice);
        if (choice == 1) {
            int id;
            printf("����ͼ���ţ�");
            scanf("%d", &id);
            for (int i = 0; i < bookArray_count; i++) {
                if (bookArray[i].id == id && bookArray[i].tai == 0) {
                    bookArray[i].tai = 1;
                    curruser.borrowed_count++;
                    writedate(i);
                    printf("�� %d �����ĳɹ�����ǰ�ѽ裺%d��\n", j + 1, curruser.borrowed_count);
                    break;
                }
            }
        } else if (choice == 2) {
            char title[50];
            printf("����ͼ��������");
            scanf("%s", title);
            for (int i = 0; i < bookArray_count; i++) {
                if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 0) {
                    bookArray[i].tai = 1;
                    curruser.borrowed_count++;
                    writedate(i);
                    printf("�� %d �����ĳɹ�����ǰ�ѽ裺%d��\n", j + 1, curruser.borrowed_count);
                    break;
                }
            }
        }
    }
    printf("�������ĳɹ���\n");
}

// ��ʦ���ܣ��黹ͼ��
void teacher_return_bookArray() {
    if (curruser.borrowed_count == 0) {
        printf("��û�н����κ�ͼ�飡\n");
        return;
    }
    int choice;
    printf("1. ����Ź黹 2. �������黹��");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("����ͼ���ţ�");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("�黹�ɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("����ͼ��������");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("�黹�ɹ�����ǰ�ѽ裺%d��\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("��û�н��ĸ�ͼ�飡\n");
}

// ͼ�����Ա���ܣ�¼������
void librarian_add_bookArray() {
    if (bookArray_count >= MAX_bookArray) {
        printf("ͼ�������Ѵ����ޣ�\n");
        return;
    }
    book b;
    printf("����ͼ���ţ�");
    scanf("%ld", &b.id);
    printf("����������");
    scanf("%s", b.name);
	b.tai=0;
    bookArray[bookArray_count++] = b;
    printf("ͼ��¼��ɹ�����ǰ��%d��ͼ��\n", bookArray_count);
}

//ͼ����Ϣɾ��ģ��
void deleteBook()
{
    long targetld;//�洢Ҫɾ����ͼ����
    printf("������Ҫɾ����ͼ���ţ�");
    scanf("%ld", &targetld);
    int found = -1;
    for (int i = 0; i <bookArray_count; i++)
    {
        if (bookArray[i].id == targetld)
        {
            found = i;
            break;
        }
    }
    
    if (found != -1)//�ƶ�����Ԫ��
    {
        for (int i = found; i < bookArray_count; i++)
        {
            bookArray[i] = bookArray[i + 1];
        }
        bookArray_count--; 
            printf("ɾ���ɹ�!\n");
        
    }
    else  printf("δ�ҵ���ͼ�飡��\n");
    
}
//��ҳ��ʾ�û���Ϣ��
void printUser()
{
    int page = 0;
    int perPage = 5;//ÿҳ�ĸ���
    int totalPages = (user_count + perPage - 1) / perPage;//������ҳ��
    char cmd;
    do {
        printf("\n===�û��б���%d/%dҳ)===\n", page + 1,totalPages);
        for (int i = page * perPage; i < (page + 1) * perPage && i < user_count; i++) {
            printf("%d.%s %s\n", i + 1, userArray[i].id,userArray[i].name);
        }
        printf("\n[n]��һҳ[p]��һҳ[q]����:");
        getchar();//�̵�ǰ��Ļس���
        scanf("%c",&cmd);
        if (cmd == 'n' && page < totalPages - 1)page++;
        else if (cmd == 'p' && page > 0)page--;
        else if (cmd == 'q')break;
    } while (1);
    return;
}
// ϵͳ����Ա���ܣ������û�
void inputUser() 
{
    int count;
    printf("������Ҫ��ӵ��û�����");
        scanf_s("%d", &count);
    if (user_count+count >= MAX_userArray) 
	{
        printf("�û���������\n");
        return;
    }
    user u;
    for(int i=0;i<count;i++)
    {
    	printf("��%d��\n",i+1);
    	printf("===============\n");
        printf("�û��˺�:");
        scanf("%s",u.id);
        printf("����:");
        scanf("%s",u.name);
        printf("����:");
        scanf("%s",u.miMa);
    int role;
    printf("ѡ���ɫ��3=ѧ����2=��ʦ��1=ͼ�����Ա����");
    scanf("%d", &role);
    if (role < 1 || role > 3) {
        printf("��ɫѡ�����\n");
        return;
    }
    u.jue = role;
    u.borrow_limit=10;
    u.borrowed_count = 0;
    userArray[user_count++] = u;
    printf("�û������ɹ����˺ţ�%s ��ɫ��%d\n",u.id, u.jue);
    }
    return;
}

// ϵͳ����Ա���ܣ�ɾ���û�
void deleteUser() {
    char account[20];
    printf("����Ҫɾ�����û��˺ţ�");
    scanf("%s", account);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(userArray[i].id, account) == 0) 
		{
			if (strcmp(userArray[i].id, curruser.id) == 0)                
			{//�����û��Ƿ�Ϊ��ǰ��¼�û�
			    printf("����ɾ����ǰ�û���\n");
			    return;
			}
            // �Ƴ����û�
            for (int j = i; j < user_count - 1; j++) 
			{
                userArray[j] = userArray[j + 1];
            }
            user_count--;
            printf("�û�ɾ���ɹ���\n");
            return;
        }
    }
    printf("δ�ҵ����û���\n");
}

void initPassWord()//��ʼ���û�����
{
    char* initPass = "123456";//��ʼ����
    for (int i = 1; i < user_count; i++) 
	{
        strcpy(userArray[i].miMa, initPass);
 }
    printf("�����������û�����Ϊ��ʼֵ��\n");
}

//��ҳ��ʾͼ����Ϣģ��
void printBook()
{
    int page = 0;
    int itemsPerPage = 10;
    char input;
    do {
        system("cls");//����
        printf("===ͼ���б���%dҳ/��%dҳ��===\n", page + 1, (bookArray_count/ itemsPerPage) + 1);
        for (int i = page * itemsPerPage; i < (page + 1) * itemsPerPage && i < bookArray_count; i++)
    //ͨ�� for ѭ��������ǰҳ��ͼ����Ϣ��i �� page* itemsPerPage ��ʼ����(page + 1)* itemsPerPage ������ͬʱȷ��������ͼ������ bookTotal
        {
            printf("[%d] %ld--%s--", i + 1, bookArray[i].id, bookArray[i].name);
            bookArray[i].tai?printf("�ѽ�\n"):printf("δ��\n");
        }
        printf("\n����ѡ�N-��һҳ��P-��һҳ��Q-�˳�����");
        scanf("%c", &input);
        if ((input == 'N' || input == 'n') && (page + 1) * itemsPerPage < bookArray_count) {
            page++;
        }
        else if ((input == 'P' || input == 'p') && page > 0)
        {
            page--;
        }
    } while (input != 'Q' && input!='q');
}

//����ʺ���
void showtime(int k)
{
	system("cls");
	time_t currtime;
	struct tm *time_info;
	time(&currtime);
	time_info=localtime(&currtime);
	int hour=time_info->tm_hour;
	//�ʺ���
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
	//��ӭ���
	if(k==1)
	printf("��ӭʹ��ͼ�����ϵͳ\n");
	else
	printf("ллʹ��ͼ�����ϵͳ\n");
	
}
// ѧ���˵�
int menuStudent()//ѧ������
{
	printf("С��ͼ�����ϵͳ--ѧ���û�\n");
	printf("==========================\n");
	printf("1.ͼ���ѯ\n");
	printf("2.ͼ��黹\n");
	printf("3.����(С����)\n");
	printf("4.�޸ĸ�����Ϣ\n");
	printf("0.�˳�\n");
	printf("==========================\n");
	printf("������ѡ��[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
void student_menu() 
{
    while (1)
	{ 
        int choice;
        choice=menuStudent();
        switch (choice) 
		{
        case 1:
        	printBook(); 
            student_borrow_bookArray();
            break;
        case 2:
        	printBook();
            student_return_bookArray();
            break;
        case 3:
            userRenewBook(); 
            break;
        case 4:
            modifyUserInfo();
            break;
        case 5:
            search_bookArray();
            break;
        
        default:
            printf("��Чѡ��\n");
        }
    }
}

// ��ʦ�˵�
int menuTeacher()// ��ʦ����
{
	printf("С��ͼ�����ϵͳ--��ʦ�û�\n");
	printf("==========================\n");
	printf("1.ͼ���ѯ\n");
	printf("2.ͼ��黹\n");
	printf("3.����(С����)\n");
	printf("4.�޸ĸ�����Ϣ\n");
	printf("0.�˳�\n");
	printf("==========================\n");
	printf("������ѡ��[ ]\b\b");
	int i;
	scanf("%d",&i);
	return i;
}
void teacher_menu() 
{
    while (1) {
        int choice;
		choice=menuTeacher();
        switch (choice) {
        case 1:
        	
            teacher_batch_borrow();
            break;
        case 2:
            teacher_return_bookArray();
            break;
        case 3:
            userRenewBook();
            break;
        case 4:
            modifyUserInfo();
            break;
        case 0:
			return; 
        default:
            printf("��Чѡ��\n");
        }
    }
}

// ͼ�����Ա�˵�

void librarian_menu() {
    while (1) {
        printf("\n===== ͼ�����Ա���=====\n");
        printf("1. ¼��ͼ��\n2. ɾ��ͼ��\n");
        printf("3. �޸���Ϣ\n4. ͼ���ѯ\n");
        printf("5. �˳�\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            librarian_add_bookArray();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            modifyUserInfo();
            break;
        case 4:
            search_bookArray();
            break;
        case 5:
            return;
        default:
            printf("��Чѡ��\n");
        }
    }
}

int menuAdmin() 
{
    printf("\n=== ϵͳ����Ա�˵� ===\n");
    printf("1. ��ʾ�û�\n");
    printf("2. ����û�\n");
    printf("3. ɾ���û�\n");
    printf("4. ��ʾͼ��\n");
    printf("5. �������ͼ��\n");
    printf("6. ɾ��ͼ��\n");
    printf("7. ��ʼ���û�����\n");
    printf("8. �޸���Ϣ\n");
    printf("0. �˳�\n");
    printf("������ѡ��[ ]\b\b");
    int choice;
    scanf_s("%d", &choice);
    return choice;
}
// ϵͳ����Ա�˵�
void admin_menu() 
{
    while (1) {
        int choice;
        choice=menuAdmin();
        switch (choice)
		{
        case 1:
            printUser();
            break;
        case 2:
            inputUser();
            break;
        case 3:
            deleteUser();
            break;
        case 4:
            printBook();
            break;
        case 5:
            librarian_add_bookArray();
            break;
        case 6:
            deleteBook();
            break;
        case 7:
        	initPassWord();
            break;
        case 8:
			modifyUserInfo(); 
		    break;
		case 0:
			return;    
        default:
            printf("��Чѡ��\n");
        }
    }
}
int mainMenu()//��Ҫ�˵� 
{
	int k;
	system("cls");
	printf("    С��ͼ�����ϵͳ    \n");
	printf("========================\n");
	printf("      1  ��¼ϵͳ\n");
	printf("      0  �˳�ϵͳ\n");
	printf("========================\n");
	printf("������ѡ��[ ]\b\b");
	scanf("%d",&k);
	return k;
}
// ������
int main() {
    user_count=readUserFromFile();
    bookArray_count=readbookArrayFromFile();

    // ���û�м��ص��û����ݣ���ʼ��Ĭ�Ϲ���Ա�û�
    if (user_count == 0) 
	{

        strcpy(userArray[0].id, "admin");
        strcpy(userArray[0].name, "����Ա");
        strcpy(userArray[0].miMa, "admin");
        strcpy(userArray[0].buMen, "�����");
        strcpy(userArray[0].email, "admin@qq.com");
        userArray[0].jue = 0;
        userArray[0].borrowed_count=0;
        userArray[0].borrow_limit = 0;

        user_count = 1;
    }

    // ���û�м��ص�ͼ�����ݣ���ʼ��Ĭ��ͼ��
    if (bookArray_count == 0) 
	{
        bookArray[0].id = 1;
        strcpy(bookArray[0].name, "C���Գ������");
        bookArray[0].tai=0;
		
        bookArray[1].id = 2;
        strcpy(bookArray[1].name, "���ݽṹ");
		bookArray[1].tai=0;

        bookArray[2].id = 3;
        strcpy(bookArray[2].name, "�����ռ�");
		bookArray[2].tai=0;

        bookArray_count = 3;
    }
    
	int choice;
    while (1) 
	{
        choice=mainMenu();
        showtime(choice);
        if (choice == 1)
		{
            while(!login())
                continue; // ��¼ʧ�ܼ�������
            // ���ݽ�ɫ��ת�˵�
            switch (curruser.jue) 
			{
            case 3:
                student_menu();
                break;
            case 2:
                teacher_menu();
                break;
            case 1:
                librarian_menu();
                break;
            case 0:
                admin_menu();
                break;
            }
            printf("\n��ǰ�û����˳����ɼ�����¼�����˺š�\n");
        } else {
            writeuserToFile();
            writebookArrayToFile();
            printf("ϵͳ���˳���\n");
            break;
        } 
    }
    return 0;
}
