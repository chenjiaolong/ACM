#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

using namespace std;

typedef struct node
{
    int coef; // 系数
    int expn; // 指数
    struct node * next;
}PNode, *Polynomial;

void CreatePolyn(Polynomial &P)
{
    Polynomial q, pre, s;
    P = new PNode;
    P -> next = NULL;
    while(1)
    {
        s = new PNode;
        scanf("%d", &s -> coef);
        if(!s -> coef) break;
        scanf("%d\n", &s -> expn);
        pre = P;
        q = P -> next;
        while(q && P -> expn > s -> expn)
        {
            pre = q;
            q = q -> next;
        }
        s -> next = q;
        pre -> next = s;
    }
}
void InsertSort(Polynomial &P)
{
    if(P -> next == NULL || P -> next -> next == NULL)
        return ;
    Polynomial p,q,pre;
    p = P -> next -> next;
    P -> next -> next = NULL;
    while(p)
    {
        pre = P;
        q = p;
        p = p -> next;
        while(pre -> next && pre -> next -> expn < q -> expn)
            pre = pre -> next;
        q -> next = pre -> next;
        pre -> next = q;
    }
}
void AddPolyn(Polynomial &Pa, Polynomial &Pb)
{
    Polynomial r, p1, p2, p3;
    int sum;
    p1 = Pa -> next;
    p2 = Pb -> next;
    p3 = Pa;
    while(p1 && p2)
    {
        if(p1 -> expn == p2 -> expn)
        {
            sum = p1 -> coef + p2 -> coef;
            if(sum)
            {
                p1 -> coef = sum;
                p3 -> next = p1;
                p3 = p1;
                p1 = p1 -> next;
                r = p2;
                p2 = p2 -> next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1 -> next;
                delete r;
                r = p2;
                p2 = p2 -> next;
                delete r;
            }
        }
        else if(p1 -> expn < p2 -> expn)
        {
            p3 -> next = p1;
            p3 = p1;
            p1 = p1 -> next;
        }
        else
        {
            p3 -> next = p2;
            p3 = p2;
            p2 = p2 -> next;
        }
    }
    p3 -> next = p1 ? p1 : p2;
    delete Pb;
}
int main()
{
    Polynomial Pa, Pb;
    CreatePolyn(Pa);
    CreatePolyn(Pb);
    InsertSort(Pa);
    InsertSort(Pb);
    AddPolyn(Pa, Pb);
    Polynomial p = Pa -> next;
    bool flag = false;
    while(p)
    {
        if(flag) printf(" ");
        printf("%d %d", p -> coef, p -> expn);
        flag = true;
        p = p -> next;
    }
    printf("\n");
    return 0;
}
