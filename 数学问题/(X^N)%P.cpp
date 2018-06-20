// ���N��ż������ôX ^ N = X * X ^��N/2��;
// ���N����������ôX ^ N = X * X ^(N - 1) = X * (X * X) ^ ��N/2��;
// ���Щ�N����ָС�ڻ��ߵ���N���������
#include<stdio.h>
/*�������ܣ�����ģ������򣬲��õݹ鷽ʽ������X ^ N (%P)��������PowerMod����ֵ��unsigned int X������ x unsigned int N��ָ��unsigned int P��ģP����ֵ��unsigned int�� X ^ N (%P)*/
unsigned int PowerMod(unsigned int X,unsigned int N,unsigned int P)
{
    if(N == 0)
        return 1;
    unsigned int temp = PowerMod((X * X) % P,N/2,P);//�ݹ���㣨X * X��^��N/2��;
    if(N & 1)//�ж�N����ż��
        temp = (temp * X) % P;
    return temp;
}
int main(int argc, char *argv[])
{
    unsigned int X,N,P;
    while(scanf("%u%u%u",&X,&N,&P) == 3)
        printf("%u\n",PowerMod(X,N,P));
    return 0;
}

//#include<stdio.h>
//// ����ָ��ģ����
//// m����,eָ��,nģ��
//int mod(int m,int e,int n)
//{
//    int c = 1;
//    while(e)
//    {
//        if(e&1)
//        {
//            e = e-1 ;
//            c = (c*m)%n ;
//        }
//        else
//        {
//            e = e/2 ;
//            m = (m*m)%n ;
//        }
//    }
//    return c ;
//}
//
//int main()
//{
//    //����
//    printf("ģn�Ĵ��������� = %d\n",mod(11,7,13));
//    getch();
//    return 0;
//}
