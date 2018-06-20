// 用邻接矩阵存储有向图，并输出各顶点的出度与入度
//#include<stdio.h>
//#include<string.h>
//
//#define MAXN 100 // 顶点个数最大值
//
//int Edge[MAXN + 5][MAXN + 5];// 邻接矩阵
//
//int main()
//{
//    int n, m;// 顶点个数、边数
//    while(scanf("%d%d", &n, &m), n + m)
//    {
//        memset(Edge, 0, sizeof(Edge));
//        int u, v;// 边的始边与终边
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            Edge[u][v] = 1;
//        }
//        for(int u = 1; u <= n; u ++)
//        {
//            int od = 0;// 顶点的出度
//            for(int v = 1; v <= n; v ++)
//                od += Edge[u][v];
//            printf("%d%c", od, u == n ? '\n' : ' ');
//        }
//        for(int v = 1; v <= n; v ++)
//        {
//            int id = 0; // 顶点的ru度
//            for(int u = 1; u <= n; u ++)
//                id += Edge[u][v];
//            printf("%d%c", id, v == n ? '\n' : ' ');
//        }
//    }
//    return 0;
//}

// Frogs's Neighborhood：Havel-Hakimi定理的应用
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//#define MAX 15
//
//using namespace std;
//
//struct vertex
//{
//    int degree;// 顶点的度
//    int index;// 顶点的下标
//} V[MAX];
//
//int cmp(const void *a, const void *b)
//{
//    return ((vertex *)b) -> degree - ((vertex *)a) -> degree;
//}
//
////bool cmp(struct vertex a, struct vertex b)
////{
////    return a.degree >= b.degree;
////}
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    while(T--)
//    {
//        int N;
//        scanf("%d", &N);
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%d", &V[i].degree);
//            V[i].index = i;
//        }
//        int Edge[MAX][MAX] = {0};
//        bool flag = true;
//        for(int i = 0; i < N && flag; i ++)
//        {
//            // 对 V 数组进行后 N - i个元素按非递增顺序排序
//            qsort(V + i, N - i, sizeof(vertex), cmp);
//            // sort(V + i, V + N, cmp);
//            int u = V[i].index;// 获取第 k 个顶点序号
//            int d1 = V[i].degree;
//            if(d1 > N - i - 1) flag = false;
//            for(int r = 1; r <= d1 && flag; r ++)
//            {
//                int v = V[i + r].index;// 后边 d1 个每个顶点的序号
//                if(V[i + r].degree <= 0) flag = false;
//                V[i + r].degree --;
//                Edge[u][v] = Edge[v][u] = 1;
//            }
//        }
//        if(flag)
//        {
//            puts("YES");
//            for(int i = 0; i < N; i ++)
//                for(int j = 0; j < N; j ++)
//                    printf("%d%c", Edge[i][j], j == N - 1 ? '\n': ' ');
//        }
//        else puts("NO");
//        if(T) puts("");
//    }
//    return 0;
//}

// 用邻接表存储有向图， 输出各顶点的出度和入度
#include<stdio.h>
#include<stdlib.h>

#define MAXN 100

struct ArcNode // 边结点
{
    int adjvex;// 有向边的另一个临界点的序号
    ArcNode *nextarc;// 指向下一个边结点的指针
};

struct VNode // 顶点
{
    int data;// 顶点信息
    ArcNode *head1;// 出边表的表头
    ArcNode *head2;// 入边表的表头
};

struct LGraph// 图的邻接表存储结点结构
{
    VNode vertexs[MAXN];// 顶点数组
    int vexnum, arcnum;// 顶点数和边数
};

LGraph lg;// 图（临界边存储）

void CreateLG()// 采用邻接表存储表示， 构造有向图
{
    ArcNode *pi;// 用来构造边链表的边结点指针
    for(int i = 0; i < lg.vexnum; i ++)// 初始化表头指针为空
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    int u, v; // 有向边的起点和终点
    for(int i = 0; i < lg.arcnum; i ++)
    {
        scanf("%d%d", &u, &v);
        u--, v--;
        pi = new ArcNode;// 假定有足够的空间
        pi -> adjvex = v;
        pi -> nextarc = lg.vertexs[u].head1; // 插入链表
        lg.vertexs[u].head1 = pi;
        pi = new ArcNode;
        pi -> adjvex = u;
        pi -> nextarc = lg.vertexs[v].head2;
        lg.vertexs[v].head2 = pi;
    }
}
// 释放图 G 邻接表各顶点的边链表中的所有边结点所占的存储空间
void DeleteLG()
{
    ArcNode *pi; // 用来指向边链表的各边结点的指针
    for(int i = 0; i < lg.vexnum; i ++)
    {
        pi = lg.vertexs[i].head1;
        // 释放第 i 个顶点出边表各边结点所占的存储空间
        while(pi != NULL)
        {
            lg.vertexs[i].head1 = pi -> nextarc;
            delete pi;
            pi = lg.vertexs[i].head1;
        }
        pi = lg.vertexs[i].head2;
        // 释放第 i 个顶点入边表各边结点所占的存储空间
        while(pi != NULL)
        {
            lg.vertexs[i].head2 = pi -> nextarc;
            delete pi;
            pi = lg.vertexs[i].head2;
        }
    }
}
int main()
{
    ArcNode *pi;// 用来遍历边链表的边结点指针
    // 首先输入顶点个数和边数
    while(scanf("%d%d", &lg.vexnum, &lg.arcnum), lg.vexnum)
    {
        CreateLG();
        for(int i = 0; i < lg.vexnum; i ++)
        {
            int od = 0;
            pi = lg.vertexs[i].head1;
            while(pi != NULL)
            {
                od ++;
                pi = pi -> nextarc;
            }
            printf("%d%c",od, i == lg.vexnum - 1 ? '\n' : ' ');
        }
        for(int i = 0; i < lg.vexnum; i ++)
        {
            int id = 0;
            pi = lg.vertexs[i].head2;
            while(pi != NULL)
            {
                id ++;
                pi = pi -> nextarc;
            }
            printf("%d%c",id, i == lg.vexnum - 1 ? '\n' : ' ');
        }
        DeleteLG();
    }
    return 0;
}
