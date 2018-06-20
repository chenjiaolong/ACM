//Pku acm 1163 the Triangle数字三角形(Communication System)
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int main()
//{
//    int N;
//    int dp[120][120];
//    while(~scanf("%d",&N))
//    {
//        for(int i=1; i<=N; i++)
//            for(int j=1; j<=i; j++)
//                scanf("%d",&dp[i][j]);
//        for(int i=N-1; i>=1; i--)
//            for(int j=1; j<=i; j++)
//                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
//        printf("%d\n",dp[1][1]);
//    }
//    return 0;
//}

//Pku acm 1458 Longest Common Subsequence LCS
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int dp[1000][1000];
//int main()
//{
//    char str[1000],str2[1000];
//    while(~scanf("%s%s",str,str2))
//    {
//        for(int i=0; i<1000; i++)
//            dp[i][0]=0;
//        for(int j=0; j<1000; j++)
//            dp[0][j]=0;
//        for(int i=1; i<=strlen(str); i++)
//            for(int j=1; j<=strlen(str2); j++)
//            {
//                if(str[i-1]==str2[j-1])
//                    dp[i][j]=dp[i-1][j-1]+1;
//                else
//                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//            }
//        printf("%d\n",dp[strlen(str)][strlen(str2)]);
//    }
//    return 0;
//}

//Pku acm 1579 Function Run Fun用DP修改递归函数——节约时间(To the Max)
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//long long dp[30][30][30];
//long long w(int a,int b,int c)
//{
//    if(dp[a][b][c])
//        return dp[a][b][c];
//    if(a<=0||b<=0||c<=0)
//        return 1;
//    if(a<b&&b<c)
//        return dp[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
//    return dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
//}
//int main()
//{
//    int m,n,p;
//    while(~scanf("%d%d%d",&m,&n,&p))
//    {
//        if(m==-1&&n==-1&&p==-1)
//            break;
//        if(m<=0||n<=0||p<=0)
//        {
//            printf("w(%d, %d, %d) = 1\n",m,n,p);
//            continue;
//        }
//        memset(dp,0,sizeof(dp));
//        if(m>20||n>20||p>20)
//            printf("w(%d, %d, %d) = %lld\n",m,n,p,w(20,20,20));
//        else
//            printf("w(%d, %d, %d) = %lld\n",m,n,p,w(m,n,p));
//    }
//    return 0;
//}

//Pku acm 2081 Recaman's Sequence(Moving Tables)
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//long long dp[500005];
//bool flag[10000000];
//int main()
//{
//    memset(dp,0,sizeof(dp));
//    memset(flag,false,sizeof(flag));
//    for(int i=1; i<=500000; i++)
//    {
//        if(dp[i-1]-i>0&&!flag[dp[i-1]-i])
//            dp[i]=dp[i-1]-i;
//        else
//            dp[i]=dp[i-1]+i;
//        flag[dp[i]]=true;
//    }
//    int k;
//    while(~scanf("%d",&k))
//    {
//        if(k==-1)
//            break;
//        if(k==0)
//        {
//            printf("0\n");
//            continue;
//        }
//        printf("%d\n",dp[k]);
//    }
//    return 0;
//}

//Pku acm 1159 Palindrome 回文串的LCS应用
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int dp[4][5005];
//int main()
//{
//    int N;
//    char str[5005],str2[5005];
//    while(~scanf("%d",&N))
//    {
//        scanf("%s", str);
//        int j=0;
//        for(int i=N-1; i>=0; i--)
//            str2[j++]=str[i];
//        str2[N]='\0';
//        for(int i=1; i<=N; i++)
//            for(int j=1; j<=N; j++)
//            {
//                int cur = i % 2;
//                if(str[i-1]==str2[j-1])
//                    dp[cur][j]=dp[(cur + 1) % 2][j-1]+1;
//                else
//                    dp[cur][j]=max(dp[(cur + 1) % 2][j],dp[cur][j-1]);
//            }
//        printf("%d\n",N-dp[N % 2][N]);
//    }
//    return 0;
//}

//最大区间的递增序列的长度
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int dp[1005];
//int main()
//{
//    int N,array[1005],temp;
//    int maxlen;
//    while(~scanf("%d",&N))
//    {
//        for(int i=0; i<N; i++)
//            scanf("%d",&array[i]);
//        dp[0]=1;
//        for(int i=1; i<N; i++)
//        {
//            temp=0;
//            for(int j=0; j<i; j++)
//                if(array[j]<array[i]&&temp<dp[j])
//                    temp=dp[j];
//            dp[i]=temp+1;
//        }
//        maxlen=0;
//        for(int i=0; i<N; i++)
//            if(maxlen<dp[i])
//                maxlen=dp[i];
//        printf("%d\n",maxlen);
//    }
//    return 0;
//}

