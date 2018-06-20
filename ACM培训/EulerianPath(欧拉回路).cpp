#include <bits/stdc++.h>

using namespace std;

int n, m;
bool g[1010][1010];
stack<int>s;

void DFS(int u)
{
    s.push(u);
    for(int v = 1; v <= n; v ++)
        if(g[u][v])
        {
            g[u][v] = g[v][u] = false;
            DFS(v);
            break;
        }
}

void Fleury(int st)
{
    while(!s.empty()) s.pop();
    s.push(st);
    bool first = true;
    while(s.size())
    {
        int u = s.top();
        s.pop();
        bool flag = false;
        for(int v = 1; v <= n; v ++)
            if(g[u][v]) // �ж��Ƿ�������
            {
                flag = true;
                break;
            }
        if(flag) DFS(u);
        else if(first)
        {
            printf("%d", u);
            first = false;
        }
        else printf(" %d", u);
    }
    puts("");
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(g, false, sizeof(g)); // �������
        int u, v;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1; // u -> v, v -> u������
        }
        int st = 1, num = 0; // �����㣬���������
        for(int i = 1; i <= n; i ++)
        {
            int k = 0;
            for(int j = 1; j <= n; j ++)
                k += g[i][j]; // �ж϶����ж��ٸ�
            if(k & 1) // �����������Ļ�
            {
                st = i;
                num ++;
            }
        }
        if(num == 0 || num == 2) // ����ŷ��ͨ·
            Fleury(st);
        else puts("NO");
    }
    return 0;
}

//9 12
//1 9
//1 5
//9 8
//5 8
//5 3
//5 4
//3 2
//2 4
//4 6
//6 7
//7 8
//6 8

//4 5 8 7 6 8 9 1 5 3 2 4 6
