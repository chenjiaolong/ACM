// hihoCoder 1299 打折机票
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MAX 200010<<2
//using namespace std;
//int array[MAX];
//int T[MAX];
//void init(int left,int right,int pa)
//{
//    T[pa]=0;
//    if(left==right)
//    {
//        array[pa] = 0;
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa]=max(array[child],array[child|1]);
//}
//void updown(int cnt,int pa)
//{
//    if(T[pa])
//    {
//        int child=pa<<1;
//        T[child]=T[pa];
//        T[child|1]=T[pa];
//        array[child]=(cnt-(cnt>>1))*T[pa];
//        array[child|1]=(cnt>>1)*T[pa];
//        T[pa]=0;
//    }
//}
//int update(int left,int right,int pa,int start,int end,int num)
//{
//    if(start<=left&&right<=end)
//    {
//        if(num!=1<<29)
//        {
//            T[pa]=num;
//            array[pa]=(right-left+1)*num;
//        }
//        return array[pa];
//    }
//    updown(right-left+1,pa);
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int ans=-1<<29;
//    if(start<=mid)
//        ans=max(ans,update(left,mid,child,start,end,num));
//    if(mid<end)
//        ans=max(ans,update(mid+1,right,child|1,start,end,num));
//    array[pa]=max(array[child],array[child|1]);
//    return ans;
//}
//int main()
//{
//    int n,m;
//    while(~scanf("%d%d",&n,&m))
//    {
//        init(1,n,1);
//        int t,v;
//        for(int i = 1; i <= n; i++)
//        {
//            scanf("%d%d", &t, &v);
//            if(v > update(1, n, 1, t, t, 1 << 29))
//            update(1, n, 1, t, t, v);
//        }
//        int a, b;
//        for(int i = 1; i <= m; i++)
//        {
//            scanf("%d%d", &a, &b);
//            int Max = update(1, n, 1, a, b, 1 << 29);
//            if(Max == 0)
//                puts("None");
//            else
//                printf("%d\n", Max);
//        }
//    }
//    return 0;
//}

// hihocoder 1082 然而沼跃鱼早就看穿了一切
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//int main()
//{
//    char ch[15] = {"marshtomp"};
//    int len_T = strlen(ch);
//    char str[205];
//
//    while(gets(str) != NULL)
//    {
//        int cur = 0;
//        char ans[205] = {'\0'};
//        int len_S = strlen(str);
//        for(int i = 0; i < len_S; i++)
//        {
//            int k = i;
//            int j = 0;
//            while((str[k] == ch[j] || str[k] - 'A' + 'a' == ch[j]) && k < len_S)
//            {
//                k++;
//                j++;
//            }
//            if(j == len_T)
//            {
//                strcat(ans, "fjxmlhx");
//                cur += 7;
//                i = k - 1;
//                // putchar(str[i]);
//            }
//            else
//                ans[cur++] = str[i];
//        }
//        ans[cur++] = '\0';
//        puts(ans);
//    }
//    return 0;
//}

// hihocoder 1366 逆序单词
#include<map>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

map<string, bool>MyMap;

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        string str;
        MyMap.clear();
        int cnt = 0;
        for(int i = 1; i <= N; i ++)
        {
            cin >> str;
            int len = str.length();
            MyMap[str] = true;
            reverse(str.begin(), str.end());
            if(MyMap[str])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
