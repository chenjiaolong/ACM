//大整数的加法
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<stdbool.h>
//#include<cstring>
//#define MAX_LEN 200
//int an1[MAX_LEN+10];
//int an2[MAX_LEN+10];
//char szLine1[MAX_LEN+10];
//char szLine2[MAX_LEN+10];
//using namespace std;
//int main()
//{
//    scanf("%s",szLine1);
//    scanf("%s",szLine2);
//
//    //库函数memset将地址an1开始的sizeof(an1)字节内容置成0
//    //sizeof（an1）的值就是an1的长度
//    //memset函数在string.h中声明
//    memset(an1,0,sizeof(an1));
//    memset(an2,0,sizeof(an2));
//
//    //下面将szLine1中存储的字符串形成的整数转换到an1中去
//    //an1[0]对应于个位
//    int nLen1=strlen(szLine1);
//    int j=0;
//    for(int i=nLen1-1; i>=0; i--)
//        an1[j++]=szLine1[i]-'0';
//
//    int nLen2=strlen(szLine2);
//    j=0;
//    for(int i=nLen2-1; i>=0; i--)
//        an2[j++]=szLine2[i]-'0';
//
//    for(int i=0; i<MAX_LEN; i++)
//    {
//        an1[i]+=an2[i];//逐行相加
//        if(an1[i]>=10)//看是否要进位
//        {
//            an1[i]-=10;
//            an1[i+1]++;//进位
//        }
//    }
//    bool bStartOutput=false;//此变量用于跳过多余的0
//    for(int i=MAX_LEN;i>=0;i--)
//    {
//        if(bStartOutput)
//            printf("%d",an1[i]);//如果多余的0已经都跳过，则输出
//        else if(an1[i])
//        {
//            printf("%d",an1[i]);
//            bStartOutput=true;//碰到第一个非0的值，就说明多余的0已经跳过
//        }
//    }
//    return 0;
//}

//大整数的乘法
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<stdbool.h>
//#include<cstring>
//#define MAX_LEN 200
//unsigned an1[MAX_LEN+10];
//unsigned an2[MAX_LEN+10];
//unsigned aResult[MAX_LEN*2+10];
//char szLine1[MAX_LEN+10];
//char szLine2[MAX_LEN+10];
//using namespace std;
//int main()
//{
//    gets(szLine1);//get函数读取一行
//    gets(szLine2);
//
//    //库函数memset将地址an1开始的sizeof(an1)字节内容置成0
//    //sizeof（an1）的值就是an1的长度
//    //memset函数在string.h中声明
//    memset(an1,0,sizeof(an1));
//    memset(an2,0,sizeof(an2));
//
//    //下面将szLine1中存储的字符串形成的整数转换到an1中去
//    //an1[0]对应于个位
//    int nLen1=strlen(szLine1);
//    int j=0;
//    for(int i=nLen1-1; i>=0; i--)
//        an1[j++]=szLine1[i]-'0';
//
//    int nLen2=strlen(szLine2);
//    j=0;
//    for(int i=nLen2-1; i>=0; i--)
//        an2[j++]=szLine2[i]-'0';
//
//    for(int i=0; i<nLen2; i++)//每一轮都用an1的一位，去an2各位相乘
//                              //从an1的各位开始
//        for(j=0;j<nLen1;j++)//用选定的an1的那一位，去乘an2的各位
//        aResult[i+j]+=an2[i]*an1[j];//两数第i，j位相乘，累加到结果的第i+j位
//    //下面的循环统一处理进位问题
//    for(int i=0;i<MAX_LEN*2;i++)
//        if(aResult[i]>=10)
//    {
//        aResult[i+1]+=aResult[i]/10;
//        aResult[i]%=10;
//    }
//    //下面输出结果
//    bool bStartOutput=false;//此变量用于跳过多余的0
//    for(int i=MAX_LEN*2;i>=0;i--)
//    {
//        if(bStartOutput)
//            printf("%d",aResult[i]);//如果多余的0已经都跳过，则输出
//        else if(aResult[i])
//        {
//            printf("%d",aResult[i]);
//            bStartOutput=true;//碰到第一个非0的值，就说明多余的0已经跳过
//        }
//    }
//    if(!bStartOutput)
//        printf("0");
//    return 0;
//}

