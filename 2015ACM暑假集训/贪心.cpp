//木块装箱问题
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int cnt2[4]={0,5,3,1};//2*2
//int main()
//{
//    int d[10];
//    while(1)
//    {
//        int sum=0;
//        for(int i=1;i<=6;i++)
//        {
//            scanf("%d",&d[i]);
//            sum+=d[i];
//        }
//        if(sum==0)
//            break;
//        int ans=0;
//        ans+=d[6]+d[5]+d[4]+(d[3]+3)/4;
//        int d2=d[4]*5+cnt2[d[3]%4];//ÓÃ2*2Ìî¿Õ
//        if(d2<d[2])
//            ans+=(d[2]-d2+8)/9;
//        int d1=ans*36-d[6]*36-d[5]*25-d[4]*16-d[3]*9-d[2]*4;//ÓÃ1*1Ìî¿Õ
//        if(d1<d[1])
//            ans+=(d[1]-d1+35)/36;
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//数的种类
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<map>
//using namespace std;
//int main()
//{
//    int N,array[105],K;
//    while(~scanf("%d",&N))
//    {
//        for(int i=0; i<N; i++)
//            scanf("%d",&array[i]);
//        scanf("%d",&K);
//        sort(array,array+N);
//        int m=unique(array,array+N)-array;
//        if(N-m<K)
//            printf("%d\n",m-(K-(N-m)));
//        else
//        printf("%d\n",m);
//    }
//    return 0;
//}

//田忌赛马问题
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//int cmp(int a, int b)
//{
//    return a > b;
//}
//
//int main()
//{
//    int n;
//    int tianji[1010];
//    int King[1010];
//    while(scanf("%d", &n), n)
//    {
//        int k = n;
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &tianji[i]);
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &King[i]);
//        sort(tianji + 1, tianji + n + 1, cmp);
//        sort(King + 1, King + n + 1, cmp);
//        int t = 0;
//        for(int i = 1, j = 1; i <= n && j <= k; )
//        {
//            if(tianji[i] > King[j])
//            {
//                i ++;
//                j ++;
//                t ++;
//            }
//            else
//            {
//                if(tianji[n] > King[k])
//                {
//                    t ++;
//                    n --;
//                    k --;
//                }
//                else if(tianji[n] == King[k])
//                {
//                    if(tianji[n] < King[j])
//                        t --;
//                    if(tianji[n] == King[j] && tianji[i] < King[j])
//                        t --;
//                    n --;
//                    j ++;
//                }
//                else
//                {
//                    j ++;
//                    n --;
//                    t --;
//                }
//
//            }
//        }
//        printf("%d\n", t * 200);
//    }
//    return 0;
//}

//球的碰撞问题
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<map>
//#include<algorithm>
//#include<math.h>
//#include<stdlib.h>
//using namespace std;
//float a[1000];
//int cmp(int a,int b)
//{
//    return a>b;
//}
//int main()
//{
//    int N;
//    while(~scanf("%d",&N))
//    {
//        for(int i=0; i<N; i++)
//            scanf("%f",&a[i]);
//        sort(a,a+N,cmp);
//        if(N==1)
//        {
//            printf("%.3f\n",a[0]*1.0);
//            continue;
//        }
//        while(1)
//        {
//            a[0]=2*sqrt(a[0]*a[1]);
//            if(N-1==1)
//                break;
//            for(int j=1; j<N-1; j++)
//                a[j]=a[j+1];
//            N--;
//            sort(a,a+N,cmp);
//        }
//        printf("%.3f\n",a[0]);
//    }
//    return 0;
//}

//奖项奖杯问题
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<map>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n,min1,max1,min2,max2,min3,max3,sum1,sum2,sum3;
//    while(~scanf("%d",&n))
//    {
//        sum1=0,sum2=0,sum3=0;
//        scanf("%d%d",&min1,&max1);
//        scanf("%d%d",&min2,&max2);
//        scanf("%d%d",&min3,&max3);
//        sum1=min1;
//        sum2=min2;
//        sum3=min3;
//        if(sum1+sum2+sum3==n)
//        {
//            printf("%d %d %d\n",sum1,sum2,sum3);
//            continue;
//        }
//        while(1)
//        {
//            for(int i=min1+1; i<=max1; i++)
//            {
//                sum1=sum1+1;
//                if(sum1+sum2+sum3==n)
//                    break;
//            }
//            if(sum1+sum2+sum3==n)
//                break;
//            for(int i=min2+1; i<=max2; i++)
//            {
//                sum2=sum2+1;
//                if(sum1+sum2+sum3==n)
//                    break;
//            }
//            if(sum1+sum2+sum3==n)
//                break;
//            for(int i=min3+1; i<=max3; i++)
//            {
//                sum3=sum3+1;
//                if(sum1+sum2+sum3==n)
//                    break;
//            }
//            if(sum1+sum2+sum3==n)
//                break;
//        }
//        printf("%d %d %d\n",sum1,sum2,sum3);
//    }
//    return 0;
//}

//茶水问题
#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,w;
    double a[200100];
    double ans;
    while(~scanf("%d%d",&n,&w))
    {
        for(int i=0; i<2*n; i++)
            scanf("%lf",&a[i]);
        sort(a,a+2*n);
        if(a[0]<=a[n]/2)
            ans=n*a[0]+2*n*a[0];
        else
            ans=n*a[n]+n*a[n]/2;
        if(ans>w)
            ans=w;
        printf("%.6f\n",ans);
    }
    return 0;
}

//牛吃花问题
//#include<cstdio>
//#include<string>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//using namespace std;
//struct node
//{
//    int T,D;
//} array[100100];
//int cmp(struct node a,struct node b)
//{
//    return a.T*b.D<a.D*b.T;
//}
//int main()
//{
//    int N;
//    while(~scanf("%d",&N))
//    {
//        long long ans=0;
//        int sum=0;
//        for(int i=0; i<N; i++)
//        {
//            scanf("%d%d",&array[i].T,&array[i].D);
//            sum+=array[i].D;
//        }
//        sort(array,array+N,cmp);
//        for(int i=0; i<N; i++)
//            printf("%d %d\n",array[i].T,array[i].D);
//        sum=sum-array[0].D;
//        for(int i=0; i<N-1; i++)
//        {
//            ans=ans+sum*array[i].T;
//            sum=sum-array[i+1].D;
//        }
//        printf("%lld\n",ans*2);
//    }
//    return 0;
//}

//安装炸弹问题
//#include<cstdio>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<cstring>
//using namespace std;
//int main()
//{
//    int R,n,x,flag[10100]={0};
//    while(~scanf("%d%d",&R,&n))
//    {
//        memset(flag,0,sizeof(flag));
//        if(R==-1&&n==-1)
//            break;
//        int cnt=0;
//        for(int i=0; i<n; i++)
//        {
//            scanf("%d",&x);
//            flag[x]=1;
//        }
//        for(int i=0; i<=1000; i++)
//        {
//            if(flag[i])
//            {
//                i=i+R;
//                wtanxinderentaiduolunbudaowolehile(1)
//                {
//                    if(flag[i])
//                    {
//                        i=i+R;
//                        cnt++;
//                        break;
//                    }
//                    i--;
//                }
//            }
//        }
//        printf("%d\n",cnt);
//    }
//    return 0;
//}
//

