//求1997！=？
//1997！的值超过计算机所能表示的整数范围，请考虑其他技巧，假设 1997！之值不超过10000位用一个含有10000个元素的整型数组num表示其结果，每个元素存放一位，num[0]存入个位数，num[]存入十 位数，依次类推……8！=40320，当前最高位len=4，求9！与各位依次相乘rum保存当前的进位数字。（0<=rem<9）.
//1)rem置初始值0.
//2）i=0:rem=rem+num[0]*9=0+0=0。num[0]=rem%10=0，rem=rem/10=0。
//3）i=1:rem=rem+num[1]*9=0+18=18。num[1]=rem%10=8，rem=rem/10=1。
//4）i=2:rem=rem+num[2]*9=1+27=28。num[2]=rem%10=8，rem=rem/10=2。
//5）i=3:rem=rem+num[3]*9=2+0=2。num[3]=rem%10=2，rem=rem/10=0。
//6）i=4:rem=rem+num[4]*9=0+36=36。num[4]=rem%10=6，rem=rem/10=3。
//7）rem=3，说明有进位，数组最高位增加1，len=len+1=5，num[5]=rem%10=3，rem=rem/10=0，结束。
//num各位结果为：3、6、2、8、8、0。即9！=362880
//#include<stdio.h>
//int sum[10000];
//int main()
//{
//    //freopen("test.out","w",stdout);
//    int i1,i2,n=1997;
//    for(i1=0; i1<10000; i1++)
//        sum[i1]=0;
//    sum[0]=1;
//    for(i1=1; i1<=n; i1++)
//    {
//        int rem=0;//进位
//        for(i2=0; i2<10000; i2++)
//        {
//            int s=sum[i2]*i1+rem;
//            sum[i2]=s%10;
//            rem=s/10;
//        }
//    }
//    for(i2=10000; i2>=0; i2--)
//        if(sum[i2])
//            break;
//    for(i1=i2; i1>=0; i1--)
//        printf("%d",sum[i1]);
//    //printf("\n");
//    return 0;
//}

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("test0.in","w",stdout);
    const int n=10000;
    int num[n];
    int j,tmp;
    int m=1;
    for(j=1; j<n; ++j)
        num[j]=0;
    num[0]=1;
    tmp=0;
    for(int i=1; i<=1997; ++i)
    {
        j=0;
        do
        {
            num[j]=num[j]*i+tmp;
            tmp=0;
            if(num[j]>=10)
            {
                tmp=(int)num[j]/10;
                num[j]=num[j]%10;
            }
            ++j;
            if(j==m&&tmp)
                ++m;
        }
        while(j!=m);
    }
    for(j=m-1; j>=0; --j)
        cout<<num[j];
    //cin>>j;
    return 0;
}

