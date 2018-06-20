// hdu5126 stars
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 5e4 + 100;
const int maxm = 2e5 + 100;

using namespace std;

struct node
{
    int x, y, z;
    int op;
    int id;
    node(int xx, int yy, int zz, int oo, int ii) : x(xx), y(yy), z(zz), op(oo), id(ii) {  }
    node() {  }
};

vector<node >ope, ope2, ope3;
vector<int > allz;

bool cmp(node a, node b)
{
    if(a.x == b.x) return a.id < b.id;
    return a.x < b.x;
}
bool CMP(node a, node b)
{
    if(a.y == b.y) return a.id < b.id;
    return a.y < b.y;
}

int tree[maxm];
int ans[maxn];
bool isQuery[maxn];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int v)
{
    while(i <= maxm)
    {
       tree[i] += v;
       i += lowbit(i);
    }
}

int query(int x)
{
    int sum = 0;
    while(x)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void Stars()
{
    for(int i = 0; i < ope3.size(); i ++)
    {
        if(ope3[i].op == 0) update(ope3[i].z, 1); // 加点
        else
        {
            int t = query(ope3[i].z);
            ans[ope3[i].id] += t * ope3[i].op;
        }
    }
    for(int i = 0; i < ope3.size(); i ++)
        if(ope3[i].op == 0) update(ope3[i].z, -1);
}

void CDQ2(int l, int r)
{
    if(l >= r) return ;
    int mid = (l + r) >> 1;
    CDQ2(l, mid);
    ope3.clear();
    for(int i = l; i <= mid; i ++)
        if(ope2[i].op == 0) ope3.push_back(ope2[i]);
    for(int i = mid + 1; i <= r; i ++)
        if(ope2[i].op != 0) ope3.push_back(ope2[i]);
    sort(ope3.begin(), ope3.end(), CMP);
    Stars();
    CDQ2(mid + 1, r);
}

void CDQ(int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid);
    ope2.clear();
    for(int i = l; i <= mid; i ++)
        if(ope[i].op == 0) ope2.push_back(ope[i]); // 前半截加点操作对后半截的询问影响
    for(int i = mid + 1; i <= r; i ++)
        if(ope[i].op != 0) ope2.push_back(ope[i]); // 询问
    sort(ope2.begin(), ope2.end(), cmp);
    CDQ2(0, ope2.size() - 1);
    CDQ(mid + 1, r);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for(int i = 0; i < maxm; i ++)
            tree[i] = 0;
        for(int i = 0; i < maxn; i ++)
        {
            isQuery[i] = false;
            ans[i] = 0;
        }
        ope.clear();
        allz.clear();
        int Q;
        scanf("%d", &Q);
        for(int i = 0; i < Q; i ++)
        {
            int A;
            scanf("%d", &A);
            if(A == 1)
            {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                ope.push_back(node(x, y, z, 0, i));
                allz.push_back(z);
            }
            else
            {
                isQuery[i] = true;
                int x1, y1, z1, x2, y2, z2;
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                ope.push_back(node(x1 - 1, y1 - 1, z1 - 1, -1, i));
                ope.push_back(node(x1 - 1, y1 - 1, z2, 1, i));
                ope.push_back(node(x1 - 1, y2, z1 - 1, 1, i));
                ope.push_back(node(x2, y1 - 1, z1 - 1, 1, i));
                ope.push_back(node(x1 - 1, y2, z2, -1, i));
                ope.push_back(node(x2, y1 - 1, z2, -1, i));
                ope.push_back(node(x2, y2, z1 - 1, -1, i));
                ope.push_back(node(x2, y2, z2, 1, i));
                allz.push_back(z1 - 1);
                allz.push_back(z2);
            }
        }
        sort(allz.begin(), allz.end());
        auto it = unique(allz.begin(), allz.end());
        allz.resize(distance(allz.begin(), it));
        for(int i = 0; i < ope.size(); i ++)
            ope[i].z  = lower_bound(allz.begin(), allz.end(), ope[i].z) - allz.begin() + 1;
        CDQ(0, ope.size() - 1);
        for(int i = 0; i < Q; i ++)
            if(isQuery[i]) printf("%d\n", ans[i]);
    }
    return 0;
}


//#include <ctime>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//double random(double start, double end)
//{
//    return start+(end-start)*rand()/(RAND_MAX+1.0);
//}
//
//int main()
//{
//    freopen("test10.in", "w", stdout);
//    srand((unsigned)time(nullptr));
//    int Q = 50000;
//    printf("%d\n", Q);
//    while(Q -- )
//    {
//        int op = 1 + rand() % 2;
//        if(op == 1)
//        {
//            int x = random(1, 1000001);
//            int y = random(1, 1000001);
//            int z = random(1, 1000001);
//            printf("%d %d %d %d\n", op, x, y, z);
//        }
//        else
//        {
//            int x1 = random(1, 1000000);
//            int y1 = random(1, 1000000);
//            int z1 = random(1, 1000000);
//            int x2 = random(x1, 1000001);
//            int y2 = random(y1, 1000001);
//            int z2 = random(z1, 1000001);
//            printf("%d %d %d %d %d %d %d\n", op, x1, y1, z1, x2, y2, z2);
//        }
//    }
//    return 0;
//}