//大整数的除法
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<cstring>
#define MAX_LEN 200
int an1[MAX_LEN+10];//被除数，an1[0]对应于个位
int an2[MAX_LEN+10];//除数，an2[0]对应于个位
int aResult[MAX_LEN+10];//存放商，aResult[0]对应于个位
char szLine1[MAX_LEN+10];
char szLine2[MAX_LEN+10];
using namespace std;
/*Substrcat函数：长度为nLen1的大整数p1减去长度为nLen2的大整数p2
减的结果存放在p1里，返回值代表结果的长度
如不够减返回-1，正好减完返回0
p1[0]、p2[0]是个位*/
int Substrcat(int *p1,int *p2,int nLen1,int nLen2)
{
    if(nLen1<nLen2)
        return -1;
    //下面判断p1是否比p2大，如果不是，返回-1
    bool bLarger=false;
    if(nLen1==nLen2)
    {
        for(int i=nLen1-1; i>=0; i--)
        {
            if(p1[i]>p2[i])
                bLarger=true;
            else if(p1[i]<p2[i])
                if(!bLarger)
                    return -1;
        }
    }
    for(int i=0; i<nLen1; i++) //做减法
    {
        p1[i]-=p2[i];//要求调用本函数时给的参数能确保当i>=nLen2时，p2[i]=0
        if(p1[i]<0)
        {
            p1[i]+=10;
            p1[i+1]--;
        }
    }
    for(int i=nLen1-1; i>=0; i--)
        if(p1[i])
            return i+1;
    return 0;
}
int main()
{
    int n;
    char szBlank[20];
    scanf("%d",&n);
    for(int t=0; t<n; t++)
    {
        scanf("%s",szLine1);//get函数读取一行
        scanf("%s",szLine2);

        //库函数memset将地址an1开始的sizeof(an1)字节内容置成0
        //sizeof（an1）的值就是an1的长度
        //memset函数在string.h中声明
        memset(an1,0,sizeof(an1));
        memset(an2,0,sizeof(an2));

        //下面将szLine1中存储的字符串形成的整数转换到an1中去
        //an1[0]对应于个位
        int nLen1=strlen(szLine1);
        int j=0;
        for(int i=nLen1-1; i>=0; i--)
            an1[j++]=szLine1[i]-'0';

        int nLen2=strlen(szLine2);
        j=0;
        for(int i=nLen2-1; i>=0; i--)
            an2[j++]=szLine2[i]-'0';
        if(nLen1<nLen2)
        {
            printf("0\n");
            continue;
        }
        nLen1=Substrcat(an1,an2,nLen1,nLen2);
        if(nLen1<0)
        {
            printf("0\n");
            continue;
        }
        else if(nLen1==0)
        {
            printf("1\n");
            continue;
        }
        aResult[0]++;//减掉一次了，商加1
        //减掉一次后的结果长度是nLen1；
        int nTimes=nLen1-nLen2;
        if(nTimes<0)//减掉一次后就不能再减了
            goto OutputResult;
        else if(nTimes>0)
            //将an2乘以10的某次幂，使得结果长度和an1相同
        {
            for(int i=nLen1-1; i>=0; i--)
            {
                if(i>=nTimes)
                    an2[i]=an2[i-nTimes];
                else
                    an2[i]=0;
            }
        }
        nLen2=nLen1;
        for(int i=0; i<=nTimes; i++)
        {
            int nTmp;
            //一直减到不够减为止
            //先减去若干个an2*（10的nTimes次方）
            //不够减了，再减去若干个an2*（10的nTimes-1次方），……
            while((nTmp=Substrcat(an1,an2+i,nLen1,nLen2-i))>=0)
            {
                nLen1=nTmp;
                aResult[nTimes-i]++;//每成功减一次，则将商的相应位加1
            }
        }
OutputResult:
        //下面的循环统一处理进
        for(int i=0; i<MAX_LEN; i++)
            if(aResult[i]>=10)
            {
                aResult[i+1]+=aResult[i]/10;
                aResult[i]%=10;
            }
        //下面输出结果
        bool bStartOutput=false;//此变量用于跳过多余的0
        for(int i=MAX_LEN; i>=0; i--)
        {
            if(bStartOutput)
                printf("%d",aResult[i]);//如果多余的0已经都跳过，则输出
            else if(aResult[i])
            {
                printf("%d",aResult[i]);
                bStartOutput=true;//碰到第一个非0的值，就说明多余的0已经跳过
            }
        }
        if(!bStartOutput)
            printf("0");
        printf("\n");
    }
    return 0;
}
