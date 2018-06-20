//循环链表版
/*#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef struct LNode
{
    int no, pass;
    LNode *next;
} LNode, *CircularLinkList;
void InitList(CircularLinkList &L)//初始化一个空的循环链表
{
    L = new LNode;
    L -> next == L;
}
void CreateList(CircularLinkList &L)//创建一个循环链表
{
    int a[10] = {3, 1, 7, 2, 4, 8, 4};//初始化密码
    LNode *s, *r = L;
    for (int i = 0; i < 7; i++)
    {
        s = new LNode;
        s -> no = i + 1;
        s -> pass = a[i];
        s -> next = NULL;
        r -> next = s;
        r = s;
    }
    s -> next = L;
}
void LinkListOutput(CircularLinkList &L)//输出循环链表中的数据
{

    LNode *p = L -> next;
    while(p != L)
    {
        printf("%d ",p -> pass);
        p = p -> next;
    }
    printf("\n");
}
int Length(CircularLinkList &L)//求取当前循环链表的长度即元素个数
{
    int length = 0;
    CircularLinkList p = L-> next;
    while(p != L)
    {
        p = p -> next;
        length++;
    }
    return length;
}
void ListDelete(CircularLinkList &L)
{
    int m;
    LNode *p, *q;//p，q分别表示指向循环链表的表头元素和表尾元素的指针
    p = L;
    q = L -> next;
    while(q != L)//让q指向表尾元素
        q = q -> next;
    m = 20;
    while (Length(L))//只要表长不为零，就执行出队操作
    {
        for(int j = 1; j < m; j++)//寻找出队元素的上一个结点
        {
            p = p -> next;
            if(p == q)//当p指向表尾元素时，跳过表头元素
                p = p -> next;
        }
        LNode *r;
        r = p -> next;//保存待删除的元素，以便释放指针所指的对象的空间
        if(r == L)//r指向表头，r应该指向表头下一个
        {
            r = L -> next;
            p -> next = L;//链接表头
            L -> next = r -> next;//修改表头的指针域
        }
        else
            p -> next = p -> next -> next;//链接待删除的元素的下一个
        printf("%d ",r -> no);
        m = r -> pass;
        delete r;
    }
}

int  main()
{
    CircularLinkList list;
    InitList(list);
    CreateList(list);
    LinkListOutput(list);
    ListDelete(list);
    return 0;
}*/
//静态链表版
/*#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct LNode
{
    int id;
    int password;
    LNode *next;
};
int main()
{
    int m,n;
    cout<<"Enter the number of people:";
    cin>>n;
    cout<<"Enter the value of 'm':";
    cin>>m;
    LNode* p=new LNode[n+1];
    cout<<"Enter the "<<n<<" people's password:"<<endl;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>p[i].password;
        p[i].id=i+1;
    }
    for(i=0; i<n-1; i++)
        p[i].next=&p[i+1];
    p[n-1].next=&p[0];
    LNode* temp=&p[0];
    LNode* last=&p[n-1];
    while(1)
    {
        for(i=0; i<m-1; i++)
        {
            if(i==m-2)
                last=temp;
            temp=temp->next;
        }
        last->next=temp->next;
        cout<<temp->id<<" ";
        --n;
        m=temp->password+1;
        if(n==0)
            break;
    }
    cout<<endl;
    delete []p;
    return 0;
}*/
//循环链表版
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct LNode
{
    int data;
    LNode *pNext;
};
int main()
{
    int n,k=1,m,i;
    LNode *p,*q,*head;
    cout<<"输入n的值:";
    cin>>n;
    cout<<"输入数到m出列的m的值:";
    cin>>m;
    head = (LNode *)new LNode;           //确定头结点
    p=head;
    for(i=1; i<=n-1; i++)                       //赋初值
    {
        p->data=i;
        p->pNext=(LNode*)new LNode;   //为下一个新建内存
        p=p->pNext;
    }
    p->data=n;                              //最后一个单独处理
    p->pNext=head;                        //指向头，形成循环链表
    p=head;
    while(p->data!=(p->pNext)->data)            //p->data==(p->pNext)->data表示只剩下一个结点的
    {
        while(p->data !=k)         //寻找编号为k的结点
            p=p->pNext;
        if(m==1)
        {
            for(i=1; i<=n; i++)
            {
                cout<<p->data<<'\t' ;
                p=p->pNext ;
            }
            cout<<'\n';
            return 0;
        }
        else
            for(i=1; i<m-1; i++)//开始报数
                p=p->pNext;//找到报m-1的结点
        q=p->pNext;//q为报m的结点
        cout<<q->data<<"\t";//输出报m的结点的值
        k=(q->pNext)->data;//k为下一个报数的起点
        p->pNext=q->pNext;//删除报m的结点
    }
    cout<<p->data<<'\n';//输出最后一个结点的值
    return 0;
}


