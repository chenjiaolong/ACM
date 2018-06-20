//杨二哥扛把子
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//struct node
//{
//    int w,l;
//    bool operator <(const node &C)const
//    {
//        if(w==C.w)
//            return l<C.l;
//        return w<C.w;
//    }
//} array[5005];
//int main()
//{
//    int n,vis[5005];
//    while(cin>>n)
//    {
//        for(int i=0; i<n; i++)
//            cin>>array[i].w>>array[i].l;
//        sort(array,array+n);
//        memset(vis,0,sizeof(vis));
//        int time=0;
//        for(int i=0; i<n; i++)
//        {
//            int W=array[i].w;
//            int L=array[i].l;
//            if(vis[i]==0)
//            {
//                for(int j=i+1; j<n; j++)
//                    if(array[j].l>=L&&array[j].w>=W&&vis[j]==0)
//                    {
//                        W=array[j].w;
//                        L=array[j].l;
//                        vis[j]=1;
//                    }
//                time++;
//            }
//        }
//        cout<<time<<endl;
//    }
//    return 0;
//}

//梦回大明之朱哥的野望
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n,m;
//    int array[100005];
//    while(cin>>n>>m)
//    {
//        for(int i=0; i<n; i++)
//        {
//            cin>>array[i];
//            array[i]=array[i]%m;
//        }
//        sort(array,array+n);
//        int mm=m-1,temp=0,sum=0;
//        for(int i=n-1; i>=1; i--)
//        {
//            int nn=mm-array[i];
//            int cur=upper_bound(array,array+n,nn)-array-1;
//            if(cur==i)
//                cur=i-1;
//            if(cur==-1)
//                cur++;
//            temp=(array[cur]+array[i])%m;
//            if(temp>sum)
//                sum=temp;
//            if(sum==mm)
//                break;
//        }
//        int M=2*m-1;
//        temp=0;
//        for(int i=n-1;i>=1;i--)
//        {
//            int nn=M-array[i];
//            int cur=upper_bound(array,array+n,nn)-array-1;
//            if(cur==i)
//            cur=i-1;
//            if(cur==-1)
//                cur++;
//            temp=(array[i]+array[cur])%m;
//            if(temp>sum)
//                sum=temp;
//            if(sum==mm)
//                break;
//        }
//        cout<<sum<<endl;
//    }
//    return 0;
//}

//西游降魔
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int main()
//{
//    int T,n,m,k,array[10005];
//    while(cin>>T)
//    {
//        for(int t=1; t<=T; t++)
//        {
//            cin>>n>>m>>k;
//            for(int i=0; i<n; i++)
//                cin>>array[i];
//            sort(array,array+n);
//            for(int i=0; i<n; i++)
//            {
//                if(m<array[0])
//                    break;
//                if(m>=array[i])
//                    continue;
//                m=array[i-1]+k--;
//                if(m<array[i])
//                    break;
//            }
//            cout<<"Case #"<<t<<":"<<endl;
//            if(m>=array[n-1])
//                cout<<"why am I so diao?"<<endl;
//            else
//                cout<<"madan!"<<endl;
//        }
//    }
//    return 0;
//}

//我是赌神
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int main()
//{
//    int T,N,l,r;
//    int cards[52];
//    int array[52];
//    while(cin>>T)
//    {
//        for(int t=1; t<=T; t++)
//        {
//            for(int i=0; i<52; i++)
//                cin>>cards[i];
//            cin>>N>>l>>r;
//            N=N%r;
//            for(int i=1; i<=N; i++)
//            {
//                int k=0;
//                for(int j=l-1; j<r; j++)
//                    array[k++]=cards[j];
//                for(int j=0; j<l-1; j++)
//                    array[k++]=cards[j];
//                for(int j=0; j<r; j++)
//                    cards[j]=array[j];
//            }
//            cout<<"Case #"<<t<<": ";
//            for(int i=0;i<51;i++)
//                cout<<cards[i]<<" ";
//            cout<<cards[51]<<endl;
//        }
//    }
//    return 0;
//}

//杨哥哥的小时候
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int N,M;
//    while(~scanf("%d%d",&N,&M)&&N&&M)
//    {
//        if(M>N)
//            M=M%N;
//        if(__gcd(N,M)==1)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

//穿越明朝之富豪杨
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int T;
//    char str[1005];
//    int ans[1005];
//    int vis[1005];
//    while(cin>>T)
//    {
//        for(int t=1; t<=T; t++)
//        {
//            cin>>str;
//            int len=strlen(str);
//            int sum=0;
//            for(int i=0; i<len; i++)
//            {
//                ans[i]=str[i]-'0';
//                ans[i]=ans[i]%3;
//                sum=sum+ans[i];
//            }
//            int times=0;
//            memset(vis,0,sizeof(vis));
//            for(int i=0; i<len; i++)
//                for(int j=0; j<len; j++)
//                    if(!vis[j]&&(sum-ans[j])%3==0)
//                    {
//                        vis[j]=1;
//                        sum=sum-ans[j];
//                        times++;
//                    }
//            if(times&1)
//                cout<<"Case "<<t<<": Y"<<endl;
//            else
//                cout<<"Case "<<t<<": Z"<<endl;
//        }
//    }
//    return 0;
//}

//天才第一步
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,dp[10005],T=0,dp0[10005];
    char str[10005];
    while(~scanf("%d",&n)&&n!=-1)
    {
        getchar();
        if(n==0)
        {
            printf("NUMBER #%d:\n\n\n",++T);
            continue;
        }
        memset(dp,0,sizeof(dp));
        memset(dp0,0,sizeof(dp0));
        for(int i=0; i<n; i++)
            cin>>str[i];
        dp[0]=1,dp0[0]=1;
        for(int i=1; i<n; i++)
        {
            int temp=0,temp1=0;
            for(int j=0; j<i; j++)
            {
                if(str[j]<=str[i]&&temp<dp[j])
                    temp=dp[j]%666;
                if(str[j]<=str[i]&&temp1<dp0[j])
                    temp1=dp0[j];
            }
            dp[i]=(temp+1)%666;
            dp0[i]=(temp1+1);
        }
        int maxlen0=dp[0];
        for(int i=1; i<n; i++)
            if(maxlen0<dp[i])
                maxlen0=dp[i];
        int maxlen=dp0[0];
        for(int i=1; i<n; i++)
            if(maxlen<dp0[i])
                maxlen=dp0[i];
        printf("NUMBER #%d:\nDaodao~Xiaomiao: %d\nYou: %d\n\n",++T,maxlen0,maxlen);
    }
    return 0;
}
