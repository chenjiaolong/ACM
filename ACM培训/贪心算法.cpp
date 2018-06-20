//木块装箱问题
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int cnt2[4]={0,5,3,1};//2*2
int main()
{
    int d[10];
    while(1)
    {
        int sum=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&d[i]);
            sum+=d[i];
        }
        if(sum==0)
            break;
        int ans=0;
        ans+=d[6]+d[5]+d[4]+(d[3]+3)/4;
        int d2=d[4]*5+cnt2[d[3]%4];//用2*2填空
        if(d2<d[2])
            ans+=(d[2]-d2+8)/9;
        int d1=ans*36-d[6]*36-d[5]*25-d[4]*16-d[3]*9-d[2]*4;//用1*1填空
        if(d1<d[1])
            ans+=(d[1]-d1+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}
