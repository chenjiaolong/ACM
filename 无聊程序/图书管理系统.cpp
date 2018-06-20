#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct Book
{
    char name[20];//����
    int num;//���ĺ�
    char auth[20];//����
    char pub[20];//������
    int allnum;//�ܿ��
    int nownum;//�ֿ��
    float price;//�۸�
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

void Gotoxy(int x, int y)	//��λ���λ��
{
    HANDLE handle;	//����������handle
    COORD coord;	//����ṹ��coord (����ϵcoord)
    coord.X = x;	//������x
    coord.Y = y;	//������y
    handle = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ����̨������(ֵΪ-11)
    SetConsoleCursorPosition(handle, coord);	//�ƶ����
}

void Welcome()//��ӭ����
{
    Gotoxy(36,6);
    printf("��ӭʹ�ã�\n");
    Gotoxy(32,11);
    system("pause");
    system("cls");
}

void Ui()//������
{
    int i;
    Gotoxy(36,6);
    printf("1��¼���鼮");
    Gotoxy(36,8);
    printf("2�������鼮");
    Gotoxy(36,10);
    printf("3����ѯ�鼮");
    Gotoxy(36,12);
    printf("4��ɾ���鼮");
    Gotoxy(36,14);
    printf("5���޸��鼮");
    Gotoxy(36,16);
    printf("6����ʾȫ���鼮");
    Gotoxy(32,18);
    printf("��ѡ��1-6��,��0�˳���");
    scanf("%d",&i);
    if(i==0)
        exit(0);
    else if(i<1||i>6)
    {
        system("cls");
        Gotoxy(32,8);
        printf("����������������룡");
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

void init_book()//��ʼ��
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
    printf("��ǰĿ¼��¼���鼮����0���������棩");
    Gotoxy(28,11);
    printf("����������ͼ���������");
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
        printf("�������%d�������Ϣ��",i+1);
        Gotoxy(28,6);
        printf("������������");
        scanf("%s",q->name);
        Gotoxy(28,7);
        printf("��������ĺţ�");
        scanf("%d",&q->num);
        Gotoxy(28,8);
        printf("���������ߣ�");
        scanf("%s",q->auth);
        Gotoxy(28,9);
        printf("����������磺");
        scanf("%s",q->pub);
        Gotoxy(28,10);
        printf("������۸�");
        scanf("%f",&q->price);
        Gotoxy(28,11);
        printf("�������ܿ�棺");
        scanf("%d",&q->allnum);
        Gotoxy(28,12);
        printf("�������ֿ�棺");
        scanf("%d",&q->nownum);
        system("cls");
        q->next=NULL;
        p->next=q;
        p=q;
    }
    Gotoxy(28,9);
    printf("¼�����");
    system("pause");
    system("cls");
    Ui();
}
void print_book(book *h)//��ʾȫ���鼮
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

