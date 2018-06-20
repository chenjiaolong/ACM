//汽水瓶问题
//方法 1 ： 正面思考
//#include<stdio.h>
//int main()
//{
//    int n=0,temp=0,m=0;
//    while(scanf("%d",&n)!=EOF)
//    {
//        if(n==0)break;
//        temp=0,m=0;
//        while(n>2)
//        {
//            temp=n/3;
//            n=temp+n%3;
//            m+=temp;
//        }
//        if(n%3==2)
//            m+=1;
//        printf("%d\n",m);
//    }
//    return 0;
//}
//方法2 ：反面思考 角谷猜想的应用
#include<stdio.h>
int main()
{
    int n ;
    while(scanf("%d",&n) == 1 && n)
        printf("%d\n",n/2);
    return 0;
}

//在基于Internet的程序中，我们常常需要判断一个IP字符串的合法性。
//合法的IP是这样的形式： A.B.C.D 其中A、B、C、D均为位于[0, 255]中的整数。
//为了简单起见，我们规定这四个整数中不允许有前导零存在，如001这种情况。
//输入由多行组成，每行是一个字符串，字符串长度最大为30，且不含空格和不可见字符
//对于每一个输入，单独输出一行 如果该字符串是合法的IP，输出Y，否则，输出N
//#include<stdio.h>
//#include<string.h>
//int test(char str[])
//{
//    int i,num=0;
//    for(i=0; i<strlen(str); i++)
//    {
//        num=0;
//        do
//        {
//            if(str[i]<'0'||str[i]>'9')
//                return 0;
//            if(str[i]>='0'&&str[i]<='9')
//                num=10*num+str[i]-'0';
//            if(num<0||num>255)
//                return 0;
//            i++;
//            if(str[i]=='\0')
//                break;
//        }while(str[i]!='.');
//    }
//    return 1;
//}
//int main()
//{
//    char str[35];
//    while(scanf("%s",str)!=EOF)
//    {
//        if(test(str)==0)
//            printf("N\n");
//        else printf("Y\n");
//    }
//    return 0;
//}

//DNA
//第一个整数N（N<=15）,N表示组数，每组数据包含两个整数a,b。a表示一个单位的DNA串的行数，a为奇数且 3<=a<=39。b表示重复度(1<=b<=20)。当a（max）=79时,b=3；当a=39（max）时，b=7！当a=3时，b=98；当b（max）=20时，a=14；
//输出DNA的形状，每组输出间有一空行。
#include<stdio.h>
int main()
{
    int i,j,k,l,N,a,b;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=1; i<=N; i++)
        {
            scanf("%d%d",&a,&b);
            for(int i=1; i<=b; i++)
                for(int j=1; j<=a; j++)
                {
                    for(int k=1; k<=a; k++)
                    {
                        if(k==j||k==a-j+1)
                            printf("X");
                        else
                            printf(" ");
                    }
                    printf("\n");
                }
            printf("\n");
        }
    }
    return 0;
}

//舍罕王的失算
/*#include<stdio.h>
int main()
{
    int i;
    double sum=1,n=1;
    for(i=1;i<64;i++)
    {
        n=n*2;
        sum=sum+n;
    }
    printf("%.0f",sum - 1);
    return 0;
}*/

