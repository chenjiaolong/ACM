//��ˮƿ����
//���� 1 �� ����˼��
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
//����2 ������˼�� �ǹȲ����Ӧ��
#include<stdio.h>
int main()
{
    int n ;
    while(scanf("%d",&n) == 1 && n)
        printf("%d\n",n/2);
    return 0;
}

//�ڻ���Internet�ĳ����У����ǳ�����Ҫ�ж�һ��IP�ַ����ĺϷ��ԡ�
//�Ϸ���IP����������ʽ�� A.B.C.D ����A��B��C��D��Ϊλ��[0, 255]�е�������
//Ϊ�˼���������ǹ涨���ĸ������в�������ǰ������ڣ���001���������
//�����ɶ�����ɣ�ÿ����һ���ַ������ַ����������Ϊ30���Ҳ����ո�Ͳ��ɼ��ַ�
//����ÿһ�����룬�������һ�� ������ַ����ǺϷ���IP�����Y���������N
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
//��һ������N��N<=15��,N��ʾ������ÿ�����ݰ�����������a,b��a��ʾһ����λ��DNA����������aΪ������ 3<=a<=39��b��ʾ�ظ���(1<=b<=20)����a��max��=79ʱ,b=3����a=39��max��ʱ��b=7����a=3ʱ��b=98����b��max��=20ʱ��a=14��
//���DNA����״��ÿ���������һ���С�
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

//�ằ����ʧ��
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

