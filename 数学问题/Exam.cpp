//题目意思:
//定义f(x) = 满足(a * b)|x的有序对(a,b)的个数。
//然后输入一个n，求f(1) + f(2) + ... + f(n)
//#include <math.h>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//__int64 mypow(__int64  x,__int64 a)//x的a次方根
//{
//    __int64 m=pow(x,1.0/a),i,j,sum;//先用系统函数把大概范围求出来！
//    while(1)
//    {
//        sum=1;
//        for(j=0; j<a; j++)
//            sum*=m;
//        if(sum<=x) m++;
//        else break;
//    }
//    while(1)
//    {
//        sum=1;
//        for(j=0; j<a; j++)
//            sum*=m;
//        if(sum>x)//这没有=号
//            m--;
//        else return m;
//    }
//}
//int main()
//{
//    __int64 n,i,j,k,sum,iall,jall,ni;
//    int tcase=1;
//    while(scanf("%I64d",&n)!=EOF)
//    {
//        iall=mypow(n,3);
//        jall=mypow(n,2);
//        sum=iall;//iii这种形式的刚好是iall个
//        for(i=1; i<=iall; i++)
//        {
//            ni=n/i;//加快速度
//            k=mypow(ni,2);
//            sum+=(ni/i+k-2*i)*3;//iij的个数为ni/i-i;ijj这种形式的个数为k-i个
//            for(j=i+1; j<=k; j++) //可以推出j小于根号下（n/i）这样速度更快
//                sum+=(ni/j-j)*6;
//        }
//        printf("Case %d: %I64d\n",tcase++,sum);
//    }
//    return 0;
//}

//把原题的条件(a * b)|x 转化为 a * b * y = x
//  然后就很好计算了，就是，输入一个n，计算有多少有序对(a, b ,y)满足a*b*y<=n
//  不妨设a<=b<=y
//  则，a<=n^(1/3) , b<=sqrt(n/a)
//  那么
//        对于三个数字都相同的情况，只计算一次: i i i
//        对于三个数字中有两个相同的情况，计算3次: i i j, i j i, j i i
//        对于均不相同的情况，计算6次: a b y ,a y b ,b a y ,b y a, y a b ,y b a
//#include <math.h>
//#include <stdio.h>
//using namespace std;
//long long n,ans;
//long long sqrt2(long long nn)// long long 开平方
//{
//    long long k;
//    k=pow(nn*1.0,0.5);
//    while(k*k<=nn) k++;
//    while(k*k>nn) k--;
//    return k;
//}
//long long sqrt3(long long nn)    // long long 开立方
//{
//    long long k;
//    k=pow(nn*1.0,1.0/3.0);
//    while(k*k*k<=nn) k++;
//    while(k*k*k>nn) k--;
//    return k;
//}
//int main()
//{
//    int i,j,t=0;
//    long long a,b,c,s,sq2,sq3;
//    while(~scanf("%I64d",&n))
//    {
//        t++;
//        sq2=sqrt2(n);       // 假如直接用sqrt或pow开平方、立方会WA  可能是浮点误差吧
//        sq3=sqrt3(n);
//        ans=sq3;                    // 第一种情况
//        for(i=1; i<=sq2; i++)       // 第二种情况
//        {
//            s=(n/((long long)(i)*i));
//            if(s<1) break;
//            if(i<=sq3) ans+=(s*3-3);
//            else ans+=s*3;
//        }
//        for(i=1; i<=sq3; i++)       // 第三种情况
//            for(j=i+1; j<=sq2; j++)
//            {
//                s=(n/((long long)(i)*j)-j);
//                if(s<=0) break ;
//                ans+=s*6;
//            }
//        printf("Case %d: %I64d\n",t,ans);
//    }
//    return 0;
//}

//a*b*y<=n的(a,b,y)的数目
//假设a<=b<=y,则可以写出他们的取值范围a<=pow(n,1.0/3.0);b<=sqrt(n/a);y>=b;
//    因为是有序对，所以a=b=y是sum+=1；
//                                    a=b!=y||a!=b=y时，sum+=3；
//                                    a!=b!=y时，sum+=6；(想一想，为什么呢？)
//    因为枚举必然超时，所以选择使用算法解决：a=b=y的数目是pow(n,1.0/3.0)
//                                    a=b!=y||a!=b=y的数目是n/(a*a)-a+b-a
//                                    a!=b!=y的数目是n/(a*b)-b
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    __int64 A,B,C,sum,n,i,j,t=1;           //记住只能用__int64，使用unsigned long long会严重超时
//    while(~scanf("%I64d",&n))          //使用%I64d输入
//    {
//        A=pow((double)n,1.0/3.0);
//        while(A*A*A<n) A++;
//        if(A*A*A>n) A--;
//        sum=A;
//
//        for(i=1; i<=A; i++)
//        {
//            B=n/i;
//            C=sqrt(B);
//            while(C*C<B) C++;
//            if(C*C>B) C--;
//
//            sum+=(B/i-i+C-i)*3;
//            for(j=i+1; j<=C; j++)
//                sum+=(B/j-j)*6;
//        }
//        printf("Case %I64d: %I64d\n",t++,sum);   //使用%I64d输出
//    }
//
//    return 0;
//}

//思考:问f(1)+f(2)+..+f(n)，其中f（x）是x的约数的个数
//转换为a*b<=n的解的个数来解决。（PS:枚举约数，然后分别计算，答案是n/1+n/2+..+n/n
//然而不同的理解方式显然有着很大的区别，如果按照第一种思维方式去理解
//这道题是不是可以转化为a*b*c<=n的解的个数。。。？
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    __int64 i,j,n,zs;
    int cas=0;
    while (scanf("%I64d",&n)!=EOF)
    {
        cas++;
        zs=0;
        for (i=1; i*i*i<=n; i++)
            for (j=i; i*j*j<=n; j++)
            {
                __int64 k1,k2;
                k1=j;
                k2=n/(i*j);
                if (i!=j)
                {
                    zs=zs+6*(k2-k1+1);
                    zs-=3;
                }
                else
                {
                    zs=zs+3*(k2-k1+1);
                    zs-=2;
                }
            }
        printf("Case %d: %I64d\n",cas,zs);
    }
    return 0;
}
