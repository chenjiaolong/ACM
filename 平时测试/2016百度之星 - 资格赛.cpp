// D
//#include<map>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//map<string, int>SS;
//int main()
//{
//    int N;
//    scanf("%d", &N);
//    SS.clear();
//    while(N --)
//    {
//        string str;
//        cin >> str;
//        sort(str.begin(), str.end());
//        printf("%d\n",SS[str]);
//        SS[str] ++;
//    }
//    return 0;
//}

// B
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//// 两个大数相加
//string sum(string s1, string s2)
//{
//    if(s1.length() < s2.length())
//    {
//        string temp=s1;
//        s1=s2;
//        s2=temp;
//    }
//    int i,j;
//    for(i=s1.length()-1,j=s2.length()-1; i>=0; i--,j--)
//    {
//        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
//        if(s1[i]-'0'>=10)
//        {
//            s1[i]=char((s1[i]-'0')%10+'0');
//            if(i) s1[i-1]++;
//            else s1='1'+s1;
//        }
//    }
//    return s1;
//}
////字符串去除后导0函数，前导0可以先反转取后导
//
//int main()
//{
//    int N;
//    while(scanf("%d", &N) != EOF)
//    {
//        if(N == 0)
//        {
//            printf("%d\n", N);
//            continue;
//        }
//        string ss,sss,ssss;
//        ss.append("0");
//        sss.append("1");
//        for(int i = 0; i < N; i++)
//        {
//            ssss = sum(ss, sss);
//            ss = sss;
//            sss = ssss;
//        }
//        cout << ssss << endl;
//    }
//}

//inline long long extend_gcd(long long a,long long b,long long &x,long long &y)
//{
//    if(a==0&&b==0)
//        return -1ll;
//    if(b==0)
//    {
//        x=1ll;
//        y=0ll;
//        return a;
//    }
//    long long d=extend_gcd(b,a%b,y,x);
//    y-=a/b*x;
//    return d;
//}
//inline long long mod_reverse(long long a,long long n)
//{
//    long long x,y,d=extend_gcd(a,n,x,y);
//    if(d==1)
//        return (x%n+n)%n;
//    return -1ll;
//}

// A
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#define N 100002
//#define BASE 28
//#define MOD 9973
//#define DIM 256
//int n;
//char str[N]; //int sum[N][DIM];
//int sum[N];
//void read()
//{
//    scanf("%s", str);
//}
//int exponent(int a, int x)
//{
//    int res = 1;
//    if( a<0 ) a+=MOD;
//    int tmp = a;
//    while(x)
//    {
//        if(x&1) res = (res*tmp)%MOD;
//        tmp = (tmp*a)%MOD;
//        x >>= 1;
//    }
//    return res;
//}
//int res = 1;
//void solve()
//{
//    int len = strlen(str);
//    for(int i=1; i<=len; ++i)
//    {
//        sum[i] = (str[i-1]+MOD-BASE)*sum[i-1]%MOD;
//    }
//    int a, b;
//    for(int i=0; i<n; ++i)
//    {
//        scanf("%d%d", &a, &b);
//        if(a<1||a>len||b<1||b>len) goto OUTPUT;
//        for(int j=0; j<MOD; ++j)
//        {
//            if( sum[a-1]*j%MOD == sum[b] )
//            {
//                res = j;
//                break;
//            }
//        }
//OUTPUT:
//        printf("%d\n", res);
//    }
//}
//int main()
//{
//    sum[0] = 1;
//    while(scanf("%d", &n)==1)
//    {
//        read();
//        solve();
//    }
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 400010<<2
const int mod = 9973;
int ans;

using namespace std;
int array[MAX];
char str[100005];
int cur = 0;
void init(int left,int right,int pa)
{
    if(left==right)
    {
        array[pa] = (int )(str[cur++] - 28 + mod) % mod;
        return ;
    }
    int mid=(left+right)>>1;
    int child=pa<<1;
    init(left,mid,child);
    init(mid+1,right,child|1);
    array[pa]=(array[child] * array[child|1])%mod;
}
void update(int left,int right,int pa,int start,int end)
{
    if(start<=left&&right<=end)
    {
        ans = array[pa] * ans % mod;
        return ;
    }
    int mid=(left+right)>>1;
    int child=pa<<1;
    if(start<=mid)
        update(left,mid,child,start,end);
    if(mid<end)
        update(mid+1,right,child|1,start,end);
    array[pa]=(array[child]*array[child|1]) %mod;
    return ;
}
int main()
{
    int N;
    while(~scanf("%d", &N))
    {
        scanf("%s", str);
        cur = 0;
        int len = strlen(str);
        init(1, len, 1);
        while(N --)
        {
            int a,b;
            scanf("%d%d",&a,&b);//访问的区间范围
            if(a < 1 || a > len || b < 1 || b > len)
            {
                printf("%d\n", ans);
                continue;
            }
            ans=1;
            update(1,len,1,a,b);
            printf("%d\n",ans);
        }
    }
    return 0;
}
