//�õ������� ����ƽ�����ĵ�����ʽΪ�� X[n+1]=1/2(X[n]+a/X[n])
//Ҫ��ǰ����������ĵò�ľ���ֵ����0.00001�� �������3λС��
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    double x1,x2,X;
//    printf("please input X numble:");
//    scanf("%lf",&X);
//    if(X<0)
//        printf("erorr");
//    else
//    {
//        x2=1.0;
//        do
//        {
//            x1=x2;
//            x2=0.5*(x1+X/x1);
//        }
//        while(fabs(x2-x1)>=1e-5);
//        printf("a=%.3f,x=%.3f\n",X,x2);
//    }
//    return 0;
//}


//��һ����������ͳ�������ж�����������
//����������һЩ����������ÿ������С��2^32��������Ϊ0����Ӧ����ͳ�ơ�
//�����ͳ�Ƶ�����������
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int j,num,count=0;
    char str[1000000];
    while(scanf("%s",str)!=EOF)
    {
        num=0;
        for(j=0;j<strlen(str);j++)
            num=10*num+str[j]-'0';
        if(num==0)
            break;
        for(j=0;j<=sqrt(num);j++)
            if(num==j*j*j)
                count++;
    }
    printf("%d\n",count);
    return 0;
}



