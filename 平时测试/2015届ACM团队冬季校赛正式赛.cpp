//易无解的IP
//#include<stdio.h>
//int main()
//{
//    //freopen("test0.in","r",stdin);
//    //freopen("check.out","w",stdout);
//    int a,b,c,d;
//    int num;
//    while(~scanf("%d",&num))
//    {
//        while(num--)
//        {
//            scanf("%d.%d.%d.%d",&a,&b,&c,&d);
//            if((a>= 0 && a <= 255) && (b >= 0 && b <= 255) && (c >= 0 && c <= 255) && (d >= 0 && d <= 255))
//            {
//                if(a >= 1 && a <= 126)
//                    printf("It's belong to class A!\n");
//                else if(a >= 128 && a <= 191)
//                    printf("It's belong to class B!\n");
//                else if(a >= 192 && a <= 223)
//                    printf("It's belong to class C!\n");
//                else
//                    printf("It's not belong to class A, B, and C!\n");
//            }
//            else
//                printf("It's not a IP address!\n");
//        }
//    }
//    return 0;
//}

//哪儿来的快递
//#include<stdio.h>
//#include<stdlib.h>
//struct node
//{
//    char a[20];
//    int b;
//    double k;
//    char s;
//}array[105];
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        char buffer[10];
//        for(int i = 0; i < n ; i++)
//            scanf("%s%d%lf%*c%c",array[i].a,&array[i].b,&array[i].k,&array[i].s);
//        gets(buffer);
//        char e;
//        scanf("%c",&e);
//        for(int i = 0; i < n; i++)
//            if(array[i].s == e)
//            printf("%s %d %.2f %c\n",array[i].a,array[i].b,array[i].k,array[i].s);
//    }
//    return 0;
//}

//独一无二？
//#include<bits/stdc++.h>
//int main()
//{
//    int n,m;
//    int a[100005],b[100005],f[100005];
//    while(~scanf("%d%d",&n,&m))
//    {
//        int cnt[100005] = {0};
//        for(int i = 1; i <= n; i++)
//        {
//            scanf("%d",&f[i]);
//            cnt[f[i]] ++;
//            a[f[i]] = i;
//        }
//        int flag = 1;
//        for(int i = 1; i <= m; i++)
//        {
//            scanf("%d",&b[i]);
//            if(cnt[b[i]] == 0)
//                flag = 0;
//            else if(cnt[b[i]] > 1&&flag != 0)
//                flag = 2;
//        }
//        if(flag == 0)
//            printf("Impossible\n");
//        else if(flag == 2)
//            printf("Ambiguity\n");
//        else
//        {
//            printf("Possible\n");
//            for(int i = 1; i <= m; i++)
//                printf("%d%c",a[b[i]],i == m  ? '\n': ' ');
//        }
//    }
//    return 0;
//}

//这不是a+b
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int a,b;
//    char ch;
//    while(~scanf("%d %c %d",&a,&ch,&b))
//    {
//        if(ch == '+')
//        {
//            printf("%d\n",a + b);
//            if(b >= 0)
//                printf("%d+%d=%d\n",a,b,a + b);
//            else
//                printf("%d-%d=%d\n",a,-b,a + b);
//        }
//        else
//        {
//            printf("%d\n",a - b);
//            if(b >= 0)
//                printf("%d-%d=%d\n",a,b,a - b);
//            else
//                printf("%d+%d=%d\n",a,-b,a - b);
//        }
//    }
//    return 0;
//}

//角谷猜想？？？No,No,No
//#include<stdio.h>
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        int array[105],cur = 0;
//        int flag = 0;
//        for(int i = 1; i <= 100; i++)
//        {
//            if(n == 1)
//            {
//                array[cur++] = n;
//                flag = 1;
//                break;
//            }
//            array[cur++] = n;
//            if(n&1)
//                n = n / 2;
//            else
//                n = 3 * n + 1;
//
//        }
//        if(flag)
//            for(int i = 0; i < cur; i++)
//                printf("%d%c",array[i],i == cur - 1 ? '\n' :' ');
//        else
//            printf("Impossible\n");
//    }
//    return 0;
//}

