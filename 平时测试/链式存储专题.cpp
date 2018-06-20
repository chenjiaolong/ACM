//Team Queue
//方法一：单项链表模拟队列
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//struct node
//{
//    int data;
//    node *next;
//}*Q,*p,*ep[1010],*rear;//头指针，辅助指针，每队的尾指针（加快速度），队列尾指针
//int belong[1000010];
//int main()
//{
//    int t;
//    int group = 1;
//    while(scanf("%d",&t) && t)
//    {
//        for(int team = 0; team < t; team++)
//        {
//            int n;
//            scanf("%d",&n);
//            while(n --)
//            {
//                int num;
//                scanf("%d",&num);
//                belong[num] = team;
//            }
//        }
//        while(Q)
//        {
//            p = Q;
//            Q = Q -> next;
//            free(p);
//        }
//        printf("Scenario #%d\n",group++);
//        char str[10];
//        while(scanf("%s",str))
//        {
//            if(str[0] == 'S')
//                break;
//            node *p = (node *)malloc(sizeof(node));
//            if(str[0] == 'E')
//            {
//                scanf("%d",&p -> data);
//                p -> next = NULL;
//                if(Q == NULL)
//                {
//                    Q = p;
//                    rear = ep[belong[p -> data]] = p;
//                }
//                else
//                {
//                    if(ep[belong[p -> data]] && ep[belong[p -> data]] -> next)
//                    {
//                        p -> next = ep[belong[p -> data]] -> next;
//                        ep[belong[p -> data]] -> next = p;
//                        ep[belong[p -> data]] = p;
//                    }
//                    else
//                    {
//                        rear -> next = ep[belong[p -> data]] = p;
//                        rear = p;
//                    }
//                }
//            }
//            else
//            {
//                printf("%d\n",Q -> data);
//                p = Q;
//                if(Q -> next == NULL || belong[Q -> next -> data] != belong[p -> data])
//                    ep[belong[p -> data]] = NULL;
//                Q = Q -> next;
//                free(p);
//            }
//        }
//        printf("\n");
//
//    }
//    return 0;
//}

//方法二：数组模拟队列
//#include<string>
//#include<iostream>
//
//using namespace std;
//int belong[1000000];
//int pos[1005];
//struct node
//{
//	int x;
//	int next;
//}r[200010];
//int main()
//{
//	int x,t,i,j,n,No=0;
//	int front,back,used;                       //队首和队尾指针,新置入结点的地址。
//	string com;
//	while(cin>>t&&t)
//	{
//		front=-1;
//		back=-1;
//		used=-1;
//		for(i=0;i<t;++i)
//		{
//			cin>>n;                      //每组的人数。
//			for(j=0;j<n;++j)
//			{
//				cin>>x;
//				belong[x]=i;             //x属于第i组。
//			}
//			pos[i]=-1;                   //pos[i]代表第i组最后一个组员所在的位置,初始化为-1,代表队列中暂时没有同组人。
//		}
//		cout<<"Scenario #"<<++No<<endl;
//		while(cin>>com&&com!="STOP")
//		{
//			if(com=="ENQUEUE")                 //入队。
//			{
//				used++;
//				cin>>x;
//				if(pos[belong[x]]==-1)                 //队列中没有同组元素。
//				{
//					if(front==-1&&back==-1)            //第一个入队元素。
//					{
//						front=used;
//						back=used;
//						r[used].x=x;
//						r[used].next=-1;
//						pos[belong[x]]=used;
//					}
//					else                               //非第一个入队元素。
//					{
//						r[used].x=x;
//						r[used].next=-1;
//						r[back].next=used;
//						back=used;
//						pos[belong[x]]=used;
//					}
//				}
//				else                                    //队列中有同组元素，站在同组元素之后。
//				{
//					if(pos[belong[x]]==back)
//						back=used;
//					r[used].x=x;
//					r[used].next=r[pos[belong[x]]].next;
//					r[pos[belong[x]]].next=used;
//					pos[belong[x]]=used;
//				}
//			}
//			else if(com=="DEQUEUE")                    //出队。
//			{
//				cout<<r[front].x<<endl;
//				if(pos[belong[r[front].x]]==front)
//					pos[belong[r[front].x]]=-1;
//				front=r[front].next;
//				if(front==-1)
//					back=-1;
//			}
//		}
//		cout<<endl;
//	}
//	return 0;
//}

