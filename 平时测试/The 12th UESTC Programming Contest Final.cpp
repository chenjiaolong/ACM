// cdoj 805 Algorithm Homework
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1e5 + 5;
int odd[maxn];
int even[maxn];
int main()
{
    int N;
    while(~scanf("%d", &N))
    {
        int M = N;
        if(M & 1)
            M -= 1;
        int cur1 = 0;
        int cur2 = 0;
        for(int i = 0; i < M; i += 2)
        {
            scanf("%d", &odd[cur1++]);
            scanf("%d", &even[cur2++]);
        }
        if(N & 1)
            scanf("%d", &odd[cur1++]);
//        for(int i = 0; i < cur1; i++)
//            printf("%d ", odd[i]);
//        puts("");
//        for(int i = 0; i < cur2; i++)
//            printf("%d ", even[i]);
        sort(odd, odd + cur1);
        sort(even, even + cur2);
        bool flag = true;
        for(int i = 0; i < cur2; i++)
            if(odd[i] > even[i])
            {
                flag = false;
                break;
            }
        if(flag)
            puts("Yes");
        else
            puts("No");
    }
}
