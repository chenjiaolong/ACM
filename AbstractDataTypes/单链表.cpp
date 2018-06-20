#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct node
{
    int num;
    double score;
    struct node *next;
} LNode;
LNode *Creat()
{
    LNode *pnew, *prear, *head;
    int x;
    double grade;
    head = (LNode *)malloc(sizeof(LNode));
    prear = head;
    puts("请输入学号和成绩，当输入学号为 0 结束：");
    scanf("%d%lf", &x, &grade);
    while(x)
    {
        pnew = (LNode *)malloc(sizeof(LNode));
        pnew -> num = x;
        pnew -> score = grade;
        prear -> next = pnew;
        prear = pnew;
        scanf("%d%lf", &x, &grade);
    }
    prear -> next = NULL;
    return head;
}
void output(LNode *head)
{
    LNode *p = head -> next;
    if(p == NULL)
    {
        puts("链表为空");
        return ;
    }
    while(p)
    {
        printf("%-5d %-5.2f\n", p -> num, p -> score);
        p = p -> next;
    }
}

int main()
{
    LNode *head = NULL;
    head = Creat();
    output(head);
    system("pause");
    return 0;
}
