//#include <stdio.h>
//#include <string.h>
//
//const int maxn = 100005;
//     // �������������ݣ������Ҫ��long long ���ܹ�.
//long long sum[maxn << 2],mar[maxn << 2];
//
//void pushup(int o)
//{
//    sum[o] = sum[o << 1] + sum[o << 1 | 1];
//}
//
//void pushdown(int o,int m) // m ��ʾ�ڵ�o���ж��ٸ���
//{
//    //  m ���� r - l + 1
//    if (mar[o])
//    {
//        //-----------------------------------------
//        // ע������ĸ����ǽ���һ�εĸ��´��ݸ�������
//        // �Է�ֹ�Ժ�������õ����ӽڵ�
//        mar[o << 1] += mar[o];
//        mar[o << 1 | 1] += mar[o];
//        //-----------------------------------------
//        // sum ���֮ǰûע�⣬�������ʱӦ�ó���
//        // ���������������ĸ���
//        sum[o << 1] += mar[o] * (m - (m >> 1));
//        sum[o << 1 | 1] += mar[o] * (m >> 1);
//        //-----------------------------------------
//        mar[o] = 0;
//    }
//}
//
//void build(int l,int r,int o)
//{
//    mar[o] = 0;
//    if (l == r)
//    {
//        scanf("%lld",&sum[o]);
//        return;
//    }
//    int m = (l + r) >> 1;
//    build(l,m,o << 1);
//    build(m + 1,r,o << 1 | 1);
//    pushup(o);
//}
//
//void update(int L,int R,int d,int l,int r,int o)
//{
//    if (L <= l && r <= R)
//    {
//        // ���� mar Ϊʲô�� += �����Լ�˼��.
//        mar[o] += d;
//        sum[o] += d * (r - l + 1);
//        return;
//    }
//    pushdown(o,r - l + 1);
//    int m = (l + r) >> 1;
//    if (L <= m)
//        update(L,R,d,l,m,o << 1);
//    if (m < R)
//        update(L,R,d,m + 1,r,o << 1 | 1);
//    pushup(o);
//
//}
//
//long long query(int L,int R,int l,int r,int o)
//{
//    if (L <= l && r <= R)
//        return sum[o];
//    pushdown(o,r - l + 1);
//    int m = (l + r) >> 1;
//    long long res = 0;
//    if (L <= m)
//        res += query(L,R,l,m,o << 1);
//    if (m < R)
//        res += query(L,R,m + 1,r,o << 1 | 1);
//    return res;
//}
//
//int main()
//{
//    int n,q;
//    while (~scanf("%d %d",&n,&q) && n)
//    {
//        build(1,n,1);
//        while (q--)
//        {
//            char str[10];
//            scanf("%s",str);
//            if (str[0] == 'Q')
//            {
//                int x,y;
//                scanf("%d %d",&x,&y);
//                printf("%lld\n",query(x,y,1,n,1));
//            }
//            else
//            {
//                int x,y,d;
//                scanf("%d %d %d",&x,&y,&d);
//                update(x,y,d,1,n,1);
//            }
//        }
//    }
//}

//�����
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define N 100100<<2
//using namespace std;
//int sto[N];
//int n,q,x,y;
//void init(int t,int w,int o)
//{
//    printf("******t=%d,w=%d,o=%d\n",t,w,o);
//    if(t==w)//���䵽Ҷ��㣬�����λ��
//    {
//        printf("*****t=%d,w=%d,o=%d\n",t,w,o);
//        scanf("%d",&sto[o]);//�������������
//        return;
//    }
//    int mid=(t+w)>>1;//�������䣬ʹ�ö����������ܵ�ƽ�⻯
//    printf("****t=%d,w=%d,mid=%d\n",t,w,mid);
//    int lso=o<<1;
//    printf("***lso=%d,o=%d\n",lso,o);
//    init(t,mid,lso);//��������
//    printf("**t=%d,mid=%d,lso=%d\n",t,mid,lso);
//    init(mid+1,w,lso|1);//��������
//    printf("*mid+1=%d,w=%d,lso|1=%d\n",mid+1,w,lso|1);
//    sto[o]=max(sto[lso],sto[lso|1]);//���ڵ㱣���ӽڵ����ֵ
//    printf("sto[o]=%d,o=%d,lso=%d,lso|1=%d\n",sto[o],o,lso,lso|1);
//}
//int update(int t,int w,int o,int st,int en)
//{
//    if(st<=t&&w<=en)//���ҵ���������ڵ�ǰ�ڵ�����䣬ֱ�ӷ��ص�ǰ�ڵ����������
//        return sto[o];
//    int mid=(t+w)>>1;
//    int lso=o<<1;
//    int ans=-1<<29;
//    if(st<=mid)
//        ans=max(ans,update(t,mid,lso,st,en));
//    if(mid<en)
//        ans=max(ans,update(mid+1,w,lso|1,st,en));
//    return ans;
//}
//int main()
//{
//    while(~scanf("%d",&n))//�������ݵĸ���
//    {
//        init(1,n,1);
//        scanf("%d",&q);//��Ҫ���ʵĴ���
//        for(int i=1; i<=q; i++)
//        {
//            scanf("%d%d",&x,&y);//���ʵ����䷶Χ
//            printf("%d\n",update(1,n,1,x,y));
//        }
//    }
//    return 0;
//}

//�������
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100100<<2
using namespace std;
int sto[N],up[N];
char s[10];
int n,q,x,y,z;
void init(int t,int w,int o)
{
    up[o]=0;
    if(t==w)//���䵽Ҷ��㣬�����λ��
    {
        scanf("%d",&sto[o]);//�������������
        return;
    }
    int mid=(t+w)>>1;//�������䣬ʹ�ö����������ܵ�ƽ�⻯
    int lso=o<<1;
    init(t,mid,lso);//��������
    init(mid+1,w,lso|1);//��������
    sto[o]=sto[lso]+sto[lso|1];//���ڵ㱣���ӽڵ�ĺ�
}
void updown(int sum,int o)
{
    if(up[o])
    {
        //printf("***%d\n",o);
        int lso=o<<1;
        up[lso]+=up[o];
        up[lso|1]+=up[o];
        sto[lso]+=(sum-(sum>>1))*up[o];
        sto[lso|1]+=(sum>>1)*up[o];
        up[o]=0;
    }
}
int update(int t,int w,int o,int st,int en,int num)
{
    if(st<=t&&w<=en)//���ҵ���������ڵ�ǰ�ڵ�����䣬ֱ�ӷ��ص�ǰ�ڵ����������
    {
        if(num!=1<<29)
        {
            up[o]+=num;
            sto[o]+=(w-t+1)*num;
        }
        return sto[o];
    }
    //printf("%d %d %d\n",t,w,o);
    updown(w-t+1,o);
    int mid=(t+w)>>1;
    int lso=o<<1;
    int sum=0;
    if(st<=mid)
        sum+=update(t,mid,lso,st,en,num);
    if(mid<en)
        sum+=update(mid+1,w,lso|1,st,en,num);
    sto[o]=sto[lso]+sto[lso|1];
    return sum;
}
int main()
{
    while(~scanf("%d",&n))//�������ݵĸ���
    {
        init(1,n,1);
        scanf("%d",&q);//��Ҫ���ʵĴ���
        for(int i=1; i<=q; i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d",&x,&y);//���ʵ����䷶Χ
                printf("%d\n",update(1,n,1,x,y,1<<29));
            }
            else
            {
                scanf("%d%d%d",&x,&y,&z);
                update(1,n,1,x,y,z);
            }
        }
    }
    return 0;
}
