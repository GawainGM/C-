#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
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
	long bookArrayID;
	char name[30];
	dateTime jie;
	dateTime huan;
	dateTime shi;
	int tai;//0是首次借,1是续借,2是归还 
}borrowbookArray;

//图书结构体
typedef struct
{
	long id;
	char name[30];
	int tai;
}book;

//用户
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
int user_count = 0;//用户数量
book bookArray[MAX_bookArray];
int bookArray_count = 0;//图书数量
user curruser; // 当前登录用户

int readUserFromFile()//把用户数据从文件中读出 
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

void writeuserToFile()//写入用户数据
{
	FILE *fp;
	fp=fopen("userArray.txt","w");
	if(fp==NULL)
	printf("打开失败");
	fwrite(userArray,sizeof(user),user_count,fp);
	fclose(fp);
}

int readbookArrayFromFile()//把书籍数据从文件中读出
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

void writebookArrayToFile()//写入书籍数据 
{
	FILE *fp;
	fp=fopen("bookArrays.txt","w");
	fwrite(bookArray,sizeof(book),bookArray_count,fp);
	fclose(fp);
}

int readBorrowFromFile(borrowbookArray borrowArray[])//把借书数据从文件中读出
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

void writeBorrowbookArrayToFile(borrowbookArray borrowArray[],int borrowTotal)//写入借书数据
{
	FILE *fp;
	fp=fopen("borrowbookArray.txt","w");
	fwrite(borrowArray,sizeof(borrowbookArray),borrowTotal,fp);
	fclose(fp);
}

int userSearch(char id[]) //用户查询（遍历查找）
{
    int i=0;
	for(i=0;i<user_count;i++)
	{
		if(strcmp(userArray[i].id,id)==0)
		return i;
	}
    return -1;
}
//输入密码
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

//生成一串长度length随机验证码
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

// 公共模块：登录验证
int login() 
{
    char account[20], password[20];
    char captcha[10];
    char usercap[10];
	getCaptcha(captcha,4);
    printf("请输入账号：");
    scanf("%s", account);
    printf("请输入密码：");
    inputPassWord(password,10); 
    printf("请输入验证码(区分大小写):  ");
	printf("（%s）\n",captcha);
	scanf("%s",usercap);
	while(strcmp(usercap,captcha)!=0)
	{
		printf("验证码错误,请重新输入:\n");
		scanf("%s",usercap);
	}
	
    // 查找用户
    for (int i = 0; i < user_count; i++) {
        if (strcmp(userArray[i].id, account) == 0 &&
            strcmp(userArray[i].miMa, password) == 0) {
            curruser = userArray[i];
            return 1; //登录成功
        }
    }
    printf("账号或密码错误！\n");
    system("pause");
    return 0;
}

// 公共模块：修改信息
void dispUser(user userArray[],int i)//修改界面 
{
	user s;
	s=userArray[i];
	printf("\n用户信息->修改信息:\n");
	printf("1.用户名字:%s\n",s.name);
	printf("2.部门:%s\n",s.buMen);
	printf("3.E-mail:%s\n",s.email);
	printf("4.密码:******\n");
	printf("0.退出\n");
}

