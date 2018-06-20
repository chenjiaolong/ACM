// cdoj1324 ��ѧ���빫��
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

// num �ֿ�ĸ���
// belong[i] ��ʾi�����Ŀ��
// block ��ʾ��Ĵ�С
// l[i] ��ʾi��������˵��λ��
// r[i] ��ʾi�������Ҷ˵��λ��


int belong[maxn], l[maxn], r[maxn];
int block, N, num;

long long tree[maxn], Max[maxn];

void Build()
{
    block = sqrt(N);
    num = N / block;
    if(N % block) num ++;
    for(int i = 1; i <= num; i ++)
        l[i] = (i - 1) * block + 1, r[i] = i * block;
    r[num] = N;
    for(int i = 1; i <= N; i ++) belong[i] = (i - 1) / block + 1;

    for(int i = 1; i <= num; i ++)
        for(int j = l[i]; j <= r[i]; j ++)
            Max[i] = max(Max[i], tree[j]);
}
void update(int p, int x)
{
    tree[p] += x;
    Max[belong[p]] = max(Max[belong[p]], tree[p]);
}
long long query(int L, int R)
{
    long long ans = 0;
    if(belong[L] == belong[R])
    {
        for(int i = L; i <= R; i ++)
            ans = max(ans, tree[i]);
        return ans;
    }
    for(int i = L; i <= r[belong[L]]; i ++) ans = max(ans, tree[i]);
    for(int i = belong[L] + 1; i < belong[R]; i ++) ans = max(ans, Max[i]);
    for(int i = l[belong[R]]; i <= R; i ++) ans = max(ans, tree[i]);
    return ans;
}
int main()
{
    int Q;
    scanf("%d%d", &N, &Q);
    Build();
    int t;
    for(int i = 1; i <= Q; i ++)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            int p, x;
            scanf("%d%d", &p, &x);
            update(p, x);
        }
        else
        {
            int L, R;
            scanf("%d%d", &L, &R);
            printf("%lld\n", query(L, R));
        }
    }
    return 0;
}