//方法三：链式队列
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//#define OVERFLOW -2
//
//typedef struct node
//{
//    int data;
//    struct node *next;
//}QNode,*QueuePtr;
//
//typedef struct
//{
//    QueuePtr front;
//    QueuePtr rear;
//}LinkQueue;
//
//int belong[1000010];
//QNode *ep[1010];
//
//void InitQueue(LinkQueue *Q)
//{
//    Q -> front = Q -> rear = (QueuePtr )malloc(sizeof(QNode));
//    if(!Q -> front)exit(OVERFLOW);
//    Q -> front -> next = NULL;
//}
//void DestroyQueue(LinkQueue *Q)
//{
//    while(Q -> front)
//    {
//        Q -> rear = Q -> front -> next;
//        free(Q -> front);
//        Q -> front = Q -> rear;
//    }
//}
//void ClearQueue(LinkQueue *Q)
//{
//    Q -> rear = Q -> front;
//    QueuePtr p,q;
//    p = Q -> front -> next;
//    Q -> front -> next = NULL;
//    while(p)
//    {
//        q = p;
//        p = p -> next;
//        free(q);
//    }
//}
//int main()
//{
//    int t;
//    int group = 1;
//    LinkQueue Q;
//    InitQueue(&Q);
//
//    while(~scanf("%d",&t) && t)
//    {
//        for(int team = 0; team < t; team++)
//        {
//            int n;
//            scanf("%d",&n);
//            while(n --)
//            {
//                int num;
//                scanf("%d",&num);
//                belong[num] = team;
//            }
//
//        }
//        ClearQueue(&Q);
//        printf("Scenario #%d\n",group++);
//        char str[10];
//        while(scanf("%s",str))
//        {
//            if(str[0] == 'S')
//                break;
//            QueuePtr p = (QueuePtr )malloc(sizeof(QNode));
//            if(str[0] == 'E')
//            {
//                scanf("%d",&p -> data);
//                p -> next = NULL;
//                if(Q.front -> next == NULL)
//                {
//                    Q.rear -> next = p;
//                    Q.rear = ep[belong[p -> data]] = p;
//                }
//                else
//                {
//                    if(ep[belong[p -> data]] && ep[belong[p -> data]] -> next)
//                    {
//                        p -> next = ep[belong[p -> data]] -> next;
//                        ep[belong[p -> data]] -> next = p;
//                        ep[belong[p -> data]] = p;
//                    }
//                    else
//                    {
//                        Q.rear -> next = ep[belong[p -> data]] = p;
//                        Q.rear = p;
//                    }
//                }
//            }
//            else
//            {
//                printf("%d\n",Q.front -> next -> data);
//                p = Q.front -> next;
//                if(Q.front -> next -> next == NULL || belong[Q.front -> next -> next -> data] != belong[p -> data])
//                    ep[belong[p -> data]] = NULL;
//                Q.front -> next = Q.front -> next -> next;
//                free(p);
//            }
//        }
//        printf("\n");
//
//    }
//    return 0;
//}

//数列有序！
//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct node
//{
//    int data;
//    struct node *next;
//}LNode,*LinkList;
//LinkList InitList(int n)
//{
//    LinkList pHead = (LinkList )malloc(sizeof(LNode));
//    pHead -> next = NULL;
//    LinkList r = pHead, p;
//    for(int i = 0; i < n; i++)
//    {
//        p = (LinkList )malloc(sizeof(LNode));
//        scanf("%d",&p -> data);
//        p -> next = NULL;
//        r -> next = p;
//        r = p;
//    }
//    return pHead;
//}
//void LinkListInsert(LinkList pHead,int m)
//{
//    LinkList p = pHead,s;
//    while(p -> next -> data < m && p -> next -> next != NULL)
//        p = p -> next;
//    if(p -> next -> data < m && p -> next != NULL)
//        p = p -> next;
//    s = (LinkList )malloc(sizeof(LNode));
//    s -> data = m;
//    s -> next = p -> next;
//    p -> next = s;
//}
//void Output(LinkList pHead)
//{
//    LinkList p = pHead -> next;
//    while(p)
//    {
//        if(p -> next != NULL)
//            printf("%d ",p -> data);
//        else
//            printf("%d\n",p -> data);
//        p = p -> next;
//    }
//}
//int main()
//{
//    int n,m;
//    while(scanf("%d%d",&n,&m) && n + m)
//    {
//        LinkList pHead;
//        pHead = InitList(n);
//        LinkListInsert(pHead,m);
//        Output(pHead);
//    }
//    return 0;
//}

