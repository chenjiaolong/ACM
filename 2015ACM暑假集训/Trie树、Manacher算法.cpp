//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn=1000010;
//char s[maxn],S[maxn],ss[maxn<<1];
//int dp[maxn<<1];
//int main()
//{
//    int T=0;
//    while(~scanf("%s",S))
//    {
//        if(strcmp(S,"END")==0)
//            break;
//        strcpy(s+1,S);
//        int len=strlen(s+1);
//        for(int i=1; i<=len; i++)
//        {
//            ss[i<<1]=s[i];
//            ss[i<<1|1]='#';
//        }
//        ss[0]='!';
//        ss[1]='#';
//        int n=(len+1)<<1;
//        ss[n]='\0';
//        int MaxId=0,id=0,MaxL=0;
//        for(int i=1; i<n; i++)
//        {
//            if(MaxId>i)
//                dp[i]=min(dp[(id<<1)-i],MaxId-i);
//            else
//                dp[i]=1;
//            while(ss[i-dp[i]]==ss[i+dp[i]])
//                dp[i]++;
//            if(dp[i]+i>MaxId)
//            {
//                MaxId=dp[i]+i;
//                id=i;
//            }
//            if(MaxL<dp[i])
//                MaxL=dp[i];
//        }
//        printf("Case %d: %d\n",++T,MaxL-1);
//    }
//    return 0;
//}

// 静态数组
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200100;
int cur=1;
char str[10005][12];
int n,m;
struct node
{
    int next[15];//每个节点有0-9 10个节点
    int ans;//到这个节点为止前缀出现的次数
    void init()//初始化
    {
        ans=0;
        memset(next,-1,sizeof(next));
    }
};
node t[maxn];
void in(char *s,int len)
{
    int p=0;//从根节点（0）开始遍历
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'0';//获得节点的位置
        if(t[p].next[x]==-1)//该节点没被建立过（没有经过）
        {
            t[cur].init();//初始化 从新建立一个新的节点
            t[p].next[x]=cur++;//获取节点的下标
        }
        p=t[p].next[x];
        t[p].ans++;//前缀个数++
    }
}
int getans(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'0';
        if(t[p].next[x]==-1)
            return 0;
        p=t[p].next[x];
    }
    return t[p].ans;
}
int main()
{
    int T,n;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            cur = 1;
            t[0].init();
            scanf("%d",&n);
            int flag=0;
            for(int i=0; i<n; i++)
            {
                scanf("%s",str[i]);
                int len=strlen(str[i]);
                in(str[i],len);
            }
            for(int i=0; i<n; i++)
            {
                int len=strlen(str[i]);
                int cnt=getans(str[i],len);
                if(cnt>1)
                    flag=1;
            }
            if(flag)
                printf("NO\n");
            else
                printf("YES\n");
            memset(str,'\0',sizeof(str));
        }
    }
    return 0;
}

