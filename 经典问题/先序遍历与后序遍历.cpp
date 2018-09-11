// 51Nod 1832
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];
int cnt;
void calc(int l1, int r1, int l2, int r2)
{
    int i;
    if(l1 >= r1)  return;
    for(i = l2; i <= r2 - 1; i ++)
        if(a[l1 +1] == b[i]) break;
    if(i == r2-1)  cnt++;
    calc(l1 + 1, l1 + 1 + (i - l2), l2, i);
    calc(l1 + 1 + (i - l2) + 1, r1, i + 1, r2 - 1);
}

string Mult(string s, int x)  //大数乘以整形数
{
    reverse(s.begin(), s.end());
    int cmp = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        cmp = (s[i] - '0') * x + cmp;
        s[i] = (cmp % 10 + '0');
        cmp /= 10;
    }
    while(cmp)
    {
        s += (cmp % 10 + '0');
        cmp /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string Pow(int n)
{
    string s = "1";
    for(int i = 0; i < n; i ++) s = Mult(s, 2);
    return s;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i ++) scanf("%d", &b[i]);
        cnt = 0;
        calc(0, n - 1, 0, n - 1);
        printf("%s\n", Pow(cnt).c_str());
    }
    return 0;
}

