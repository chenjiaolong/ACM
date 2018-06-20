// CDOJ 1330 柱爷与远古法阵
#include<bits/stdc++.h>

using namespace std;

const int maxn = 305;
const long double eps = 1e-14;
long double a[maxn][maxn];
// 输入挂
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch <'0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n = read();
    int m = read();
    int f[maxn];
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) f[read()] = read();

    // 消元
    for(int i = 1; i < n; i ++)
    {
        a[i][i] = 6;
        if(f[i] != i) a[i][f[i]] = -6;
        else
        {
            a[i][n + 1] = 6;
            for(int j = 1; j <= 6; j ++)
                if(i + j <= n) a[i][i + j] -= 1.0;
                else a[i][i] -= 1.0;
        }
    }
    // 往回带
    a[n][n] = 1.0;
    a[n][n + 1] = 0;
    for(int i = 1; i <= n; i ++)
    {
        int p = i;
        for(int j = i + 1;  j <= n; j ++)
            if(fabs(a[j][i] > eps)) p = j;
        if(fabs(a[p][i]) > eps)
        {
            for(int j = i; j <= n + 1; j ++)
                swap(a[i][j], a[p][j]);
            for(int j = i + 1; j <= n; j++)
                if(fabs(a[j][i]) > eps)
                {
                    long double k = a[j][i] / a[i][i];
                    for(int t = i; t <= n + 1; t ++)
                        a[j][t] -= a[i][t] * k;
                }
        }
    }
    // 输出结果
    for(int i = n; i >= 1; i--)
    {
        for(int j = i + 1; j <= n; j ++)
            if(fabs(a[i][j]) > eps) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        if(fabs(a[i][i]) <= eps && fabs(a[i][n + 1]) > eps)
        {
            printf("-1\n");
            return 0;
        }
        a[i][n + 1] /= a[i][i];
    }
    printf("%.12Lf\n", a[1][n + 1]);
    // setiosflags(ios :: fixed);
    cout << setprecision(12) << a[1][n + 1] << endl;
    return 0;
}
