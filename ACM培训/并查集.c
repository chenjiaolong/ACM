#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int pa[10010];
int cha(int k)
{
    if(pa[k]!=k)
        pa[k]=cha(pa[k]);
    return pa[k];
}
bool bing(int x,int y)
{
    int x1=cha(x);
    int y1=cha(y);
    if(x1==y1)
        return false;
    pa[y1]=x1;
    return true;
}
int main()
{
    int n,m,p,i;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        for(i=0; i<=n; i++)
            pa[i]=i;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            bing(x,y);
        }
        while(p--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(cha(x)==cha(y))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
