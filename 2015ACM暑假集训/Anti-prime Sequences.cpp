#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int ans[1000],m,n,d,len;//lenΪsequence�ĳ��ȣ�����m-n+1
bool flag,vis[1001],composite[10000]= {1,1}; //flag�����ж��Ƿ�����anti-prime sequence

//ɸѡ����,composite[i]=1���ҽ���i��������
void InitComposite()
{
    for(int i=2; i<1001; i++)
        if(!composite[i])
            for(int j=2; j*i<10000; j++)
                composite[i*j]=1;
    //for(int i=0; i<100; i++)cout<<i<<":"<<composite[i]<<" "<<endl;
}

//���sum�Ƿ���composite number
bool CheckSum(int idx)
{
    int sum=ans[idx];
    for(int i=idx-1; i>-1&&i>idx-d; i--)
    {
        sum+=ans[i];
        if(!composite[sum])
            return 0;
    }
    return 1;
}

//depth��¼��ǰ�ж��ٸ����ɹ�����sequence
void DFS(int depth)
{
    //��depth����lenʱ�������ҵ�anti-prime sequence
    if(depth==len)
    {
        flag=1;
        return ;
    }
    for(int i=n; i<=m; i++)
        if(!vis[i])
        {
            ans[depth]=i;
            if(CheckSum(depth))
            {
                vis[i]=1;
                //ans�е�depth�����Ѿ�ȷ������depth+1������
                DFS(depth+1);
                vis[i]=0;//��Ҫ©�����������
                if(flag)
                    return ;
            }
        }
    return ;
}

int main()
{
    InitComposite();
    while(scanf("%d%d%d",&n,&m,&d) && m)
    {
        memset(vis,0,sizeof(vis));
        len=m-n+1;
        flag=0;
        DFS(0);
        if(flag)
        {
            for(int i=0; i<len-1; i++)
                printf("%d,",ans[i]);
            printf("%d\n",ans[len-1]);
        }
        else puts("No anti-prime sequence exists.");
    }
    return 0;
}
