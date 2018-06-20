//斯特林（Stirling）公式：
//n ! = √(2*π *n )*(n/e)^n;

//利用斯特林(Stirling)公式求解n!的位数:
//易知整数n的位数为[lg(n)]+1.
//用Stirling公式计算n!结果的位数时，可以两边取对数，得：
//lg(n!) = lg(2*PI*n)/2+n*lg(n/E);
//故n!的位数为
//     res=lg(2*PI*n)/2+n*lg(n/E)+1
//或者为:
//    long result = (long)((lg(sqrt(4.0*acos(0.0)*n))+n*(lg(n)-lg(exp(1.0))))+1); (编程更方便)
//（注意：当n=1时，算得的结果为0）
//n！的估计：
//在高德纳的《计算机程序设计艺术》一书中,对n!的估计:
//n! = sqrt(2*π*n) * ((n/e)^n) * (1 + 1/(12*n) + 1/(288*n*n) + O(1/n^3));

//#include<stdio.h>
//#include<math.h>
//#define PI 3.141592654
//#define E 2.71828182846
//int opt[205];
//int main()
//{
//    //freopen("input","r",stdin);
//    int tmp;
//    int cache;
//    opt[0]=4;
//    for(int i=1; i<=22; i++) opt[i]=opt[i-1]*2;
//    while(scanf("%d",&tmp) == 1&& tmp)
//    {
//        cache=opt[(int)(tmp-1960)/10];
//        double log_n;
//        double log_2=log(2);
//        //printf("%d\n",cache);
//        for(int n=4;; n++)
//        {
//            log_n=0.5*log(2*PI*n)+i=n*log(n/E);
//            if(log_n/log_2>cache)
//            {
//                printf("%d\n",n-1);
//                break;
//            }
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include<sstream>
//#include <cmath>
//#include <map>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//// #define  LL __int64
//#define  LL long long
//const double pi=acos(-1.0);
//const double inx_2=log(2.0); // log -> inx  log10
//int f[30];
//int main()
//{
//  f[0]=1;
//  for(int i=1;i<30;i++)
//    f[i]=f[i-1]*2;
//  int year;
//  while(scanf("%d",&year),year)
//  {
//      double t=f[(year-1960)/10+2];
//      double s=(0.5*log(2*pi)+log(1.0)-1)/inx_2;
//      int i=1;
//      while(s<=t)
//      {
//         i++;
//         s=(0.5*log(2*pi*i)+i*log((double)i)-i)/inx_2;
//      }
//      printf("%d\n",i-1);
//  }
//  return 0;
//}

//题意：求满足n! < 2^k，n的最大值！
//解题：指数比较转换成对数比较,达到降幂！
//        其中：log (n!) = log(n)+log(n-1)+...+log(1);
//        log(2^k) = k * log(2);
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//    int year;
//    while(cin >> year && year >0)
//    {
//        //add 2 because of the beginning with 4, 1<<2 equals with 4
//        int bits = 1<<((year -1960)/10+2);
//        int n=1;
//        double res =0;
//        while(res<bits)
//        {
//            res += log(n)/log(double(2));
//            n++;
//        }
//        cout<<n-2<<endl;
//    }
//    return 0;
//}


//预处理
#include<stdio.h>
#include<math.h>
double a[1000001];
void init()
{
	a[1]=log(1);
	for(int i=2;i<=1000000;i++)
		a[i]=a[i-1]+(log(i)/log(2));
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
	    double num = 4.0*pow(2,((n-1960)/10));
	    int i;
		for(i=1;i<=1000000;i++)
			if(a[i]>num)
				break;
		printf("%d\n",i-1);
	}
	return 0;
}

//求满足 m! <= 2^n 的最大m
//两边取log：log1 + log2 +.....+logm <= n
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//int main(int argc, char const *argv[])
//{
//    int year;
//    while (cin >> year && year != 0)
//    {
//        int times = (year - 1960) / 10;
//        int bit = (int)pow(2, times + 2);
//        double sum = 0;
//        int n = 1;
//        while (sum <= bit)
//            sum += log2(n++);  // 将大整数运算转换为对数运算
//        cout << n - 2 << endl;
//    }
//    return 0;
//}
