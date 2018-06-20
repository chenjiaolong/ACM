//墨迹扩散
//#include <stdio.h>
//int main ()
//{
//    int M,N,T,i,j,k,array[200][200];
//    while(scanf("%d%d%d",&M,&N,&T)!=EOF)
//    {
//        for(i=0; i<M; i++)
//            for(j=0; j<N; j++)
//                scanf("%d",&array[i][j]);
//        for(k=1; k<=T; k++)
//            for(i=0; i<M; i++)
//                for(j=0; j<N; j++)
//                    if(array[i][j]==k)
//                    {
//                        if(array[i-1][j]!=k)
//                        array[i-1][j]=k+1;
//                        if(array[i+1][j]!=k)
//                        array[i+1][j]=k+1;
//                        if(array[i][j-1]!=k)
//                        array[i][j-1]=k+1;
//                        if(array[i][j+1]!=k)
//                        array[i][j+1]=k+1;
//                    }
//        for(i=0; i<M; i++)
//            for(j=0; j<N; j++)
//            {
//                if(array[i][j]!=0)
//                    array[i][j]=1;
//                printf("%d%c",array[i][j],j==N-1?'\n':' ');
//            }
//        printf("\n");
//    }
//    return 0;
//}

//数字的尾巴：得到一个正整数，然后你写下一个不大于这个数一半的正整数，对你刚写下的这个正整数做同样的操作。直到无法再写数字为止。由此可见呢，一个数字会有很多种不同“尾巴”，尾巴指的是你所写下的数字串。
//给出一个数字N（1<=N<=1000）,它的尾巴有多少种？
//#include<stdio.h>
//int array[1001];
//int isdealt[1001];
//int count_s(int n)
//{
//    if(n==1||n==2)
//        return 1;
//    if(isdealt[n]==1)
//        return array[n];
//    else
//    {
//        int total=0;
//        int i,half;
//        if(n%2==0)
//            half = n/2;
//        else
//            half = (n-1)/2;
//        for(i=1; i<=half; i++)
//            total+=count_s(i);
//        isdealt[n]=1;
//        array[n]=total;
//        return total;
//    }
//}
//int main()
//{
//    int i;
//    for(i=0; i<1001; i++)
//        isdealt[i]=0;
//    isdealt[1]=1;
//    isdealt[2]=1;
//    array[1]=1;
//    array[2]=1;
//    for(i=1; i<1001; i++)
//        count_s(i);
//    array[0]=0;
//    array[1]=0;
//    int N;
//    while(scanf("%d",&N)!=EOF)
//        printf("%d\n",array[N]);
//    return 0;
//}

//C语言线性表
//A N s f i：A表示插入操作。往该线性表的第N个位置插入一个线性表元素（s,f,i）。若N大于该线性表当前的长度那么就在该线性表的末尾添加这个元素。
//D N：D表示删除操作。删除该线性表的第N个位置的元素。同样的如果N大于该线性表当前的长度那么就删除该线性表的最后一个元素，下同。
//C N s f i：C表示修改操作。用（s,f,i）替换掉地N个位置的元素。
//S ch：S表示排序操作。而char类型ch以什么的值来排序，ch可以是 s,f或者i。始终以升序排序。字符串的是以字典序来排序。
//X N：X表示询问操作。询问第N个元素的值。其中float类型保留2位小数。
//O：O操作为输出当前这个顺序表。

//输如样例
//9
//A 1 qwerjonfa 1234.234 123
//A 2 aoeifasdfoijfneq 1234.32 1234
//A 2 adfjoenqe 1234.24 12345
//X 3
//S s
//X 2
//D 2
//X 2
//O

