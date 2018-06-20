//#include <stdio.h>
//int main ()
//{
//    int n,a=0,b=0,sum1=0,sum2=0,average1,average2;
//    printf("请输入一个一位数");
//    scanf("%d",&n);
//    while(n!=0)
//    {
//        if(n%2==0)
//        {
//            a++;
//            sum1=sum1+n;
//        }
//        else
//        {
//            b++;
//            sum2=sum2+n;
//        }
//        printf("请输入一个一位数");
//        scanf("%d",&n);
//    }
//    average1=sum1/a;
//    average2=sum2/b;
//    printf("偶数总个数为%d，偶数平均数为%d，奇数总个数为%d，奇数的平均数%d",a,average1,b,average2);
//    return 0;
//}

//统计字母（小写）个数
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,count[30];
    char ch;
    char str[12000];
    for(i=0; i<26; i++)
        count[i]=0;
    for(i=0;; i++)
    {
        scanf("%c",&str[i]);
        if(str[i]=='#')
            break;
    }
    for(i=0; i<strlen(str)-1; i++)
    {
        count[str[i]-'a']++;
        /*switch(str[i])
        {
            case 'a':count[0]++;break;
            case 'b':count[1]++;break;
            case 'c':count[2]++;break;
            case 'd':count[3]++;break;
            case 'e':count[4]++;break;
            case 'f':count[5]++;break;
            case 'g':count[6]++;break;
            case 'h':count[7]++;break;
            case 'i':count[8]++;break;
            case 'j':count[9]++;break;
            case 'k':count[10]++;break;
            case 'l':count[11]++;break;
            case 'm':count[12]++;break;
            case 'n':count[13]++;break;
            case 'o':count[14]++;break;
            case 'p':count[15]++;break;
            case 'q':count[16]++;break;
            case 'r':count[17]++;break;
            case 's':count[18]++;break;
            case 't':count[19]++;break;
            case 'u':count[20]++;break;
            case 'v':count[21]++;break;
            case 'w':count[22]++;break;
            case 'x':count[23]++;break;
            case 'y':count[24]++;break;
            case 'z':count[25]++;break;
        }*/
    }
    for(i=0,ch='a'; i<26,ch<='z'; i++,ch++)
        printf("%c %d\n",ch,count[i]);
    return 0;
}


