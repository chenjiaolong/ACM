//��Ŀ��˼:
//����f(x) = ����(a * b)|x�������(a,b)�ĸ�����
//Ȼ������һ��n����f(1) + f(2) + ... + f(n)
//#include <math.h>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//__int64 mypow(__int64  x,__int64 a)//x��a�η���
//{
//    __int64 m=pow(x,1.0/a),i,j,sum;//����ϵͳ�����Ѵ�ŷ�Χ�������
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
//        if(sum>x)//��û��=��
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
//        sum=iall;//iii������ʽ�ĸպ���iall��
//        for(i=1; i<=iall; i++)
//        {
//            ni=n/i;//�ӿ��ٶ�
//            k=mypow(ni,2);
//            sum+=(ni/i+k-2*i)*3;//iij�ĸ���Ϊni/i-i;ijj������ʽ�ĸ���Ϊk-i��
//            for(j=i+1; j<=k; j++) //�����Ƴ�jС�ڸ����£�n/i�������ٶȸ���
//                sum+=(ni/j-j)*6;
//        }
//        printf("Case %d: %I64d\n",tcase++,sum);
//    }
//    return 0;
//}

//��ԭ�������(a * b)|x ת��Ϊ a * b * y = x
//  Ȼ��ͺܺü����ˣ����ǣ�����һ��n�������ж��������(a, b ,y)����a*b*y<=n
//  ������a<=b<=y
//  ��a<=n^(1/3) , b<=sqrt(n/a)
//  ��ô
//        �����������ֶ���ͬ�������ֻ����һ��: i i i
//        ����������������������ͬ�����������3��: i i j, i j i, j i i
//        ���ھ�����ͬ�����������6��: a b y ,a y b ,b a y ,b y a, y a b ,y b a
//#include <math.h>
//#include <stdio.h>
//using namespace std;
//long long n,ans;
//long long sqrt2(long long nn)// long long ��ƽ��
//{
//    long long k;
//    k=pow(nn*1.0,0.5);
//    while(k*k<=nn) k++;
//    while(k*k>nn) k--;
//    return k;
//}
//long long sqrt3(long long nn)    // long long ������
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
//        sq2=sqrt2(n);       // ����ֱ����sqrt��pow��ƽ����������WA  �����Ǹ�������
//        sq3=sqrt3(n);
//        ans=sq3;                    // ��һ�����
//        for(i=1; i<=sq2; i++)       // �ڶ������
//        {
//            s=(n/((long long)(i)*i));
//            if(s<1) break;
//            if(i<=sq3) ans+=(s*3-3);
//            else ans+=s*3;
//        }
//        for(i=1; i<=sq3; i++)       // ���������
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

//a*b*y<=n��(a,b,y)����Ŀ
//����a<=b<=y,�����д�����ǵ�ȡֵ��Χa<=pow(n,1.0/3.0);b<=sqrt(n/a);y>=b;
//    ��Ϊ������ԣ�����a=b=y��sum+=1��
//                                    a=b!=y||a!=b=yʱ��sum+=3��
//                                    a!=b!=yʱ��sum+=6��(��һ�룬Ϊʲô�أ�)
//    ��Ϊö�ٱ�Ȼ��ʱ������ѡ��ʹ���㷨�����a=b=y����Ŀ��pow(n,1.0/3.0)
//                                    a=b!=y||a!=b=y����Ŀ��n/(a*a)-a+b-a
//                                    a!=b!=y����Ŀ��n/(a*b)-b
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    __int64 A,B,C,sum,n,i,j,t=1;           //��סֻ����__int64��ʹ��unsigned long long�����س�ʱ
//    while(~scanf("%I64d",&n))          //ʹ��%I64d����
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
//        printf("Case %I64d: %I64d\n",t++,sum);   //ʹ��%I64d���
//    }
//
//    return 0;
//}

//˼��:��f(1)+f(2)+..+f(n)������f��x����x��Լ���ĸ���
//ת��Ϊa*b<=n�Ľ�ĸ������������PS:ö��Լ����Ȼ��ֱ���㣬����n/1+n/2+..+n/n
//Ȼ����ͬ����ⷽʽ��Ȼ���źܴ������������յ�һ��˼ά��ʽȥ���
//������ǲ��ǿ���ת��Ϊa*b*c<=n�Ľ�ĸ�����������
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