//修改用户参数
void modifyUserInfo() 
{
	int i;
	int n;
	char mi[10],ma[10];
	i=userSearch(curruser.id);
	if(i<0)
	printf("没有该用户\n");
	do{
	dispUser(userArray,i);
	printf("请选择要修改的选项:");
	scanf("%d",&n);
	switch (n) {
		case 1:
			printf("请输入新名字:");
			scanf("%s",curruser.name);
			printf("修改成功\n");
			break;
		case 2:
			printf("请输入新部门:");
			scanf("%s",curruser.buMen);
			printf("修改成功\n");
			break;
		case 3:
			printf("请输入新E-mail:");
			scanf("%s",curruser.email);
			printf("修改成功\n");
			break;
		case 4:
			printf("请输入新密码:");
			inputPassWord(mi,10);
			printf("请再次输入新密码:");
			inputPassWord(ma,10);
			if(strcmp(mi,ma)==0)
			{printf("修改成功\n");
			strcpy(curruser.miMa,mi);}
			else
			printf("修改失败\n");
			break;
		default:
			printf("退出\n");
			break;
	}
	userArray[i]=curruser;
	}while(n==1||n==2||n==3||n==4);
	return; 
}
//续借界面 
void dispBook()
{
	user s;
	s=curruser;
	printf("用户信息->续借:\n");
	printf("用户ID:%s\n",s.id);
	printf("用户名字:%s\n",s.name);
	printf("部门:%s\n",s.buMen);
	printf("当前借书量:%d\n",s.borrowed_count);
	printf("===========================================\n");
	printf("图书编号     书名     借阅日期     应还日期\n");
	printf("===========================================\n");
	for(int i=1;i<=s.borrowed_count;i++)
	{printf("%ld  %6s  %d年%2d月%d日--",s.max[i].bookArrayID,s.max[i].name,s.max[i].jie.year,s.max[i].jie.month,s.max[i].jie.day);
	printf("%d年%2d月%d日\n",s.max[i].huan.year,s.max[i].huan.month,s.max[i].huan.day);
	}
	printf("===========================================\n");
} 
//续借模块
void userRenewBook()
{
	dispBook();
	long n;
	user s;
	int i;
	s=curruser;
	do{
		printf("请输入图书编号(输入0返回):"); 
		scanf("%ld",&n);
		for(i=0;i<s.borrowed_count;i++)
		if(s.max[i].bookArrayID==n)
		break;
		if(n==0||s.max[i].tai==0)
		{
			printf("续借失败\n");
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
		printf("《%s》,续借成功!\n",s.max[i].name);
	}while(1);
	curruser=s;
}

// 公共模块：查询图书
void search_bookArray() 
{
    char keyword[50];
    int choice;
    printf("1.按编号查询 2.按书名查询：");
    scanf("%d", &choice);
    if (choice == 1) {
        long id;
        printf("输入编号：");
        scanf("%ld", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id) {
                printf("图书信息：编号%ld 书名《%s》 状态：%s\n",
                       bookArray[i].id, bookArray[i].name,bookArray[i].tai == 0 ? "可借" : "已借");
                return;
            }
        }
    } else {
        printf("输入书名关键词：");
        scanf("%s", keyword);
        for (int i = 0; i < bookArray_count; i++) {
            if (strstr(bookArray[i].name, keyword)) {
                printf("图书信息：编号%ld 书名《%s》 状态：%s\n",
                bookArray[i].id, bookArray[i].name,bookArray[i].tai == 0 ? "可借" : "已借");     
            }
        }
    }
    printf("未找到匹配图书！\n");
}


void writedate(int i)//把bookArray中序号i的书借出
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


