//关键是如何判断2个数相关:
//对一个数如果把其中的数字由大到小排列.如1345 排成5431 4135 排成5431
//如果排列后的两个数相等,那么两个数相关.
//所以对本题:
//(1)把输入的数从小到大排列
//(2)把每个数中的数字按从大到小排列.如223 变为322
//(3)两两比较是否相关,也就是比较是否相等.
#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a > b;
}
int Check(int n)
{
    int digit[10];
    int cur = 0;
    while(n)
    {
        digit[cur++] = n % 10;
        n /= 10;
    }
    //for(int i = 0; i < cur; i++)
        //printf("%d%c",digit[i],i == cur - 1?'\n' : ' ');
    sort(digit,digit + cur,cmp);
    int num = 0;
    for(int i = 0; i < cur; i++)
        num = 10 * num + digit[i];
    //printf("$$$$$ %d\n",num);
    return num;
}
int main()
{
    int N;
    while(scanf("%d",&N) == 1&& N)
    {
        int P[1005];
        for(int i = 0; i < N; i++)
            scanf("%d",&P[i]);
        sort(P,P + N);
        int num[1005];
        for(int i =0; i < N; i++)
            num[i] = Check(P[i]);
        bool DependencyNumber[1005] = {0};
        for(int i = 0; i < N; i++)
            if(!DependencyNumber[i])
            {
                for(int j = i + 1; j < N; j++)
                    if(num[i] == num[j])
                        DependencyNumber[i] = DependencyNumber[j] = true;
            }
        bool flag = true;
        for(int i = 0; i < N; i++)
            if(!DependencyNumber[i])
            {
                if(flag)
                    printf("%d",P[i]);
                else
                    printf(" %d",P[i]);
                flag = false;
            }
            if(flag)
                printf("None");
            printf("\n");
    }
    return 0;
}
