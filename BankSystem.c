#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define upNum 2000 

struct record
{
    int account;
    int password; 
    char name[10];   
    double balance;  
    int status;  
};

struct record users[upNum];

int N;

void pass();

void adminpass();

void readData();

void writeData();

int chooseInMenu();

void openAccount();

void save();

void Menu();

void withdraw();

void showAccount();

void showAll();

void showBalance();

void findData();

void freeze();

void cancelfreeze();

int inputPassword();

int search(int);

int welcomeMenu();

int ichooseInMenu();

int adminchooseMenu();

void adminMenu();


void welcome();
#endif // BANK_H_INCLUDED



/*登录界面*/
int welcomeMenu()
{
    int i;
    while(1)
    {
    printf("+------------------------------+\n");
    printf("+                              +\n");
    printf("+    Welcome Bank System       +\n");
    printf("+                              +\n");
    printf("+         1 Create             +\n");
    printf("+                              +\n");
    printf("+         2 Sign up            +\n");
    printf("+                              +\n");
    printf("+         3 Admin              +\n");
    printf("+                              +\n");
    printf("+         0 Quit               +\n");
    printf("+                              +\n");
    printf("+------------------------------+\n");
    printf("Please select the business you want to handle: ");
    fflush(stdin);
    scanf("%d",&i);
    if(i>=0 &&i<=3)
            break;
        else
            printf("Invalid selection, please select again!\n\n");
    }
    return i;
}

/*用户菜单*/
int ichooseInMenu()
{
    int i;
    while(1)
    {
        printf("\n");
        printf("+---------------------------+\n");
        printf("|  1 search balance         |\n");
        printf("|  2 search history change  |\n");
        printf("|  3 depoist money          |\n");
        printf("|  4 withdraw money         |\n");
        printf("|  0 quit                   |\n");
        printf("+---------------------------+\n");
        printf("enter ur choice: ");
        scanf("%d",&i);
        if(i>=0 &&i<=4)
            break;
        else
            printf("Incorrect input, please choose again\n\n");
    }
    return i;
}

/*管理员菜单*/
int adminchooseMenu()
{
    int i;
    while(1)
    {
        printf("\n");
        printf("+--------------------------------------------------+\n");
        printf("|                1 search balance                  |\n");
        printf("|                2 history chage                   |\n");
        printf("|                3 deposit money                   |\n");
        printf("|                4 withdraw money                  |\n");
        printf("|                5 Show all account information    |\n");
        printf("|                6 search account                  |\n");
        printf("|                7 freeze account                  |\n");
        printf("|                8 Unfreeze your account           |\n");
        printf("|                0 Quit                            |\n");
        printf("+--------------------------------------------------+\n");
        printf("enter ur choice: ");
        scanf("%d",&i);
        if(i>=0 &&i<=8)
            break;
        else
            printf("enter wrong,choice again!\n\n");
    }
    return i;
}




/*欢迎界面功能*/
void welcome()
{
    int Choice;/*用户选择功能*/
    do
    {
        Choice=welcomeMenu();
        switch(Choice)
        {
        case 1:
            openAccount();/*开户*/
            break;
        case 2:
            pass();/*用户登录*/
            break;
        case 3:
            adminpass();/*管理员登录*/
            break;
        case 0:
            printf("You are welcome to come again. \n");
        }
    }
    while(Choice);
}




/*开户*/
void openAccount()
{
    if(N==upNum)
    {
        printf("account limits!");
        return;
    }
    //下面正常办理开户业务
    printf("creating\n");
    users[N].account=10001+N;
    printf("account：%d", users[N].account);
    printf("name：");
    scanf("%s", users[N].name);
    int iPass1, iPass2;
    printf("password：");
    iPass1=inputPassword();  //输入密码1
    printf("make sure password：");
    iPass2=inputPassword();  //输入密码2
    if(iPass1==iPass2)
    {
        users[N].password=iPass1;
        users[N].status=0; //账户状态为“正常”
        printf("depoist balance：");
        scanf("%lf", &users[N].balance);
        N++; //正式用户数增加1，确认了新用户已经加入
        printf("create sucessfully！\n");
    }
    else
    {
        printf("Two times the password does not match, unsuccessful account opening！\n"); //没有N++，则读入的值无效
    }
}