// 学生功能：借阅图书
void student_borrow_bookArray() {
    if (curruser.borrowed_count >= curruser.borrow_limit) {
        printf("已达借阅上限（%d本）！\n", curruser.borrow_limit);
        return;
    }
    int choice;
    printf("1. 按编号借阅 2. 按书名借阅：");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("输入图书编号：");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai==0) {
                bookArray[i].tai = 1;
                curruser.borrowed_count++;
                writedate(i);
                
                printf("借阅成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("输入图书书名：");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0&&bookArray[i].tai==0) {
                bookArray[i].tai = 1;
                curruser.borrowed_count++;
                writedate(i);
                printf("借阅成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("图书不可借！\n");
}

// 学生功能：归还图书
void student_return_bookArray() {
    if (curruser.borrowed_count == 0) {
        printf("你没有借阅任何图书！\n");
        return;
    }
    int choice;
    printf("1. 按编号归还 2. 按书名归还：");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("输入图书编号：");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("归还成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("输入图书书名：");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("归还成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("你没有借阅该图书！\n");
}

// 教师功能：批量借阅
void teacher_batch_borrow() {
    int num;
    printf("输入借阅数量（最多%d本）：", curruser.borrow_limit - curruser.borrowed_count);
    scanf("%d", &num);
    if (num <= 0 || num > curruser.borrow_limit - curruser.borrowed_count) {
        printf("数量无效！\n");
        return;
    }
    for (int j = 0; j < num; j++) {
        int choice;
        printf("第 %d 本，1. 按编号借阅 2. 按书名借阅：", j + 1);
        scanf("%d", &choice);
        if (choice == 1) {
            int id;
            printf("输入图书编号：");
            scanf("%d", &id);
            for (int i = 0; i < bookArray_count; i++) {
                if (bookArray[i].id == id && bookArray[i].tai == 0) {
                    bookArray[i].tai = 1;
                    curruser.borrowed_count++;
                    writedate(i);
                    printf("第 %d 本借阅成功！当前已借：%d本\n", j + 1, curruser.borrowed_count);
                    break;
                }
            }
        } else if (choice == 2) {
            char title[50];
            printf("输入图书书名：");
            scanf("%s", title);
            for (int i = 0; i < bookArray_count; i++) {
                if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 0) {
                    bookArray[i].tai = 1;
                    curruser.borrowed_count++;
                    writedate(i);
                    printf("第 %d 本借阅成功！当前已借：%d本\n", j + 1, curruser.borrowed_count);
                    break;
                }
            }
        }
    }
    printf("批量借阅成功！\n");
}

// 教师功能：归还图书
void teacher_return_bookArray() {
    if (curruser.borrowed_count == 0) {
        printf("你没有借阅任何图书！\n");
        return;
    }
    int choice;
    printf("1. 按编号归还 2. 按书名归还：");
    scanf("%d", &choice);
    if (choice == 1) {
        int id;
        printf("输入图书编号：");
        scanf("%d", &id);
        for (int i = 0; i < bookArray_count; i++) {
            if (bookArray[i].id == id && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("归还成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    } else if (choice == 2) {
        char title[50];
        printf("输入图书书名：");
        scanf("%s", title);
        for (int i = 0; i < bookArray_count; i++) {
            if (strcmp(bookArray[i].name, title) == 0 && bookArray[i].tai == 1) {
                bookArray[i].tai = 0;
                curruser.borrowed_count--;
                
                printf("归还成功！当前已借：%d本\n", curruser.borrowed_count);
                return;
            }
        }
    }
    printf("你没有借阅该图书！\n");
}

// 图书管理员功能：录入新书
void librarian_add_bookArray() {
    if (bookArray_count >= MAX_bookArray) {
        printf("图书数量已达上限！\n");
        return;
    }
    book b;
    printf("输入图书编号：");
    scanf("%ld", &b.id);
    printf("输入书名：");
    scanf("%s", b.name);
	b.tai=0;
    bookArray[bookArray_count++] = b;
    printf("图书录入成功！当前共%d本图书\n", bookArray_count);
}

//图书信息删除模块
void deleteBook()
{
    long targetld;//存储要删除的图书编号
    printf("请输入要删除的图书编号：");
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
    
    if (found != -1)//移动数组元素
    {
        for (int i = found; i < bookArray_count; i++)
        {
            bookArray[i] = bookArray[i + 1];
        }
        bookArray_count--; 
            printf("删除成功!\n");
        
    }
    else  printf("未找到该图书！！\n");
    
}
//分页显示用户信息化
void printUser()
{
    int page = 0;
    int perPage = 5;//每页的个数
    int totalPages = (user_count + perPage - 1) / perPage;//计算总页数
    char cmd;
    do {
        printf("\n===用户列表（第%d/%d页)===\n", page + 1,totalPages);
        for (int i = page * perPage; i < (page + 1) * perPage && i < user_count; i++) {
            printf("%d.%s %s\n", i + 1, userArray[i].id,userArray[i].name);
        }
        printf("\n[n]下一页[p]上一页[q]返回:");
        getchar();//吞掉前面的回车键
        scanf("%c",&cmd);
        if (cmd == 'n' && page < totalPages - 1)page++;
        else if (cmd == 'p' && page > 0)page--;
        else if (cmd == 'q')break;
    } while (1);
    return;
}
// 系统管理员功能：创建用户
void inputUser() 
{
    int count;
    printf("请输入要添加的用户数：");
        scanf_s("%d", &count);
    if (user_count+count >= MAX_userArray) 
	{
        printf("用户数已满！\n");
        return;
    }
    user u;
    for(int i=0;i<count;i++)
    {
    	printf("第%d个\n",i+1);
    	printf("===============\n");
        printf("用户账号:");
        scanf("%s",u.id);
        printf("姓名:");
        scanf("%s",u.name);
        printf("密码:");
        scanf("%s",u.miMa);
    int role;
    printf("选择角色（3=学生，2=教师，1=图书管理员）：");
    scanf("%d", &role);
    if (role < 1 || role > 3) {
        printf("角色选择错误！\n");
        return;
    }
    u.jue = role;
    u.borrow_limit=10;
    u.borrowed_count = 0;
    userArray[user_count++] = u;
    printf("用户创建成功！账号：%s 角色：%d\n",u.id, u.jue);
    }
    return;
}

// 系统管理员功能：删除用户
void deleteUser() {
    char account[20];
    printf("输入要删除的用户账号：");
    scanf("%s", account);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(userArray[i].id, account) == 0) 
		{
			if (strcmp(userArray[i].id, curruser.id) == 0)                
			{//检查该用户是否为当前登录用户
			    printf("不能删除当前用户！\n");
			    return;
			}
            // 移除该用户
            for (int j = i; j < user_count - 1; j++) 
			{
                userArray[j] = userArray[j + 1];
            }
            user_count--;
            printf("用户删除成功！\n");
            return;
        }
    }
    printf("未找到该用户！\n");
}

void initPassWord()//初始化用户密码
{
    char* initPass = "123456";//初始密码
    for (int i = 1; i < user_count; i++) 
	{
        strcpy(userArray[i].miMa, initPass);
 }
    printf("已重置所有用户密码为初始值！\n");
}

//分页显示图书信息模块
void printBook()
{
    int page = 0;
    int itemsPerPage = 10;
    char input;
    do {
        system("cls");//清屏
        printf("===图书列表（第%d页/共%d页）===\n", page + 1, (bookArray_count/ itemsPerPage) + 1);
        for (int i = page * itemsPerPage; i < (page + 1) * itemsPerPage && i < bookArray_count; i++)
    //通过 for 循环遍历当前页的图书信息，i 从 page* itemsPerPage 开始，到(page + 1)* itemsPerPage 结束，同时确保不超过图书总数 bookTotal
        {
            printf("[%d] %ld--%s--", i + 1, bookArray[i].id, bookArray[i].name);
            bookArray[i].tai?printf("已借\n"):printf("未借\n");
        }
        printf("\n操作选项（N-下一页，P-上一页，Q-退出）：");
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

//输出问候语
void showtime(int k)
{
	system("cls");
	time_t currtime;
	struct tm *time_info;
	time(&currtime);
	time_info=localtime(&currtime);
	int hour=time_info->tm_hour;
	//问候语
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
	//欢迎语句
	if(k==1)
	printf("欢迎使用图书管理系统\n");
	else
	printf("谢谢使用图书管理系统\n");
	
}
// 学生菜单
int menuStudent()//学生界面
{
	printf("小型图书管理系统--学生用户\n");
	printf("==========================\n");
	printf("1.图书查询\n");
	printf("2.图书归还\n");
	printf("3.续借(小问题)\n");
	printf("4.修改个人信息\n");
	printf("0.退出\n");
	printf("==========================\n");
	printf("请输入选项[ ]\b\b");
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
            printf("无效选择！\n");
        }
    }
}

// 教师菜单
int menuTeacher()// 教师界面
{
	printf("小型图书管理系统--教师用户\n");
	printf("==========================\n");
	printf("1.图书查询\n");
	printf("2.图书归还\n");
	printf("3.续借(小问题)\n");
	printf("4.修改个人信息\n");
	printf("0.退出\n");
	printf("==========================\n");
	printf("请输入选项[ ]\b\b");
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
            printf("无效选择！\n");
        }
    }
}

// 图书管理员菜单

void librarian_menu() {
    while (1) {
        printf("\n===== 图书管理员面板=====\n");
        printf("1. 录入图书\n2. 删除图书\n");
        printf("3. 修改信息\n4. 图书查询\n");
        printf("5. 退出\n");
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
            printf("无效选择！\n");
        }
    }
}

