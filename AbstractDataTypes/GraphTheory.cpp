// ���ڽӾ���洢����ͼ�������������ĳ��������
//#include<stdio.h>
//#include<string.h>
//
//#define MAXN 100 // ����������ֵ
//
//int Edge[MAXN + 5][MAXN + 5];// �ڽӾ���
//
//int main()
//{
//    int n, m;// �������������
//    while(scanf("%d%d", &n, &m), n + m)
//    {
//        memset(Edge, 0, sizeof(Edge));
//        int u, v;// �ߵ�ʼ�����ձ�
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            Edge[u][v] = 1;
//        }
//        for(int u = 1; u <= n; u ++)
//        {
//            int od = 0;// ����ĳ���
//            for(int v = 1; v <= n; v ++)
//                od += Edge[u][v];
//            printf("%d%c", od, u == n ? '\n' : ' ');
//        }
//        for(int v = 1; v <= n; v ++)
//        {
//            int id = 0; // �����ru��
//            for(int u = 1; u <= n; u ++)
//                id += Edge[u][v];
//            printf("%d%c", id, v == n ? '\n' : ' ');
//        }
//    }
//    return 0;
//}

// Frogs's Neighborhood��Havel-Hakimi�����Ӧ��
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
//    int degree;// ����Ķ�
//    int index;// ������±�
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
//            // �� V ������к� N - i��Ԫ�ذ��ǵ���˳������
//            qsort(V + i, N - i, sizeof(vertex), cmp);
//            // sort(V + i, V + N, cmp);
//            int u = V[i].index;// ��ȡ�� k ���������
//            int d1 = V[i].degree;
//            if(d1 > N - i - 1) flag = false;
//            for(int r = 1; r <= d1 && flag; r ++)
//            {
//                int v = V[i + r].index;// ��� d1 ��ÿ����������
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

// ���ڽӱ�洢����ͼ�� ���������ĳ��Ⱥ����
#include<stdio.h>
#include<stdlib.h>

#define MAXN 100

struct ArcNode // �߽��
{
    int adjvex;// ����ߵ���һ���ٽ������
    ArcNode *nextarc;// ָ����һ���߽���ָ��
};

struct VNode // ����
{
    int data;// ������Ϣ
    ArcNode *head1;// ���߱�ı�ͷ
    ArcNode *head2;// ��߱�ı�ͷ
};

struct LGraph// ͼ���ڽӱ�洢���ṹ
{
    VNode vertexs[MAXN];// ��������
    int vexnum, arcnum;// �������ͱ���
};

LGraph lg;// ͼ���ٽ�ߴ洢��

void CreateLG()// �����ڽӱ�洢��ʾ�� ��������ͼ
{
    ArcNode *pi;// �������������ı߽��ָ��
    for(int i = 0; i < lg.vexnum; i ++)// ��ʼ����ͷָ��Ϊ��
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    int u, v; // ����ߵ������յ�
    for(int i = 0; i < lg.arcnum; i ++)
    {
        scanf("%d%d", &u, &v);
        u--, v--;
        pi = new ArcNode;// �ٶ����㹻�Ŀռ�
        pi -> adjvex = v;
        pi -> nextarc = lg.vertexs[u].head1; // ��������
        lg.vertexs[u].head1 = pi;
        pi = new ArcNode;
        pi -> adjvex = u;
        pi -> nextarc = lg.vertexs[v].head2;
        lg.vertexs[v].head2 = pi;
    }
}
// �ͷ�ͼ G �ڽӱ������ı������е����б߽����ռ�Ĵ洢�ռ�
void DeleteLG()
{
    ArcNode *pi; // ����ָ�������ĸ��߽���ָ��
    for(int i = 0; i < lg.vexnum; i ++)
    {
        pi = lg.vertexs[i].head1;
        // �ͷŵ� i ��������߱���߽����ռ�Ĵ洢�ռ�
        while(pi != NULL)
        {
            lg.vertexs[i].head1 = pi -> nextarc;
            delete pi;
            pi = lg.vertexs[i].head1;
        }
        pi = lg.vertexs[i].head2;
        // �ͷŵ� i ��������߱���߽����ռ�Ĵ洢�ռ�
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
    ArcNode *pi;// ��������������ı߽��ָ��
    // �������붥������ͱ���
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