//输出样例
//aoeifasdfoijfneq 1234.32 1234
//aoeifasdfoijfneq 1234.32 1234
//qwerjonfa 1234.23 123
//adfjoenqe 1234.24 12345
//qwerjonfa 1234.23 123
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<string.h>
//typedef struct LNode
//{
//    char s[1005];
//    float f;
//    int i;
//    struct LNode *next;
//} LNode,*LinkList;
//LinkList InitList()
//{
//    LinkList pHead = (LinkList) malloc(sizeof(LNode));
//    pHead -> next = NULL;
//    return pHead;
//}
//int ListInsert(LinkList pHead,int N,char s[],float f,int i)
//{
//    LinkList p = pHead,pNew;
//    if(N < 1)
//        return 0;
//    int cnt = 0;
//    while(p -> next != NULL)
//    {
//        if(++cnt ==  N)
//        {
//            pNew = (LNode *)malloc(sizeof(LNode));
//            strcpy(pNew -> s,s);
//            pNew -> f = f;
//            pNew -> i = i;
//            pNew -> next = p -> next;
//            p -> next = pNew;
//            return 1;
//        }
//        p = p -> next;
//    }
//    pNew = (LinkList) malloc(sizeof(LNode));
//    strcpy(pNew -> s,s);
//    pNew -> f = f;
//    pNew -> i = i;
//    pNew -> next = p -> next;
//    p -> next = pNew;
//    return 1;
//}
//int ListDelete(LinkList pHead,int N)
//{
//    LinkList p = pHead,q;
//    if(N < 1)
//        return 0;
//    int cnt = 0;
//    while(p -> next != NULL)
//    {
//        if(++cnt == N)
//        {
//            q = p -> next;
//            p -> next = q -> next;
//            free(q);
//            return 1;
//        }
//        p = p -> next;
//    }
//    return 0;
//}
//int ModifyElem(LinkList pHead,int N,char s[],float f,int i)
//{
//    LinkList p = pHead -> next;
//    if(N < 1)
//        return 0;
//    int cnt = 0;
//    while(p != NULL)
//    {
//        if(++cnt == N)
//        {
//            strcpy(p -> s,s);
//            p -> f = f;
//            p -> i = i;
//            return 1;
//        }
//        p = p -> next;
//    }
//    return 0;
//}
//void SortLinkList_s(LinkList pHead)
//{
//    if(pHead -> next == NULL || pHead -> next -> next ==NULL)
//        return ;
//    LinkList p = pHead -> next -> next,q,pre;
//    pHead -> next -> next = NULL;
//    while(p != NULL)
//    {
//        pre = pHead;
//        q = p;
//        p = p -> next;
//        while(pre -> next != NULL && strcmp(pre -> next -> s,q -> s) < 0)
//            pre = pre -> next;
//        q -> next = pre -> next;
//        pre -> next = q;
//    }
//    return ;
//
//}
//void SortLinkList_f(LinkList pHead)
//{
//    if(pHead -> next == NULL || pHead -> next -> next ==NULL)
//        return ;
//    LinkList p = pHead -> next -> next,pre,q;
//    pHead -> next -> next = NULL;
//    while(p != NULL)
//    {
//        pre = pHead;
//        q = p;
//        p = p -> next;
//        while(pre -> next != NULL && pre -> next -> f < q -> f)
//            pre = pre -> next;
//        q -> next = pre -> next;
//        pre -> next = q;
//    }
//    return ;
//}
//void SortLinkList_i(LinkList pHead)
//{
//    if(pHead -> next == NULL || pHead -> next -> next == NULL)
//        return ;
//    LinkList p = pHead -> next -> next,pre,q;
//    pHead -> next -> next = NULL;
//    while(p != NULL)
//    {
//        pre = pHead;
//        q = p;
//        p = p -> next;
//        while(pre -> next != NULL && pre -> next -> i < q -> i)
//            pre = pre -> next;
//        q -> next = pre -> next;
//        pre -> next = q;
//    }
//    return ;
//}
//void GetElem(LinkList pHead,int N)
//{
//    LinkList p = pHead -> next;
//    if(N < 1) return ;
//    int cnt = 0;
//    while(p != NULL)
//    {
//        if(++cnt == N)
//        {
//            printf("%s %.2f %d\n",p -> s,p -> f,p -> i);
//            return ;
//        }
//        p = p ->next;
//    }
//    return ;
//}
//void LinkListOutput(LinkList pHead)
//{
//    LinkList p = pHead -> next;
//    while(p != NULL)
//    {
//        printf("%s %.2f %d\n",p -> s,p -> f,p -> i);
//        p = p ->next;
//    }
//}
//int main()
//{
//    struct LNode *pHead = NULL;
//    pHead = InitList();
//    int n;
//    while(scanf("%d",&n) == 1)
//    {
//        while(n--)
//        {
//            char op[5];
//            scanf("%s",op);
//            switch(op[0])
//            {
//            case 'A':
//                int N,num;
//                char str[1005];
//                float fnum;
//                scanf("%d%s%f%d",&N,str,&fnum,&num);
//                ListInsert(pHead,N,str,fnum,num);
//                break;
//            case 'D':
//                scanf("%d",&N);
//                ListDelete(pHead,N);
//                break;
//            case 'C':
//                scanf("%d%s%f%d",&N,str,fnum,num);
//                ModifyElem(pHead,N,str,fnum,num);
//                break;
//            case 'S':
//                char ch[5];
//                scanf("%s",ch);
//                if(ch[0] == 's')
//                    SortLinkList_s(pHead);
//                else if(ch[0] == 'f')
//                    SortLinkList_f(pHead);
//                else
//                    SortLinkList_i(pHead);
//                break;
//            case 'X':
//                scanf("%d",&N);
//                GetElem(pHead,N);
//                break;
//            case 'O':
//                LinkListOutput(pHead);
//                break;
//            }
//        }
//    }
//    return 0;
//}