int menuAdmin() 
{
    printf("\n=== 系统管理员菜单 ===\n");
    printf("1. 显示用户\n");
    printf("2. 添加用户\n");
    printf("3. 删除用户\n");
    printf("4. 显示图书\n");
    printf("5. 批量添加图书\n");
    printf("6. 删除图书\n");
    printf("7. 初始化用户密码\n");
    printf("8. 修改信息\n");
    printf("0. 退出\n");
    printf("请输入选择[ ]\b\b");
    int choice;
    scanf_s("%d", &choice);
    return choice;
}
// 系统管理员菜单
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
            printf("无效选择！\n");
        }
    }
}
int mainMenu()//首要菜单 
{
	int k;
	system("cls");
	printf("    小型图书管理系统    \n");
	printf("========================\n");
	printf("      1  登录系统\n");
	printf("      0  退出系统\n");
	printf("========================\n");
	printf("请输入选项[ ]\b\b");
	scanf("%d",&k);
	return k;
}
// 主函数
int main() {
    user_count=readUserFromFile();
    bookArray_count=readbookArrayFromFile();

    // 如果没有加载到用户数据，初始化默认管理员用户
    if (user_count == 0) 
	{

        strcpy(userArray[0].id, "admin");
        strcpy(userArray[0].name, "管理员");
        strcpy(userArray[0].miMa, "admin");
        strcpy(userArray[0].buMen, "计算机");
        strcpy(userArray[0].email, "admin@qq.com");
        userArray[0].jue = 0;
        userArray[0].borrowed_count=0;
        userArray[0].borrow_limit = 0;

        user_count = 1;
    }

    // 如果没有加载到图书数据，初始化默认图书
    if (bookArray_count == 0) 
	{
        bookArray[0].id = 1;
        strcpy(bookArray[0].name, "C语言程序设计");
        bookArray[0].tai=0;
		
        bookArray[1].id = 2;
        strcpy(bookArray[1].name, "数据结构");
		bookArray[1].tai=0;

        bookArray[2].id = 3;
        strcpy(bookArray[2].name, "狂人日记");
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
                continue; // 登录失败继续尝试
            // 根据角色跳转菜单
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
            printf("\n当前用户已退出，可继续登录其他账号。\n");
        } else {
            writeuserToFile();
            writebookArrayToFile();
            printf("系统已退出。\n");
            break;
        } 
    }
    return 0;
}
