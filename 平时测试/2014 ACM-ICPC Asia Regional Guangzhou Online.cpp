// hdu 5023 A Corrupt Mayor's Performance Art
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int maxn = 1e6 + 100;
//
//struct node
//{
//    int l, r;
//    int color;
//    bool v;
//} sto[maxn << 2];
//
//bool vis[35];
//int ans[maxn];
//int cur;
//
//void PushDown(int rt)
//{
//    if(!sto[rt].v) return;
//    sto[rt << 1].color = sto[rt << 1 | 1].color = sto[rt].color;
//    sto[rt].v = false;
//    sto[rt << 1].v = true;
//    sto[rt << 1 | 1].v = true;
//}
//void Init(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r, sto[rt].color = 2, sto[rt].v = true;
//    if(l == r) return ;
//    int mid = (l + r) >> 1;
//    Init(lson);
//    Init(rson);
//}
//
//void update(int l, int r, int rt, int v)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].color = v;
//        sto[rt].v = true;
//        return ;
//    }
//    PushDown(rt);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, v);
//    else if(l > mid) update(l, r, rt << 1 | 1, v);
//    else
//    {
//        update(lson, v);
//        update(rson, v);
//    }
//}
//
//void query(int l, int r, int rt)
//{
//    if(sto[rt].l == l && sto[rt].r == r && sto[rt].v)
//    {
//        if(!vis[sto[rt].color])
//        {
//            ans[cur++] = sto[rt].color;
//            vis[sto[rt].color] = true;
//        }
//        return ;
//    }
//    if(sto[rt].l == sto[rt].r) return ;
//    PushDown(rt);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) query(l, r, rt << 1);
//    else if(l > mid) query(l, r, rt << 1 | 1);
//    else
//    {
//        query(lson);
//        query(rson);
//    }
//}
//
//int main()
//{
//    int N, M;
//    while(scanf("%d%d", &N, &M), N)
//    {
//        Init(1, N, 1);
//        char str[5];
//        int a, b, c;
//        while(M --)
//        {
//            scanf("%s", str);
//            if(str[0] == 'P')
//            {
//                scanf("%d%d%d", &a, &b, &c);
//                update(a, b, 1, c);
//            }
//            else
//            {
//                scanf("%d%d", &a, &b);
//                memset(vis, false, sizeof(vis));
//                cur = 0;
//                query(a, b, 1);
//                sort(ans, ans + cur);
//                for(int i = 0; i < cur; i ++)
//                    printf("%d%c", ans[i], i == cur - 1 ? '\n' : ' ');
//            }
//        }
//    }
//    return 0;
//}

// hdu5024 Wang Xifeng's Little Plot
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

char map[105][105];
int n;

int dir[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0},{1, -1}};

int BFS(int x, int y)
{
    int d[10] = {0};
    for(int i = 0; i < 8; i ++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];

        while(xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] != '#')
        {
            d[i] ++;
            xx += dir[i][0];
            yy += dir[i][1];
        }

    }
    int sum = 0;
    for(int i = 0; i < 8; i ++)
        sum = max(sum, d[i] + d[(i + 2) % 8] + 1);
    return sum;
}
int main()
{
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i ++)
            scanf("%s", map[i]);
        int ans = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(map[i][j] == '.') ans = max(ans, BFS(i, j));
        printf("%d\n", ans);
    }
    return 0;
}