/*用户登录*/
void pass()
{
    int id;   //用于输入的账号
    int who;  //查找到该账号在数组中对应的下标
    int sPass;  //业务员登录时输入的密码
    int right = 0;  //要返回的结果：0-不正确 1-正确

    printf("Please enter your account number：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("The user does not exist, login failed！\n");
    }
    else
    {
        printf("Please enter your password:");
        sPass=inputPassword();
        if(sPass==users[who].password)
        {
            right = 1;
        }
        else
            {
                printf("Sorry, wrong password\n");
            }
    if (right==1)
        Menu();
    else
        return;
    }
}

/*管理员登录*/
void adminpass()
{
    char userName[7];
    char userPWD[7];
    int i;

    for(i=0; i<3; i++)
    {
        printf("\n");
        printf("Please enter your account number:");
        scanf("%s", userName);
        fflush(stdin);

        printf("\nPlease enter your password:");
        scanf("%s", userPWD);
        fflush(stdin);


        if ((strcmp(userName,"admin")==0) && (strcmp(userPWD,"admin")==0))
        {
            //用户名和密码正确，显示管理员菜单
            adminMenu();
            return;
        }
        else
        {
            if (i < 2)
            {
                //用户名或密码错误，提示用户重新输入
                printf("User name or password is wrong, please re-enter!\n");
            }
            else
            {
                //连续3次输错用户名或密码，退出系统。
                printf("User name or password is wrong, quit system!\n");
            }
        }
    }
}


/*用户菜单*/
void Menu()
{
    int iChoice;/*用户选择功能*/
    do
    {
        iChoice=ichooseInMenu();
        switch(iChoice)
        {
        case 1:
            showBalance();/*查询余额*/
            break;
        case 2:
            findData();/*查询记录,还没做好*/
            break;
        case 3:
            save();/*存钱*/
            break;
        case 4:
            withdraw();/*取钱*/
            break;
        case 0:
            printf("You are welcome to come again. \n");
            break;
        }
    }
    while(iChoice);
}

/*管理员菜单*/
void adminMenu()
{
    int Choice;/*用户选择功能*/
    do
    {
        Choice=adminchooseMenu();
        switch(Choice)
        {
        case 1:
            showBalance();//查询余额
            break;
        case 2:
            findData();//查询记录,还没做好
            break;
        case 3:
            save();//存钱
            break;
        case 4:
            withdraw();//取钱
            break;
        case 5:
            showAll();//查询所有账户
            break;
        case 6:
            showAccount();//查询账户信息
            break;
        case 7:
            freeze();//冻结
            break;
        case 8:
            cancelfreeze();//解冻
            break;
        case 0:
            printf("Welcome!!. \n");
        }
    }
    while(Choice);
}


/*存款*/
void save()
{
    int id, who;
    double money;
    printf("Enter the account number to be deposited：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("The user does not exist, the deposit failed！\n");
    }
    else
    {
        if(users[who].status==0)
        {
            printf("User Name：%s\n", users[who].name);
            printf("Enter the deposit amount：");
            scanf("%lf", &money);
            users[who].balance+=money;
            printf("After the deposit, you have %.2f$. \n",users[who].balance);
        }
        else if(users[who].status==1)
        {
            printf("The user is in a frozen state and the deposit has failed！\n");
        }
    }
    return;
}




/*取款*/
void withdraw()
{
    int id, who;
    int iPass;
    double money;
    printf("Enter the account number to withdraw：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("The user does not exist, withdrawal failed！\n");
    }
    else
    {
        if(users[who].status==0)
        {
            printf("username：%s\n", users[who].name);
            printf("password：");
            iPass=inputPassword();
            if(iPass!=users[who].password)
            {
                printf("Incorrect password, withdrawal failed！\n");
            }
            else
            {
                printf("Enter withdrawal amount：");
                scanf("%lf", &money);
                if(money>users[who].balance)  //亲，不玩透支
                {
                    printf("Insufficient balance, withdrawal failed!\n");
                }
                else
                {
                    users[who].balance-=money;
                    printf("After withdrawal, there is still %.2f yuan. \n",users[who].balance);
                }
            }
        }
        else if(users[who].status==1)
        {
            printf("The user is in a frozen state and the withdrawal failed!\n");
        }
    }
    return;
}