//松浩的猴子
//#include<bits/stdc++.h>
//using namespace std;
//int cmp(int a,int b)
//{
//    return a > b;
//}
//int main()
//{
//    int N,array[105];
//    while(~scanf("%d",&N))
//    {
//        for(int i = 0; i < N; i++)
//            scanf("%d",&array[i]);
//        sort(array,array + N,cmp);
//        int m = unique(array,array + N) - array;
//        for(int i = 0 ; i < m; i ++)
//            printf("%d%c",array[i],i == m-1?'\n':' ');
//        printf("%d\n",N-m);
//    }
//    return 0;
//}

//购买材料
//#include<stdio.h>
//#include<math.h>
//#define PI 3.14
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        while(n--)
//        {
//            int b,N;
//            scanf("%d%d",&b,&N);
//            int sum = 0;
//            for(int i = 0 ; i < N; i++)
//            {
//                double R;
//                scanf("%lf",&R);
//                double V = PI * R * R * R * 4.0/3 * powl(10,b + 1);
//                //printf("SSSS %lf\n",V);
//                int VV = (int )V;
//                if(VV % 10 >= 5)
//                   sum += VV / 10 + 1;
//                else
//                    sum += VV / 10;
//            }
//            printf("%d\n",sum);
//        }
//    }
//    return 0;
//}

//啊飞的烦恼
//#include<stdio.h>
//#include<math.h>
//const int maxn = 10005;
//int array[maxn];
//void IsPrime()
//{
//    for(int i = 0; i < maxn; i++)
//        if(i & 1)
//            array[i] = 1;
//        else
//            array[i] = 0;
//    array[1] = 0,array[2] = 1;
//    for(int i = 2; i <= (int) sqrt(maxn); i++)
//        if(array[i])
//            for(int j = i + i; j <= maxn; j += i)
//                array[j] = 0;
////    for(int i = 2; i <=100 ; i++)
////        if(array[i])
////            printf("%d ",i);
//}
//int main()
//{
//    IsPrime();
//    int M;
//    while(~scanf("%d",&M))
//    {
//        for(int A = M / 2,B = M / 2; A >= 0,B <= M; A--,B++)
//            if(array[A]&&array[B])
//            {
//                printf("%d %d\n",A,B);
//                break;
//            }
//    }
//    return 0;
//}

//我们都爱美
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char ch;
//    char buffer[10];
//    while(~scanf("%c",&ch))
//    {
//        gets(buffer);
//        if(ch == 'A'||ch == 'H'||ch == 'I'||ch == 'M'||ch == 'O'||ch == 'T'||ch == 'U'||ch == 'V'||ch == 'W'||ch == 'X'||ch == 'Y')
//            printf("Yes\n");
//        else
//            printf("No\n");
//    }
//    return 0;
//}

//小心可过的水题
//#include<stdio.h>
//int main()
//{
//    int A, B;
//    while(~scanf("%d%d",&A,&B))
//    {
//        if((A & 1) == 0 && (B & 1) == 0)
//            printf("%lld\n",(long long)A + B);
//        else
//            printf("-1\n");
//    }
//    return 0;
//}

//姐姐的麻烦
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("sample.in","r",stdin);
    //freopen("sample.out","w",stdout);
    char s[40];
    char str[1200];
    int i,j;
    int cnt;
    while(gets(s) != NULL)
    {
        if(s[0] == '#')
            break;
        gets(str);
        int vis[130] = {0};
        for(i = 0; i < strlen(s); i++)
        {
            cnt = 0;
            int cur = (int)s[i];
            if(!vis[cur])
            {
                for(j = 0; j < strlen(str); j++)
                    if(s[i] == str[j])
                        cnt++;
                printf("%c %d\n",s[i],cnt);
                vis[cur] = 1;
            }
        }
        printf("\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