//Assistance Required
//#include <stdio.h>
//#include <malloc.h>
//#define MaxSize 33810
//typedef struct node
//{
//    int data;
//    struct node *next;
//} LNode,*LinkList;
//LinkList InitList()
//{
//    LinkList pHead = (LinkList )malloc(sizeof(LNode));
//    pHead -> next = NULL;
//    return pHead;
//}
//void DestoryList(LinkList pHead)
//{
//    LinkList p = pHead,q;
//    while(p)
//    {
//        q = p -> next;
//        free(p);
//        p = q;
//    }
//}
//void isPrime(LinkList pHead)
//{
//    LinkList p = pHead;
//    bool array[MaxSize + 10];
//    for(int i = 0 ; i < MaxSize; i++)
//        array[i] = true;
//    array[0] = false,array[1] = false;
//    //int len = 0;
//    for(int i = 2; i < MaxSize; i++)
//        if(array[i] == true)
//        {
//            //len ++;
//            LinkList q = (LinkList )malloc(sizeof(LNode));
//            q -> data = i;
//            q -> next = NULL;
//            p -> next = q;
//            p = q;
//            int cnt = 0;
//            for(int j = i + 1; j < MaxSize; j++)
//                if(array[j] == true)
//                    if(++cnt == i)
//                    {
//                        cnt = 0;
//                        array[j] = false;
//                    }
//        }
//    //printf("%d\n",len);
//}
//void GetElem(LinkList pHead,int pos,int *e)
//{
//    if(pos < 1)
//        return ;
//    LinkList p = pHead -> next;
//    int cnt = 0;
//    while(p)
//    {
//        if(++ cnt == pos)
//        {
//            *e = p -> data;
//            return ;
//        }
//        p = p -> next;
//    }
//}
//int main()
//{
//    LinkList pHead = InitList();
//    isPrime(pHead);
//    int n;
//    while(~scanf("%d",&n) && n)
//    {
//        int *e = (int *)malloc(sizeof(int));
//        GetElem(pHead,n,e);
//        printf("%d\n",*e);
//    }
//    DestoryList(pHead);
//    return 0;
//}

// Joseph
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//struct node
//{
//    int data;
//    node *next;
//};
//
//node *Init()
//{
//    node *L = new node;
//    L -> next = nullptr;
//    node *tail = L;
//    for(int k = 1; k < 14; k ++)
//    {
//        int m = k + 1;
//        while(1)
//        {
//            int p = 1, total = 2 * k;
//            while(1)
//            {
//                p = (p + m - 2) % total -- + 1;
//                if(p <= k) break;
//                if(total == k - 1) break;
//            }
//            if(total == k - 1) break;
//            m++;
//        }
//        node *p = new node;
//        p -> data = m;
//        p -> next = tail -> next;
//        tail -> next = p;
//        tail = p;
//    }
//    return L;
//}
//
//int main()
//{
//    node *L;
//    L = Init();
//    int k;
//    while(scanf("%d", &k), k)
//    {
//        int cnt = 1;
//        node *p = L -> next;
//        while(p)
//        {
//            if(cnt ++ == k)
//            {
//                printf("%d\n", p -> data);
//                break;
//            }
//            p = p -> next;
//        }
//    }
//    return 0;
//}