// 动态建树
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//struct TrieNode
//{
//    TrieNode *next[10];
//    bool flag;
//    TrieNode()
//    {
//        flag = false;
//        for(int i = 0; i < 10; i ++)
//            next[i] = NULL;
//    }
//}*head;
//bool flag;
//void Bulid(char *s)
//{
//    bool used = true;
//    TrieNode *p = head;
//    for(int i = 0; s[i]; i ++)
//    {
//        int index = s[i] - '0';
//        if(!p -> next[index])
//        {
//            p -> next[index] = new TrieNode;
//            used = false;
//        }
//        if(p -> flag)
//        {
//            flag = true;
//            return ;
//        }
//        p = p -> next[index];
//    }
//    if(used) flag = true;
//    p -> flag = true;
//}
//void DeleteTrie(TrieNode *p)
//{
//    for(int i = 0; i < 10; i ++)
//        if(p -> next[i] != NULL)
//        DeleteTrie(p -> next[i]);
//    delete[] p -> next;
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        int n;
//        char str[10005][15] = {'\0'};
//        flag = false;
//        head = new TrieNode;
//        scanf("%d", &n);
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%s", str[i]);
//            if(!flag) Bulid(str[i]);
//        }
//        if(flag) puts("NO");
//        else puts("YES");
//        DeleteTrie(head);
//    }
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn=4000100;
//int cur=1;
//char str[100010][100];
//int n,m;
//struct node
//{
//    int next[27];//每个节点有0-9 10个节点
//    int ans;//到这个节点为止前缀出现的次数
//    void init()//初始化
//    {
//        ans=0;
//        memset(next,-1,sizeof(next));
//    }
//};
//node t[maxn];
//void in(char *s,int len)
//{
//    int p=0;//从根节点（0）开始遍历
//    for(int i=0; i<len; i++)
//    {
//        int x=s[i]-'a';//获得节点的位置
//        if(t[p].next[x]==-1)//该节点没被建立过（没有经过）
//        {
//            t[cur].init();//初始化 从新建立一个新的节点
//            t[p].next[x]=cur++;//获取节点的下标
//        }
//        p=t[p].next[x];
//        t[p].ans++;//前缀个数++
//    }
//}
//int getans(char *s,int len)
//{
//    int p=0;
//    for(int i=0; i<len; i++)
//    {
//        int x=s[i]-'a';
//        if(t[p].next[x]==-1)
//            return 0;
//        p=t[p].next[x];
//    }
//    return t[p].ans;
//}
//int main()
//{
//    t[0].init();
//    int count=0;
//    while(gets(str[count])&&str[count][0]!='\0')
//    {
//        int len=strlen(str[count]);
//        in(str[count],len);
//        count++;
//    }
//    char s1[100];
//    while(~scanf("%s",s1))
//    {
//        int len=strlen(s1);
//        int cnt=getans(s1,len);
//        printf("%d\n",cnt);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<map>
//using namespace std;
//map<string,int> str;
//int main()
//{
//    int N;
//    string s,ss;
//    //char s[1005],ss[1005];
//    while(~scanf("%d",&N)&&N)
//    {
//        int temp=0;
//        while(N--)
//        {
//            cin>>s;
//            //scanf("%s",s);
//            str[s]++;
//            if(str[s]>temp)
//            {
//                temp=str[s];
//                ss=s;
//                //strcpy(ss,s);
//            }
//        }
//        cout<<ss<<endl;
//        //printf("%s\n",ss);
//        str.clear();
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<map>
//#include<iostream>
//using namespace std;
//map<string,string>str;
//int main()
//{
//    char s[30],ss[15],sss[15];
//    while(gets(s)&&s[0]!='\0')
//    {
//        int i;
//        for(i=0; s[i]!=' '; i++)
//            ss[i]=s[i];
//        ss[i]='\0';
//        strcpy(sss,s+i+1);
//        str[sss]=ss;
//    }
//    string s1;
//    while(cin>>s1)
//    {
//        if(str[s1][0]=='\0')
//            cout<<"eh"<<endl;
//        else
//            cout<<str[s1]<<endl;
//    }
//    return 0;
//}

//#include<map>
//#include<string>
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//map<string,string>str;
////map<string,string>::iterator str2;
//int main()
//{
//    char s[30],ss[15],sss[15];
//    while(gets(s)&&strcmp(s,"END")!=0)
//    {
//        if(strcmp(s,"START")==0)
//            continue;
//        int i;
//        for(i=0; s[i]!=' '; i++)
//            ss[i]=s[i];
//        ss[i]='\0';
//        strcpy(sss,s+i+1);
//        str[sss]=ss;
//    }
//    char s1[10000],s2[15];
//    while(gets(s1)&&strcmp(s1,"END")!=0)
//    {
//        if(strcmp(s1,"START")==0)
//            continue;
//        int len=strlen(s1);
//        int j=0;
//        for(int i=0; i<=len; i++)
//        {
//            if(s1[i]>='a'&&s1[i]<='z')
//                s2[j++]=s1[i];
//            else
//            {
//                s2[j]='\0';
//                //str2=str.find(s2);
//                //if(str2!=str.end()) cout<<str[s2];
//                if(str[s2][0]!='\0')
//                    cout<<str[s2];
//                else
//                    cout<<s2;
//                if(s1[i]!='\0')
//                    cout<<s1[i];
//                j=0;
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
