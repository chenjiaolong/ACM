#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct Book
{
    char name[20];//书名
    int num;//借阅号
    char auth[20];//作者
    char pub[20];//出版社
    int allnum;//总库存
    int nownum;//现库存
    float price;//价格
    struct Book *next;
} book;
void Gotoxy(int x, int y);
void Welcome();
void Ui();
void init_book();
void print_book(book *h);

book *head=NULL;

int main()
{
    Welcome();
    Ui();
    return 0;
}

void Gotoxy(int x, int y)	//定位光标位置
{
    HANDLE handle;	//定义句柄变量handle
    COORD coord;	//定义结构体coord (坐标系coord)
    coord.X = x;	//横坐标x
    coord.Y = y;	//纵坐标y
    handle = GetStdHandle(STD_OUTPUT_HANDLE);	//获取控制台输出句柄(值为-11)
    SetConsoleCursorPosition(handle, coord);	//移动光标
}

void Welcome()//欢迎界面
{
    Gotoxy(36,6);
    printf("欢迎使用！\n");
    Gotoxy(32,11);
    system("pause");
    system("cls");
}

void Ui()//主界面
{
    int i;
    Gotoxy(36,6);
    printf("1、录入书籍");
    Gotoxy(36,8);
    printf("2、增加书籍");
    Gotoxy(36,10);
    printf("3、查询书籍");
    Gotoxy(36,12);
    printf("4、删除书籍");
    Gotoxy(36,14);
    printf("5、修改书籍");
    Gotoxy(36,16);
    printf("6、显示全部书籍");
    Gotoxy(32,18);
    printf("请选择（1-6）,按0退出：");
    scanf("%d",&i);
    if(i==0)
        exit(0);
    else if(i<1||i>6)
    {
        system("cls");
        Gotoxy(32,8);
        printf("输入错误，请重新输入！");
        Gotoxy(34,10);
        system("pause");
        system("cls");
        Ui();
    }
    else
    {
        switch(i)
        {
        case 1:
            init_book();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            print_book(head);
            break;
        }
    }
}

void init_book()//初始化
{

    book *p,*q;
    int i,j;
    head=(book *)malloc(sizeof(book));
    p=head;
    p->next=NULL;
    system("cls");
    Gotoxy(28,9);
    //printf("%p\n",head);
    //printf("%p",p);
    printf("当前目录：录入书籍（按0返回主界面）");
    Gotoxy(28,11);
    printf("请输入现有图书的数量：");
    scanf("%d",&j);
    if(j==0)
    {
        system("cls");
        Ui();
    }
    system("cls");
    for(i=0; i<j; i++)
    {
        q=(book *)malloc(sizeof(book));
        Gotoxy(28,5);
        printf("请输入第%d本书的信息：",i+1);
        Gotoxy(28,6);
        printf("请输入书名：");
        scanf("%s",q->name);
        Gotoxy(28,7);
        printf("请输入借阅号：");
        scanf("%d",&q->num);
        Gotoxy(28,8);
        printf("请输入作者：");
        scanf("%s",q->auth);
        Gotoxy(28,9);
        printf("请输入出版社：");
        scanf("%s",q->pub);
        Gotoxy(28,10);
        printf("请输入价格：");
        scanf("%f",&q->price);
        Gotoxy(28,11);
        printf("请输入总库存：");
        scanf("%d",&q->allnum);
        Gotoxy(28,12);
        printf("请输入现库存：");
        scanf("%d",&q->nownum);
        system("cls");
        q->next=NULL;
        p->next=q;
        p=q;
    }
    Gotoxy(28,9);
    printf("录入结束");
    system("pause");
    system("cls");
    Ui();
}
void print_book(book *h)//显示全部书籍
{
    system("cls");
    int y=3;
    Gotoxy(28,y);
    while(h->next!=NULL)
    {
        h=h->next;
        printf("%s ",h->name);
        printf("%d ",h->num);
        printf("%s ",h->auth);
        printf("%s ",h->pub);
        printf("%d ",h->allnum);
        printf("%d ",h->nownum);
        printf("%f ",h->price);
        y+=2;
        Gotoxy(28,y);
    }
    system("pause");
    system("cls");
    Ui();
}