// 文件系统
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//struct fileSystem
//{
//    char filename[100];
//    bool filetype; // 0-File 1- Dir;
//    fileSystem *last;
//    fileSystem *next;
//    fileSystem *parent;
//    fileSystem *son;
//};
//
//fileSystem *mkinitdir()
//{
//    fileSystem *head = new fileSystem;
//    head -> next = nullptr;
//    head -> parent = nullptr;
//    head -> son = nullptr;
//    head -> filetype = 1;
//    strcpy(head -> filename, ".");
//    return head;
//}
//fileSystem *cd(fileSystem *nowdir, fileSystem *home, char *con)
//{
//    fileSystem *temp = nowdir -> next, *t;
//    if(strcmp(con, "\\") == 0)
//    {
//        nowdir = home -> son;
//        puts("success");
//        return nowdir;
//    }
//    if(strcmp(con, "..") == 0)
//    {
//        if(nowdir -> parent != home)
//        {
//            nowdir = nowdir -> parent;
//            while(strcmp(nowdir -> filename, ".") != 0)
//                nowdir = nowdir -> last;
//        }
//        puts("success");
//        return nowdir;
//    }
//    while(temp != nullptr)
//    {
//        if (strcmp(temp -> filename, con) == 0 && temp -> filetype == 1)
//        {
//            if (temp -> son == NULL)
//            {
//                temp -> son = mkinitdir();
//                temp -> son -> parent = temp;
//                nowdir = temp -> son;
//                puts("success");
//                return nowdir;
//            }
//            else
//            {
//                nowdir = temp -> son;
//                puts("success");
//                return nowdir;
//            }
//        }
//        temp = temp -> next;
//    }
//    puts("no such directory");
//	return nowdir;
//}
//void mkdir(fileSystem *nowdir, fileSystem *head, char* con)
//{
//	fileSystem *temp;
//	temp = head;
//	while (temp != nullptr)
//	{
//		if (strcmp(temp -> filename, con) == 0 && temp -> filetype == 1)
//		{
//			puts("directory already exist");
//			return;
//		}
//		temp = temp -> next;
//	}
//	temp = mkinitdir();
//	temp -> parent = nowdir -> parent;
//	strcpy(temp -> filename, con);
//	while (head -> next != nullptr)
//		head = head -> next;
//	head -> next = temp;
//	temp -> last = head;
//	puts("success");
//}
//void rd(fileSystem *nowdir, char *con)
//{
//	fileSystem *temp = nowdir -> next;
//	while (temp != nullptr)
//	{
//		if (strcmp(temp -> filename, con) == 0 && temp -> filetype == 1)
//		{
//			if (temp -> son == nullptr || temp -> son -> next == nullptr)
//			{
//				if (temp -> next != nullptr)
//				{
//					temp -> last -> next = temp -> next;
//					temp -> next -> last = temp -> last;
//				}
//				else
//					temp -> last -> next = nullptr;
//				delete temp;
//				puts("success");
//				return;
//			}
//		}
//		temp = temp -> next;
//	}
//	printf("can not delete the directory\n");
//}
//void create(fileSystem *nowdir, char *con)
//{
//	fileSystem *temp = nowdir->next, *t = nowdir;
//	while (temp != nullptr)
//	{
//		if (strcmp(temp -> filename, con) == 0 && temp -> filetype == 0)
//		{
//			printf("file already exist\n");
//			return;
//		}
//		temp = temp -> next;
//	}
//	while (t -> next != nullptr)
//		t = t -> next;
//	temp = new fileSystem;
//	strcpy(temp -> filename, con);
//	temp -> filetype = 0;
//	temp -> last = t;
//	t -> next = temp;
//	temp -> next = nullptr;
//	puts("success");
//}
//void ls(fileSystem *nowdir)
//{
//	nowdir = nowdir->next;
//	if(nowdir != nullptr)
//		printf("%-30s%-5s\n", nowdir -> filename, nowdir -> filetype == 1 ? "DIR" : "FILE");
//}
//void deleteFile(fileSystem *nowdir, char *con)
//{
//	fileSystem *temp = nowdir -> next;
//	while (temp != nullptr)
//	{
//		if (strcmp(temp -> filename, con) == 0 && temp -> filetype == 0)
//		{
//			if (temp -> next != nullptr)
//			{
//				temp -> last -> next = temp -> next;
//				temp -> next -> last = temp -> last;
//			}
//			else
//				temp -> last -> next = nullptr;
//			delete temp;
//			puts("success");
//			return;
//		}
//		temp = temp -> next;
//	}
//	puts("no such file");
//}
//int main()
//{
//	fileSystem *head = nullptr, *home = nullptr, *nowdir = nullptr;
//
//	head = mkinitdir();
//	home = new fileSystem;
//	home -> next = home -> last = nullptr;
//	home -> parent = nullptr;
//	strcpy(home -> filename, "\\");
//	home -> son = head;
//	head -> parent = home;
//
//	nowdir = head;
//	char cmd[7], con[20];
//	while (scanf("%s%s", cmd, con)!=EOF)
//	{
//		if (strcmp(cmd, "MD") == 0) mkdir(nowdir, head, con);
//		else if (strcmp(cmd, "CD") == 0)
//		{
//			nowdir = cd(nowdir, home, con);
//			head = nowdir;
//		}
//		else if (strcmp(cmd, "RD") == 0) rd(nowdir, con);
//		else if (strcmp(cmd, "CREATE") == 0) create(nowdir, con);
//		else if (strcmp(cmd, "DELETE") == 0) deleteFile(nowdir, con);
//		else if (strcmp(cmd, "LS") == 0) ls(nowdir);
//	}
//}



//反转链表
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} LNode,*LinkList;
LinkList InitList(int n)
{
    LinkList pHead;
    pHead = (LinkList )malloc(sizeof(LNode));
    pHead -> next = NULL;
    LinkList r,p;
    r = pHead;
    for(int i = 0; i < n; i++)
    {
        p = (LinkList )malloc(sizeof(LNode));
        scanf("%d",&p -> data);
        p -> next = NULL;
        r -> next = p;
        r = p;
    }
    return pHead;
}
LinkList ReverseLinkList(LinkList pHead)
{
    if(pHead == NULL)
        return NULL;
    LinkList tmp, p;
    tmp = pHead -> next;
    while(tmp -> next != NULL)
    {
        p = tmp -> next;
        tmp -> next = p -> next;
        p -> next = pHead -> next;
        pHead -> next = p;
    }
    return pHead;
}
void Output(LinkList pHead)
{
    LinkList p = pHead -> next;
    while(p)
    {
        printf("%d%c",p -> data,p -> next != NULL ? ' ':'\n');
        p = p -> next;
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n == 0)
        {
            printf("NULL\n");
            continue;
        }
        LinkList pHead = InitList(n);
        ReverseLinkList(pHead);
        Output(pHead);
    }
    return 0;
}
