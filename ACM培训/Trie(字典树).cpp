// 输入一个字符串，下面输入前缀字符串，求每个字符串出现的次数
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn=4000100;
//int cur=1;
//char str[10010][100];
//int n,m;
//struct node
//{
//    int next[10];//每个节点有0-9 10个节点
//    int ans;//到这个节点为止前缀出现的次数
//    void init()//初始化
//    {
//        ans=0;
//        memset(next,-1,sizeof(next));
//    }
//};
//node t[maxn];
//void in(char *s,int len)//录取数据
//{
//    int p=0;//从根节点（0）开始遍历，0相当于根节点
//    //接下来遍历字符串
//    for(int i=0;i<len;i++)
//    {
//        int x=s[i]-'0';//获得节点的位置
//        if(t[p].next[x]==-1)//如果该节点没被建立过（没有经过）
//        {
//          t[cur].init();//初始化 从新建立一个新的节点
//          t[p].next[x]=cur++;//获取节点的下标||//cur是下标,每次建立一个下标，cur++;
//        }
//        p=t[p].next[x];
//        t[p].ans++;//前缀个数++
//    }
//}
//int getans(char *s,int len)//存完后查找路径
//{
//    int p=0;
//    for(int i=0;i<len;i++)
//    {
//        int x=s[i]-'0';
//        if(t[p].next[x]==-1)
//            return 0;
//        p=t[p].next[x];
//    }
//    return t[p].ans;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        t[0].init();
//        for(int i=0;i<n;i++)
//        {
//            scanf("%s",str[i]);
//            int len=strlen(str[i]);
//            in(str[i],len);
//        }
//        while(m--)
//        {
//            char s1[100];
//            scanf("%s",s1);
//            int len=strlen(s1);
//            int cnt=getans(s1,len);
//            printf("%d\n",cnt);
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define MAX 26 // 字符集大小
//const int maxn = 6e5 + 10;
//const int maxm = 1e4 + 100;
//char str[maxn][100];
//typedef struct node
//{
//    int cnt; // 记录字符出现次数
//    struct node *next[MAX];
//}TrieNode;
//
//TrieNode Memory[maxn];
//int allocp = 0;
//// 初始化
//void InitTrieRoot(TrieNode ** pRoot)
//{
//    *pRoot = NULL;
//}
//// 创建新结点
//TrieNode *CreateTrieNode()
//{
//    TrieNode *p;
//    p = &Memory[allocp++];
//    p -> cnt = 0;
//    for(int i = 0; i < MAX; i++)
//        p->next[i] = NULL;
//    return p;
//}
//// 插入
//void InsertTrie(TrieNode **pRoot, char * s)
//{
//    TrieNode *p;
//    if(!(p = *pRoot)) p = *pRoot = CreateTrieNode();
//    int i = 0, k;
//    while(s[i])
//    {
//        k = s[i++] - 'a';// 确定 branch
//        if(!p -> next[k])
//            p -> next[k] = CreateTrieNode();
//        p -> next[k] -> cnt ++;
//        p = p -> next[k];
//    }
//}
//// 查找
//int SearchTrie(TrieNode ** pRoot, char *s)
//{
//    TrieNode *p;
//    if(! (p = *pRoot))
//        return 0;
//    int i = 0, k;
//    while(s[i])
//    {
//        k = s[i++] - 'a';
//        if(p -> next[k] == NULL) return 0;
//        p = p -> next[k];
//    }
//    return p -> cnt;
//}
//// 销毁
//void DeleteTrie(TrieNode **pRoot)
//{
//    TrieNode *p = *pRoot;
//    for(int i = 0;  i < MAX; i ++)
//        if(p -> next[i] != NULL)
//        DeleteTrie(&p -> next[i]);
//    delete []p -> next;
//}
//int main()
//{
//    int cur = 0;
//    TrieNode *head;
//    InitTrieRoot(&head);
//    while(gets(str[cur]), str[cur][0] != '\0')
//    {
//        InsertTrie(&head, str[cur++]);
//    }
//    char s[100];
//    while(gets(s), s[0] != '\0')
//    {
//        printf("%d\n", SearchTrie(&head, s));
//    }
//    DeleteTrie(&head);
//    return 0;
//}

