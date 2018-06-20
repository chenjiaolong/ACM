// BZOJ1251 –Ú¡–÷’Ω·’ﬂ
// http://codevs.cn/problem/4655/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 100;
const int inf = -0x7fffffff;

struct Splay_tree
{
    struct node
    {
        int val, Max, add, Size, son[2];
        bool rev;
        void Init(int _val)
        {
            val = Max = _val;
            Size = 1;
            add = rev = son[0] = son[1] = 0;
        }
    }T[maxn];
    int fa[maxn], root;
    void PushUp(int x)
    {
        T[x].Max = T[x].val, T[x].Size = 1;
        if(T[x].son[0])
        {
            T[x].Max = max(T[x].Max, T[T[x].son[0]].Max);
            T[x].Size += T[T[x].son[0]].Size;
        }
        if(T[x].son[1])
        {
            T[x].Max = max(T[x].Max, T[T[x].son[1]].Max);
            T[x].Size += T[T[x].son[1]].Size;
        }
    }
    void PushDown(int x)
    {
        if(x == 0) return ;
        if(T[x].add)
        {
            if(T[x].son[0])
            {
                T[T[x].son[0]].val += T[x].add;
                T[T[x].son[0]].Max += T[x].add;
                T[T[x].son[0]].add += T[x].add;
            }
            if(T[x].son[1])
            {
                T[T[x].son[1]].val += T[x].add;
                T[T[x].son[1]].Max += T[x].add;
                T[T[x].son[1]].add += T[x].add;
            }
            T[x].add = 0;
        }
        if(T[x].rev)
        {
            if(T[x].son[0]) T[T[x].son[0]].rev ^= 1;
            if(T[x].son[1]) T[T[x].son[1]].rev ^= 1;
            swap(T[x].son[0], T[x].son[1]);
            T[x].rev = 0;
        }
    }
    void Rotate(int x, int kind)
    {
        int y = fa[x], z = fa[y];
        T[y].son[!kind] = T[x].son[kind],fa[T[x].son[kind]] = y;
        T[x].son[kind] = y, fa[y] = x;
        T[z].son[T[z].son[1] == y] = x, fa[x] = z;
        PushUp(y);
    }
    /*void Zig(int x)
    {
        int y = fa[x];
        ch[y][0] = ch[x][1];
        fa[ch[x][1]] = y;
        ch[x][1] = y;
        fa[x] = fa[y];
        if(y == ch[fa[y]][0])
            ch[fa[y]][0] = x;
        else if(y == cha[fa[y][1])
            ch[fa[y]][1] = x;
        fa[y] = x;
        PushUp(y);
        if(y == root) root = x;
    }
    void Zag(int x)
    {
        int y = fa[x];
        ch[y][1] = ch[x][0];
        fa[ch[x][0]] = y;
        ch[x][0] = y;
        fa[x] = fa[y];
        if(y == ch[fa[y]][0])
            ch[fa[y]][0] = x;
        else if(y == cha[fa[y][1])
            ch[fa[y]][1] = x;
        fa[y] = x;
        PushUp(y);
        if(y == root) root = x;
    }
    */
    void Splay(int x, int goal)
    {
        if(x == goal) return ;
        while(fa[x] != goal)
        {
            int y = fa[x], z = fa[y];
            PushDown(z);
            PushDown(y);
            PushDown(x);
            int rx = T[y].son[0] == x, ry = T[z].son[0] == y;
            if(z == goal) Rotate(x, rx);
            else
            {
                if(rx == ry) Rotate(y, ry);
                else Rotate(x, rx);
                Rotate(x, ry);
            }

        }
        PushUp(x);
        if(goal == 0) root = x;
    }
    int Select(int pos)
    {
        int u = root;
        PushDown(u);
        while(T[T[u].son[0]].Size != pos)
        {
            if(pos < T[T[u].son[0]].Size) u = T[u].son[0];
            else
            {
                pos -= T[T[u].son[0]].Size + 1;
                u = T[u].son[1];
            }
            PushDown(u);
        }
        return u;
    }
    void update(int L, int R, int val)
    {
        int u = Select(L - 1), v = Select(R + 1);
        Splay(u, 0);
        Splay(v, u);

        T[T[v].son[0]].Max += val;
        T[T[v].son[0]].val += val;
        T[T[v].son[0]].add += val;
    }
    void Reverse(int L, int R)
    {
        int u = Select(L - 1), v = Select(R + 1);
        Splay(u, 0);
        Splay(v, u);
        T[T[v].son[0]].rev ^= 1;
    }
    int Query(int L, int R)
    {
        int u = Select(L - 1), v = Select(R + 1);
        Splay(u, 0);
        Splay(v, u);
        return T[T[v].son[0]].Max;
    }
    int Build(int L, int R)
    {
        if(L > R) return 0;
        if(L == R) return L;
        int mid = (L + R) >> 1, sL, sR;
        T[mid].son[0] = sL = Build(L, mid - 1);
        T[mid].son[1] = sR = Build(mid + 1, R);
        fa[sL] = fa[sR] = mid;
        PushUp(mid);
        return mid;
    }
    void Init(int n)
    {
        T[0].Init(inf), T[1].Init(inf), T[n + 2].Init(inf);
        for(int i = 2; i <= n + 1; i ++) T[i].Init(0);
        root = Build(1, n + 2), fa[root] = 0;
        fa[0] = 0, T[0].son[1] = root, T[0].Size = 0;
    }
}Tree;


int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M) != EOF)
    {
        Tree.Init(N);
        int K, L, R, V;
        for(int i = 0; i < M; i ++)
        {
            scanf("%d", &K);
            if(K == 1)
            {
                scanf("%d%d%d", &L, &R, &V);
                Tree.update(L, R, V);
            }
            else if(K == 2)
            {
                scanf("%d%d", &L, &R);
                Tree.Reverse(L, R);
            }
            else
            {
                scanf("%d%d", &L, &R);
                printf("%d\n", Tree.Query(L, R));
            }
        }
    }
    return 0;
}
