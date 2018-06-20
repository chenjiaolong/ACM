// N表示要计算的 n 开根号
#include<stdio.h>
#include<tr1/unordered_map>
using namespace std :: tr1;
const int N = 1e6;
int tot, p[N], f[N];
bool v[N];
unordered_map<int, int>T[200];
// the number of natural numbers not great than m which are divisible by no p[i](1 <= i <= n)
// Phi(m, n) = Phi(m, n - 1) - Phi(m / p[n], n - 1)
int cal(int m, int n)
{
    if(!n) return m;
    unordered_map<int, int> :: iterator x = T[n].find(m);
    if(x != T[n].end()) return x -> second;
    return T[n][m] = cal(m, n - 1) - cal(m / p[n - 1], n - 1);
}
// number of prime less than or equal to n
int Pi(int n)
{
    if(n < N) return f[n];
    int b = 0;
    while(p[b] * p[b] * p[b] <= n) b++;
    int t = cal(n, b) + b - 1;
    for(int i = b; p[i] * p[i] <= n; i++) t -= f[n / p[i]] - i;
    return t;
}
int main()
{
    int i;
    for(i = 2; i < N; i++)
        if(!v[i]) f[p[tot++] = i] = 1;
    f[i] += f[i - 1];
    for(int j = 0; j < tot && i * p[j] < N; j++)
    {
        v[i * p[j]] = 1;
        if(i % p[j] == 0) break;
    }
    return 0;

}