//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//namespace trie
//{
//template<class T, size_t CHILD_MAX>
///**
//* Parameter T: Typedef of reserved data.
//* Parameter CHILD_MAX: Size of array of pointers to child node.
//*/
//struct node
//{
//    T reserved;
//    node<T, CHILD_MAX> *child[CHILD_MAX];
//    node() { memset(this, 0, sizeof * this); }
//    ~node()
//    {
//        for(unsigned i = 0; i < CHILD_MAX; i++) delete child[i];
//    }
//    void Traversal(char *str, unsigned index)
//    {
//        for(unsigned i = 0; i < index; i++)
//            cout << str[i];
//        cout << '\t' << reserved << endl;
//        for(unsigned i = 0; i < CHILD_MAX; i++)
//            if(child[i])
//            {
//                str[index] = i;
//                child[i] -> Traversal(str, index + 1);
//            }
//        return;
//    }
//
//};
//template <class T, size_t CHILD_MAX = 127>
//class trie
//{
//private:
//    node<T, CHILD_MAX>root;
//public:
//    node<T, CHILD_MAX> *AddStr(char*str);
//    node<T, CHILD_MAX> *FindStr(char*str);
//    bool DeleteStr(char *str);
//    void Traversal()
//    {
//        char str[100];
//        root.Traversal(str, 0);
//    }
//};
//template<class T, size_t CHILD_MAX>
//node<T, CHILD_MAX> *trie<T, CHILD_MAX> :: AddStr(char *str)
//{
//    node<T, CHILD_MAX> *now = &root;
//    do
//    {
//        if(now -> child[*str] == NULL)
//            now -> child[*str] = new node<T, CHILD_MAX>;
//        now = now -> child[*str];
//    }
//    while(*(++str) != '\0');
//    return now;
//}
//template<class T, size_t CHILD_MAX>
//node<T, CHILD_MAX> *trie<T, CHILD_MAX> :: FindStr(char *str)
//{
//    node<T, CHILD_MAX>*now = &root;
//    do
//    {
//        if(now -> child[*str] == NULL)return NULL;
//        now = now -> child[*str];
//    }
//    while(*(++str) != '\0');
//    return now;
//}
//template<class T, size_t CHILD_MAX>
//bool trie<T, CHILD_MAX> :: DeleteStr(char *str)
//{
//    node<T, CHILD_MAX> **nodes = new node<T, CHILD_MAX> * [strlen(str)];
//    int snodes = 1;
//    node<T, CHILD_MAX> *now = &root;
//    nodes[0] = &root;
//    do
//    {
//        if(now->child[*str] == NULL) return false;
//        nodes[snodes++] = now = now -> child[*str];
//    }
//    while(*(++str)!='\0');
//    snodes--;
//    while(snodes > 0)
//    {
//        for(unsigned i = 0; i < CHILD_MAX; i++)
//            if(nodes[snodes] -> child[i] != NULL) return true;
//        delete nodes[snodes];
//        nodes[--snodes] -> child[*(--str)] = NULL;
//    }
//    return true;
//}
//}
//int main()
//{
//    //Test Program
//    trie :: trie<int>tree;
//    while(1)
//    {
//        cout << "1 for add a string" << endl;
//        cout << "2 for find a string" << endl;
//        cout << "3 for delete a string" << endl;
//        cout << "4 for traversal" << endl;
//        cout << "5 for exit" << endl;
//        char str[100];
//        switch(getch())
//        {
//        case '1':
//            cin.getline(str, 100);
//            cout << "This sting has existed for " << tree.AddStr(str) -> reserved++ << " times." << endl;
//            break;
//        case '2':
//            cin.getline(str, 100);
//            trie :: node<int, 127>*find;
//            find = tree.FindStr(str);
//            if(!find) cout << "No found." << endl;
//            else cout << "This sting has existed for " << find -> reserved << " times." << endl;
//            break;
//        case '3':
//            cin.getline(str, 100);
//            cout << "The action is " << (tree.DeleteStr(str) ? "Successful." : "Unsuccessful.") << endl;
//            break;
//        case '4':
//            tree.Traversal();
//            break;
//        case '5':
//            return 0;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int N(5e5+5);
//struct node
//{
//    int id, dep, nt[26];
//    void init(int _id, int _dep)
//    {
//        id=_id, dep=_dep, memset(nt, 0, sizeof(nt));
//    }
//    void renew()
//    {
//        id=0;
//    }
//} trie[N];
//char s[N];
//bool vis[1005];
//void build_trie(int n)
//{
//    int tot=0;
//    trie[tot].init(0, 0); //error-prone
//    for(int id=1; id<=n; id++)
//    {
//        cin>>s;
//        for(int i=0, now=0; s[i]; i++)
//        {
//            int &nt=trie[now].nt[s[i]-'a'];
//            now=nt?trie[nt].renew(),nt:(trie[++tot].init(id, i+1), nt=tot);
//        }
//    }
//    int res=0;
//    for(int i=0; i<=tot; i++)
//    {
//        if(trie[i].id&&!vis[trie[i].id]) res+=trie[i].dep, vis[trie[i].id]=true;
//    }
//    cout<<res<<endl;
//}
//
//int main()
//{
//    // freopen("in", "r", stdin);
//    int T, n;
//    for(cin>>T; T--; memset(vis, 0, sizeof(vis)))
//    {
//        cin>>n;
//        build_trie(n);
//    }
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
const int maxn =4e6 + 100;
char str[maxn];

struct TrieNode
{
    bool flag;
    TrieNode *next[26];
    int ans;
    TrieNode()
    {
        flag = false;
        ans = 0;
        for(int i = 0; i < 26; i ++)
            next[i] = NULL;
    }
}*head;
void Bulid(char *s)
{
    TrieNode *p = head;
    for(int i = 0; s[i]; i ++)
    {
        int index = s[i] - 'a';
        if(!p -> next[index]) p -> next[index] = new TrieNode;
        p = p -> next[index];
        p -> ans++;
    }
    p -> flag = true;
    return;
}
int SearchTrie(char *s)
{
    TrieNode *p = head;
    for(int i = 0; s[i]; i ++)
    {
        int index = s[i] - 'a';
        if(!p -> next[index])
        {
            puts("False");
            return 0;
        }
        p = p -> next[index];
    }
    puts("True");
    return p -> ans;
}
void DeleteTrie(TrieNode *head)
{
    TrieNode *p = head;
    for(int i = 0; i < 26; i ++)
        if(p -> next[i]) DeleteTrie(p -> next[i]);
    delete p;
}
int main()
{
    head = new TrieNode;
    while(gets(str) != NULL)
    {
        if(str[0] == '\0') break;
        Bulid(str);
    }
    while(gets(str) != NULL)
    {
        printf("%d\n", SearchTrie(str));
    }
    DeleteTrie(head);
    return 0;
}

