#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int tree[30][maxn]; // 表示每层每个位置的值
int sorted[maxn]; // 已排序的数
int toleft[30][maxn]; // toleft[p][i] 表示第i层从第1到i有多少个数分入右边

void Init(int l, int r, int dep)
{
    if(l == r) return ;
    int mid = (l + r) >> 1;
    int same = mid - l + 1; // 表示等于中间值而且被分入左边的个数
    for(int i = l; i <= r; i ++)
        if(tree[dep][i] < sorted[mid]) same--;
    int lpos = l;
    int rpos = mid + 1;
    for(int i = l; i <= r; i ++)
    {
        if(tree[dep][i] < sorted[mid]) // 比中间数小，被放入左边
        tree[dep + 1][lpos ++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep + 1][lpos ++] = tree[dep][i];
            same --;
        }
        else //比中间值的大分入写入右边
        tree[dep + 1][rpos ++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l - 1] + lpos - l; // 从1到i放左边个数
    }
    Init(l, mid, dep + 1);
    Init(mid + 1, r, dep + 1);
}
// 查询区间第k大的数，[L, R] 是大区间， [l, r]是要查询的小区间
int Query(int L, int R, int l, int r, int dep, int k)
{
    if(l == r) return tree[dep][l];
    int mid = (L + R) >> 1;
    int cnt = toleft[dep][r] - toleft[dep][l - 1]; // [l, r]中位于左边的个数
    if(cnt >= k)
    {
        // L + 要查询的区间前被放在左边的个数
        int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
        // 左端点加上查询区间会放在左边的个数
        int newr = newl + cnt - 1;
        return Query(L, mid, newl, newr, dep + 1, k);
    }
    else
    {
        int newr = r + toleft[dep][R] - toleft[dep][r];
        int newl = newr - (r - l - cnt);
        return Query(mid + 1, R, newl, newr, dep + 1, k - cnt);
    }
}

int main()
{
    int T;
    int n, m;
    int s, t, k;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        memset(tree, 0, sizeof(tree));
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &tree[0][i]);
            sorted[i] = tree[0][i];
        }
        sort(sorted + 1, sorted + n + 1);
        Init(1, n, 0);
        while(m --)
        {
            scanf("%d%d%d", &s, &t, &k);
            printf("%d\n", Query(1, n, s, t, 0, k));
        }
    }
    return 0;
}