/*余额查询*/
void showBalance()
{
    int id, who;
    printf("account：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("this user does not exist！\n");
    }
    else
    {
        printf("username：%s\n", users[who].name);
        {
            printf("balance：%.2f元. \n",users[who].balance);
        }
    }
    return;
}


/*查询账户*/
void showAccount()
{
    int id, who;
    printf("account：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("This user does not exist！\n");
    }
    else
    {
        printf("user name: s\n", users[who].name);
        {
            printf("balance：%.2f Dollers. \n",users[who].balance);
            printf("Status：");
            if(users[who].status==0)
            {
                printf("Normal\n");
            }
            else if(users[who].status==1)
            {
                printf("Freeze\n");
            }
        }
    }
    return;
}




/*查询记录还没做好*/
void findData()
{
    return ;
}


/*显示所有账户*/
void showAll()
{
    int i;
    printf("Account Username Password\n");
    for(i=0;i<=N;i++)
    {
        printf("%d %s %d",users[i].account, users[i].name, users[i].password);
    }
}


/*冻结账户*/
void freeze()
{
    int id, who;
    printf("Account Number：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("The user does not exist and cannot be frozen！\n");
    }
    else
    {
        printf("Name of head of household：%s\n", users[who].name);


            if(users[who].status==0)
            {
                users[who].status=1;
                printf("Lost and Found\n");
            }
            else if(users[who].status==1)
            {
                printf("The account is already in a frozen staten");
            }
    }
    return;
}




/*解除冻结*/
void cancelfreeze()
{
    int id, who;
    printf("Account Number：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("The user does not exist, unfreezing failed! \n");
    }
    else
    {
        printf("户主姓名：%s\n", users[who].name);
            if(users[who].status==0)
            {
                printf("The account is in normal status and does not need to be unfrozen\n");
            }
            else if(users[who].status==1)
            {
                users[who].status=0;
                printf("Unfreezing successful\n");
            }

    }
    return;
}



/*根据账号查询用户，返回用户的下标*/
int search(int id)
{
    int index=-1;
    int low=0, high=N-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(users[mid].account==id)
        {
            index=mid;
            break;   //找到了，立即退出循环
        }
        else if (users[mid].account>id)
            high=mid-1;
        else
            low=mid+1;
    }
    return index; //若找到，其值在0~N-1间，否则，保持-1
}



/*读取文件内容*/
void readData()
{
    FILE *fp;  //用于文件操作
    int i = 0;
    //从文件中取出余额
    if ((fp=fopen("account.txt", "a+"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    while(fscanf(fp,"%d %s %d %lf %d",&users[i].account, users[i].name, &users[i].password, &users[i].balance,&users[i].status ) != EOF)
    {
        i++;
    }
    N = i; //用全局变量存储用户的总人数
    fclose(fp);
    return;
}


/*将数据保存到文件中*/
void writeData()
{
    FILE *fp;  //用于文件操作
    int i=0;
    //保存余额
    if ((fp=fopen("account.txt", "w"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    for(i=0; i<N; i++)
        fprintf(fp,"%d %s %d %f %d\n",users[i].account, users[i].name, users[i].password, users[i].balance,users[i].status);
    fclose(fp);
}



/*规范密码并将输入密码变成星号*/
int inputPassword()
{
    char ch;  //接收字符形式密码
    int iPass=0;   //要转换为数字
    int i;
    while(1)
    {
        for(i=0; i<6; i++)
        {
            ch=getch();  //输入但不显示
            putchar('*');   //输出*
            if(isdigit(ch))
                iPass=iPass*10+(ch-'0');
            else
            {
                iPass=0;
                break;  //退出for循环后，再次接受
            }
        }
        fflush(stdin); //清除键盘缓存区中已经有的输入
        printf("\n");
        if(iPass==0)  //此条件成立可能由两种情况引起：输入了非数字字符被直接重置为0，或6位全0后正常退出for循环
        {
            printf("The password requires all numbers and not all zeros!\n");
            printf("Please re-enter your password: ");
        }
        else
            break;
    }
    return iPass;
}

/*主函数：*/
int main()
{
    system("title 银行管理系统");
    readData();
    welcome();
    writeData();

    return 0;
}
