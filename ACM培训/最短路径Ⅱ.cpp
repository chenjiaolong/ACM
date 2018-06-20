//#include <bits/stdc++.h>
//
//using namespace std;
//const int maxn = 205;
//
//vector<pair<int, int>>E[maxn];
//
//int n, m;
//int d[maxn];
//bool inq[maxn];
//
//void Init()
//{
//    for(int i = 0; i < maxn; i ++)
//    {
//        E[i].clear();
//        inq[i] = false;
//        d[i] = 1e9;
//    }
//}
//
//int main()
//{
//    while(cin >> n >> m)
//    {
//        Init();
//        for(int i = 0; i < m; i ++)
//        {
//            int x, y, z;
//            scanf("%d%d%d", &x, &y, &z);
//            E[x].push_back(make_pair(y, z));
//            E[y].push_back(make_pair(x, z));
//        }
//        int s, t;
//        scanf("%d%d", &s, &t);
//        queue<int>Q;
//        Q.push(s), d[s] = 0, inq[s] = true;
//        while(!Q.empty())
//        {
//            int now = Q.front();
//            Q.pop();
//            inq[now] = false;
//            for(int i = 0; i < E[now].size(); i ++)
//            {
//                int v = E[now][i].first;
//                if(d[v] > d[now] + E[now][i].second)
//                {
//                    d[v] = d[now] + E[now][i].second;
//                    if(inq[v]) continue;
//                    Q.push(v);
//                    inq[v] = true;
//                }
//            }
//        }
//        if(d[t] == 1e9) puts("-1");
//        else printf("%d\n", d[t]);
//    }
//    return 0;
//}


#include <bits/stdc++.h>

using namespace std;
const int maxn = 205;

vector<pair<int, int>>E[maxn];

int n, m;
int d[maxn];

void Init()
{
    for(int i = 0; i < maxn; i ++)
    {
        E[i].clear();
        d[i] = 1e9;
    }
}

int main()
{
    while(cin >> n >> m)
    {
        Init();
        for(int i = 0; i < m; i ++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            E[x].push_back(make_pair(y, z));
            E[y].push_back(make_pair(x, z));
        }
        int s, t;
        scanf("%d%d", &s, &t);
        priority_queue<pair<int, int>>Q;
        Q.push(make_pair(-d[s], s)), d[s] = 0;
        while(!Q.empty())
        {
            int now = Q.top().second;
            Q.pop();
            for(int i = 0; i < E[now].size(); i ++)
            {
                int v = E[now][i].first;
                if(d[v] > d[now] + E[now][i].second)
                {
                    d[v] = d[now] + E[now][i].second;
                    Q.push(make_pair(-d[v], v));
                }
            }
        }
        if(d[t] == 1e9) puts("-1");
        else printf("%d\n", d[t]);
    }
    return 0;
}
