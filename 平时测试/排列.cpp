//#include<stdio.h>
//#include<string.h>
//int array[4];
//int ans[3];
//bool vis[4];
//void DFS(int cur)
//{
//    if(cur == 3)
//    {
//        for(int i = 0; i < cur; i++)
//            printf("%d%c",ans[i],i == cur - 1 ? '\n':' ');
//        return;
//    }
//    for(int i = 0; i < 3; i ++)
//        if(!vis[i])
//        {
//            vis[i] = true;
//            ans[cur] = array[i];
//            DFS(cur+1);
//            vis[i] = false;
//        }
//}
//int main()
//{
//    int a,b,c,d;
//    while(~scanf("%d%d%d%d",&a,&b,&c,&d))
//    {
//        array[0] = a;
//        array[1] = b,array[2] = c;
//        memset(vis,false,sizeof(vis));
//        DFS(0);
//        array[2] = d;
//        //memset(vis,false,sizeof(vis));
//        DFS(0);
//        array[1] = c;
//        //memset(vis,false,sizeof(vis));
//        DFS(0);
//        array[0] = b;
//        //memset(vis,false,sizeof(vis));
//        DFS(0);
//    }
//    return 0;
//}

#include<stdio.h>
int main()
{
    int i,j,k,t,n,a[5];
    scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
    for(i=4; i>=1; i--)
        for(j=1; j<=4; j++)
        {
            if(i!=j)
                for(k=1; k<=4; k++)
                {
                    if(k!=i&&k!=j)
                        for(t=1; t<=4; t++)
                        {
                            if(t!=i&&t!=j&&t!=k)
                                printf("%d %d %d\n",a[j],a[k],a[t]);
                        }
                }
        }
    return 0;
}

