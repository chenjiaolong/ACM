//ѭ�������
/*#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef struct LNode
{
    int no, pass;
    LNode *next;
} LNode, *CircularLinkList;
void InitList(CircularLinkList &L)//��ʼ��һ���յ�ѭ������
{
    L = new LNode;
    L -> next == L;
}
void CreateList(CircularLinkList &L)//����һ��ѭ������
{
    int a[10] = {3, 1, 7, 2, 4, 8, 4};//��ʼ������
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
void LinkListOutput(CircularLinkList &L)//���ѭ�������е�����
{

    LNode *p = L -> next;
    while(p != L)
    {
        printf("%d ",p -> pass);
        p = p -> next;
    }
    printf("\n");
}
int Length(CircularLinkList &L)//��ȡ��ǰѭ������ĳ��ȼ�Ԫ�ظ���
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
    LNode *p, *q;//p��q�ֱ��ʾָ��ѭ������ı�ͷԪ�غͱ�βԪ�ص�ָ��
    p = L;
    q = L -> next;
    while(q != L)//��qָ���βԪ��
        q = q -> next;
    m = 20;
    while (Length(L))//ֻҪ����Ϊ�㣬��ִ�г��Ӳ���
    {
        for(int j = 1; j < m; j++)//Ѱ�ҳ���Ԫ�ص���һ�����
        {
            p = p -> next;
            if(p == q)//��pָ���βԪ��ʱ��������ͷԪ��
                p = p -> next;
        }
        LNode *r;
        r = p -> next;//�����ɾ����Ԫ�أ��Ա��ͷ�ָ����ָ�Ķ���Ŀռ�
        if(r == L)//rָ���ͷ��rӦ��ָ���ͷ��һ��
        {
            r = L -> next;
            p -> next = L;//���ӱ�ͷ
            L -> next = r -> next;//�޸ı�ͷ��ָ����
        }
        else
            p -> next = p -> next -> next;//���Ӵ�ɾ����Ԫ�ص���һ��
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
//��̬�����
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
//ѭ�������
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
    cout<<"����n��ֵ:";
    cin>>n;
    cout<<"��������m���е�m��ֵ:";
    cin>>m;
    head = (LNode *)new LNode;           //ȷ��ͷ���
    p=head;
    for(i=1; i<=n-1; i++)                       //����ֵ
    {
        p->data=i;
        p->pNext=(LNode*)new LNode;   //Ϊ��һ���½��ڴ�
        p=p->pNext;
    }
    p->data=n;                              //���һ����������
    p->pNext=head;                        //ָ��ͷ���γ�ѭ������
    p=head;
    while(p->data!=(p->pNext)->data)            //p->data==(p->pNext)->data��ʾֻʣ��һ������
    {
        while(p->data !=k)         //Ѱ�ұ��Ϊk�Ľ��
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
            for(i=1; i<m-1; i++)//��ʼ����
                p=p->pNext;//�ҵ���m-1�Ľ��
        q=p->pNext;//qΪ��m�Ľ��
        cout<<q->data<<"\t";//�����m�Ľ���ֵ
        k=(q->pNext)->data;//kΪ��һ�����������
        p->pNext=q->pNext;//ɾ����m�Ľ��
    }
    cout<<p->data<<'\n';//������һ������ֵ
    return 0;
}