//arrange the window of your flower shop
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<limits.h>
//using namespace std;
//int main()
//{
//    int F,V,max;
//    int array[105][105];
//    while(~scanf("%d%d",&F,&V))
//    {
//        for(int i=0; i<F; i++)
//            for(int j=0; j<V; j++)
//                scanf("%d",&array[i][j]);
//        for(int i=1; i<F; i++)
//            for(int j=i; j<V; j++)
//            {
//                max=INT_MIN;
//                for(int k=j-1; k>=0; k--)
//                    if(max<array[i-1][k])
//                        max=array[i-1][k];
//                array[i][j]+=max;
//            }
//        max=INT_MIN;
//        for(int j=0; j<V; j++)
//            if(max<array[F-1][j])
//                max=array[F-1][j];
//        printf("%d\n",max);
//    }
//    return 0;
//}

//LDS最长递减子序列
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int main()
//{
//    int temp,cnt=0,cur=0,flag=0;
//    int dp[10100],array[10010];
//    while(~scanf("%d",&temp))
//    {
//        if(temp==-1&&!flag)
//            break;
//        if(temp!=-1)
//        {
//            array[cur++]=temp;
//            flag=1;
//            continue;
//        }
//        dp[0]=1;
//        for(int i=1; i<cur; i++)
//        {
//            int temp=0;
//            for(int j=0; j<i; j++)
//                if(array[i]<array[j]&&temp<dp[j])
//                    temp=dp[j];
//            dp[i]=temp+1;
//        }
//        int maximum=dp[0];
//        for(int i=1;i<cur;i++)
//            if(maximum<dp[i])
//                maximum=dp[i];
//        printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++cnt,maximum);
//        flag=0,cur=0;
//    }
//    return 0;
//}

//在一个区域中从高到低滑雪，求最长底滑坡
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int dp[105][105];
//int area[105][105];
//int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
//int R,C;
//int DFS(int x,int y)
//{
//    for(int i=0; i<4; i++)
//    {
//        int xx=x+dir[i][0];
//        int yy=y+dir[i][1];
//        if(xx>=0&&xx<R&&yy>=0&&yy<C&&(dp[xx][yy]==1||dp[x][y]+1>dp[xx][yy])&&area[xx][yy]>area[x][y])
//        {
//            dp[xx][yy]=dp[x][y]+1;
//            DFS(xx,yy);
//            dp[x][y]=dp[xx][yy]-1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int num;
//    int pos[20010];
//    while(~scanf("%d%d",&R,&C))
//    {
//        num=0;
//        for(int i=0; i<R; i++)
//            for(int j=0; j<C; j++)
//            {
//                scanf("%d",&area[i][j]);
//                dp[i][j]=1;
//            }
//        for(int i=0; i<R; i++)
//            for(int j=0; j<C; j++)
//            {
//                int xx,yy,flag=0;
//                for(int x=0; x<4; x++)
//                {
//                    xx=i+dir[x][0];
//                    yy=j+dir[x][1];
//                    if(xx>=0&&xx<R&&yy>=0&&yy<C&&area[i][j]>=area[xx][yy])
//                    {
//                        flag=1;
//                        break;
//                    }
//                }
//                if(!flag)
//                {
//                    pos[num++]=i;
//                    pos[num++]=j;
//                }
//            }
//        for(int i=0; i<num/2; i++)
//            DFS(pos[2*i],pos[2*i+1]);
//        int maxlen=dp[0][0];
//        for(int i=0; i<R; i++)
//            for(int j=0; j<C; j++)
//                if(maxlen<dp[i][j])
//                    maxlen=dp[i][j];
//        printf("%d\n",maxlen);
//    }
//    return 0;
//}

#include<string>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 110;

string ans[maxn + 5], a[maxn + 5], b[maxn + 5];
int cur;
int dp[maxn + 5][maxn + 5];

void DFS(int x, int y, int len)
{
    if(len == 0) return;
    if(dp[x][y] == dp[x - 1][y]) DFS(x - 1, y, len);
    else if(dp[x][y] == dp[x][y - 1]) DFS(x, y - 1, len);
    else
    {
        DFS(x - 1, y - 1, len - 1);
        ans[cur ++] = a[x - 1];// 此两行代码如果是这样就正着输出来，交换顺序就倒着输出来
    }
}
int main()
{
    string str;
    while(cin >> str)
    {
        int len1 = 0, len2 = 0;
        if(str != "#") a[len1++] = str;
        while(cin >> str)
        {
            if(str == "#") break;
            a[len1++] = str;
        }
        while(cin >> str)
        {
            if(str == "#") break;
            b[len2++] = str;
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len1; i ++)
            for(int j = 1; j <= len2; j ++)
            {
                if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
            }
        cur = 0;
        DFS(len1, len2, dp[len1][len2]);
        for(int i = 0; i < cur - 1; i ++)
            cout << ans[i] << " ";
        cout << ans[cur - 1] << endl;
    }
    return 0;
}
