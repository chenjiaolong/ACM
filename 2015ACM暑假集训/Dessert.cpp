//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int Max = 16;
//int n,num;//num记录可能得情况数。
//char symbol[Max];
//void print()
//{
//    int i;
//    for(i = 1; i < n; i ++)
//        printf("%d %c",i,symbol[i]);
//    printf("%d\n", i);
//}
//void dfs(int sum, int depth, int pre)//dfs尽量少用全局变量，如定义成dfs(int depth)。
//{
//
//    if(depth == n)//深搜出口。
//    {
//        if(sum == 0)
//        {
//            num ++;
//            if(num <= 20)
//                print();
//        }
//    }
//    else
//    {
//        int next;
//        symbol[depth] = '+';//若第depth位符号为'+'。
//        next = depth + 1;
//        dfs(sum + next, depth + 1, next);
//        symbol[depth] = '-';//若第depth位符号为'-'。
//        next = depth + 1;
//        dfs(sum - next, depth + 1, next);
//        symbol[depth] = '.';//若第depth位符号为'.'。
//        if(depth < 9)
//            next = pre * 10 + depth + 1;
//        else
//            next = pre * 100 + depth + 1;
//        int i = depth - 1;
//        while(symbol[i] == '.' && i >= 0)
//            i --;
//        if(symbol[i] == '+')
//            dfs(sum + next - pre, depth + 1, next);
//        else if(symbol[i] == '-')
//            dfs(sum - next + pre, depth + 1, next);
//    }
//}
//
//int main()
//{
//    cin >> n;
//    symbol[0] = '+';//将第0个符号看成'+',构造成 0 + 1 ? 2 ? 3 …简化后面较烦的初始化。
//    num = 0;
//    dfs(1, 1, 1);
//    cout << num << endl;
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//
//int N, sck[55], cnt;
//
//void dfs(int p, int pre, int sum)
//{
//    if(abs(pre)>1234567891)return ;
//    if(p==N+1)
//    {
//        if(sum == 0)
//        {
//            cnt++;
//            if(cnt>20)return ;
//            printf("1");
//            for(int i=2; i<=2*N; i++)
//                if(i&1)printf(" %d", sck[i]);
//                else printf(" %c", sck[i]);
//        }
//        return ;
//    }
//    sck[2*p-2]='+';
//    sck[2*p-1]=p;
//    dfs(p+1, p, sum+p);
//    sck[2*p-2]='-';
//    dfs(p+1, -p, sum-p);
//    sck[2*p-2]='.';
//    int a, b, x=pre<0?-p:p;
//
//    if(p<=9)a=pre*10+x, b=sum-pre+a;
//    else a=pre*100+x, b=sum-pre+a;
//    dfs(p+1, a, b);
//}
//
//int main()
//{
//    cin >> N;
//    sck[2*N]='\n';
//    sck[1]=1;
//    dfs(2, 1, 1);
//    printf("%d\n", cnt);
//    return 0;
//}

//#include <iostream>
//#define F(i,a,b) for (int i=a;i<=b;i++)
//using namespace std;
//char chr[4]= {'+', '-', '.'} ;
//int a[16], total, sum, now, sign, n;
//int calc(int a, int b, int c)
//{
//    switch(b)
//    {
//    case 0:
//        return a+c;
//    case 1:
//        return a-c;
//    }
//}
//void dfs(int x )
//{
//    if ( x == n)
//    {
//        if (x<=9)
//            now = now*10+x;
//        else
//            now = now *100 +x;
//        if ( calc(sum, sign, now)==0 )
//        {
//            total++;
//            if (total<=20)
//            {
//                F(i,1,n-1)
//                cout << i << " " << chr[ a[i] ] << " ";
//                cout << n;
//                cout << endl;
//            }
//        }
//    }
//    else
//    {
//        int tsum = sum, tsign = sign, tnow=now;
//        //+
//        if (x<=9)
//            now = now*10 +x;
//        else
//            now = now *100 + x;
//        sum =calc(sum, sign, now);
//        now = 0;
//        sign = 0, a[x] = 0;
//        dfs(x+1);
//        //-
//        sign = 1, a[x] = 1;
//        now = 0;
//        dfs(x+1);
//        // .
//        now = tnow;
//        sum = tsum, sign = tsign;
//        a[x] = 2;
//        if (x<=9)
//            now = now*10+x;
//        else
//            now = now *100 +x;
//        dfs(x+1);
//        now = tnow;
//    }
//}
//int main()
//{
//    cin >> n;
//    now = 0, sum = 0, sign = 0;
//    dfs(1);
//    cout << total << endl;
//    return 0;
//}
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int N,cnt;
char nap[20];
void dfs(int ret,int dep,int p)
{
    if(dep==N+1)
    {
        if(!ret)
        {
            cnt++;
            if(cnt>20) return;
            for(int i=1; i<N; i++)
                printf("%d %c ",i,nap[i]);
            printf("%d\n",N);
        }
        return;
    }
    nap[dep-1]='+';
    dfs(ret+dep,dep+1,dep);
    nap[dep-1]='-';
    dfs(ret-dep,dep+1,-dep);

    nap[dep-1]='.';
    int t=p>0?dep:-dep;
    if(dep>9)
        dfs(ret+p*99+t,dep+1,p*100+t);
    else
        dfs(ret+p*9+t,dep+1,p*10+t);
}
int main()
{
    //freopen("test.txt","r",stdin);
    scanf("%d",&N);
    dfs(1,2,1);
    printf("%d\n",cnt);
    return 0;
}


