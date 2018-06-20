//lg (N !) = lg(2) + lg(3) + ^ + lg(N);
//10^m = N !
//λ�� = log10(N !) + 1
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        double sum = 0.0;
//        for(int i = 2; i <= n; i++)
//            sum += log10(i);
//        printf("%lld\n",(long long)sum + 1);
//    }
//    return 0;
//}

//˹���ֹ�ʽ Stirling ��ʽ n ! = �� ��2 * �� * n����n/e��^n
#include<stdio.h>
#include<math.h>
int main()
{
    double c1 = 0.798179868358;//lg2*��
    double c2 = 0.434294481093;//lge
    int n;
    while(scanf("%d",&n) != EOF)
    {
        double c3 = log10(n);
        long long s = 1;
        if(n > 3)//n < 3 �����������
            s = (c3 + c1)/2 + n * (c3 - c2) + 1;
        printf("%lld\n",s);

    }
    return 0;
}
