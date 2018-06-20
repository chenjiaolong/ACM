//#include<bits/stdc++.h>
//#include<math.h>
//using namespace std;
//int main()
//{
//    int n,num;
//    while(~scanf("%d",&n))
//    {
//        bool flag = true;
//        for(int i = 0; i < n; i++)
//        {
//            scanf("%d",&num);
//            int a = (int)(sqrt)(num);
//            if(a * a != num)
//                flag = false;
//        }
//        if(flag)
//            puts("Yes");
//        else
//            puts("No");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//char W[5000001],P[5000001];
//int top=-1;
//int next[5000001];
//int len_W,len_P;
//struct stack
//{
//    char ch;
//    int J;
//} stack[5000001];
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_W)
//    {
//        if(j==-1||W[i]==W[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//void KMP()
//{
//    int i=0,j=0;
//    top=-1;
//    while(i<len_P)
//    {
//        if(j==-1||P[i]==W[j])
//        {
//            top++;
//            stack[top].J=j+1;
//            stack[top].ch=P[i];
//            i++;
//            j++;
//        }
//        else
//            j=next[j];
//        if(j==len_W)
//        {
//            top=top-len_W;
//            j=stack[top].J;
//        }
//
//    }
//}
//int main()
//{
//    while(~scanf("%s%s",W,P))
//    {
//        len_W=strlen(W);
//        len_P=strlen(P);
//        if(len_W>len_P)
//        {
//            printf("%s\n",P);
//            continue;
//        }
//        get_next();
//        KMP();
//        for(int k=0; k<=top; k++)
//            printf("%c",stack[k].ch);
//        printf("\n");
//    }
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
    int array[maxn],digits[maxn];
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i ++)
            scanf("%d",&array[i]);
        int mod = 1;
        long long cnt = 0;
        for(int i = 1; i <= 9; i ++)
        {
            mod *= 10;
            for(int j = 0; j < n; j ++)
                digits[j] = array[j] % mod;
            sort(digits, digits + n);
            int k = 0;
            for(int j = n -1; j >= 0; j --)
            {
                for(; k < n; k++)
                    if(digits[j] + digits[k] >= mod)
                        break;
                if(k <= j)
                    cnt --;
                cnt += (n - k);
            }
        }
        printf("%lld\n", cnt / 2);
    }
    return 0;
}