//The Game of 31
//输入样例
//356656
//35665
//3566
//111126666
//552525

//输出样例
//356656 B
//35665 B
//3566 A
//111126666 A
//552525 A
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//#include<memory.h>
//using namespace std;
//int cnt[7];
//bool DFS(int sum)
//{
//    if(sum >= 31) return false;
//    for(int i = 1; i <= 6; i++)
//    {
//        if(cnt[i] && sum + i <= 31)
//        {
//            cnt[i] --;
//            if(DFS(sum + i) == 0)
//            {
//                cnt[i] ++;
//                return true;
//            }
//            cnt[i] ++;
//        }
//    }
//    return false;
//}
//int main(int argc,char *argv[])
//{
//    char str[35];
//    while(scanf("%s",str) != EOF)
//    {
//        for(int i = 1; i <= 6; i++)
//            cnt[i] = 4;
//        int sum = 0;
//        int len = strlen(str);
//        for(int i = 0; i < len; i++)
//        {
//            sum += str[i] - '0';
//            cnt[str[i] - '0'] --;
//        }
//        printf("%s ",str);
//        if(sum >= 31)
//        {
//            if(len & 1) puts("A");
//            else puts("B");
//            continue;
//        }
//        if(DFS(sum))
//        {
//            if(len & 1) puts("B");
//            else puts("A");
//        }
//        else
//        {
//            if(len & 1) puts("A");
//            else puts("B");
//        }
//
//    }
//    return 0;
//}

//The Game about KILL(和约瑟夫归则一样，归律)
//题意：给出一个人数n，问以间隔2来去除，最后一个留下的是编号几。
//归律：1：1  2：1  3：3  4：1  5：3  6：5  7：5  8：1  9：3  10：5  .......
//可以看出输出的都是奇数，而且从2^k都是1，之后都是奇数递增。
//约瑟夫环，n太大，首先可以想到打表找看有没有规律
//可以发现是有规律的
//可以看到，只要是2的i次幂，那么存活的是1，后面的依次加2
//例如4为1,5就是3,6->5,7->7,8->1
#include<stdio.h>
int main()
{
    int F[32];
    F[0] = 1;
    for(int i = 1; i < 31; i ++)
        F[i] = F[i-1] * 2;
    int N;
    while(scanf("%d",&N) == 1)
    {
        int i;
        for(i = 0; i < 31; i ++)
            if(N < F[i]) break;
        printf("%d\n",2 * (N - F[i - 1]) +1);
    }
    return 0;
}
