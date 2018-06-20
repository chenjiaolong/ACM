#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

struct node
{
    ll s, n; // s: 各数位交错和 n: 满足条件的个数
};
node dp[21][20][400]; // [长度][以那个数作为开头][该数的数位交替和]
int bits[21]; // 存放一个数的各位，低到高存放在0到20
ll base[21]; // 每一数位的基准

// len 数位长度，dig是首个数字，begin_zero表示从高位到当前位是否全部为0，limit表示下一位枚举是否有限制（bit[len - 2] 或9），sum表示要求的数字和
node DFS(int len, int dig, bool begin_zero, bool limit, int sum)
{
    node t;
    t.s = t.n = 0;
    // 边界值
    if(len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200) return t;

    // 返回以后的dp结果，即记忆化搜索
    if(!limit && dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
        return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];

    // 长度只有一位，就不需要枚举下一位了，直接讨论返回即可
    if(len == 1)
    {
        if (dig != sum) return t;
        t.n = 1, t.s = sum;
        return t;
    }
    // 开始枚举下一位的数字
    int end = limit ? bits[len - 2] : 9; // 下一位数字的最大值
    int New = dig - sum;
    node tmp;
    for(int j = 0; j <= end; j ++)
    {
        // 前面都是0，接下来的就由当前位决定j是否为0
        if(begin_zero)
            tmp = DFS(len - 1, j, j == 0, limit && (j == end), sum);
        else // 前面不全是0
            tmp = DFS(len - 1, j, false, limit && (j == end), New);
        // 将tmp的值累加到t上
        t.n += tmp.n;
        // 计算满足条件的长度为len的data[len]所有数的和，tmp是长度为i - 1的data[len - 1]所有数的和
        // 每一个：data[len] = dig * base[len] + data[len - 1]且共有n个
        // t.s = t.s + tmp.n * (dig * base[len]) + tmp.s增加%mod就得到下面的结果
        t.s = ((t.s + tmp.s) % mod + ((tmp.n * dig) % mod * base[len]) % mod) % mod;
    }
    // 当长度为len，且以dig开头的，数位和为sum的所有结果都计算完成，才将其进行存储
    if(!limit) dp[len][dig + (begin_zero ? 0 : 10)][sum + 200] = t;
    // dig + (begin_zero ? 0 : 10) 用来区分两种状态，（1. 前导都为0；2. 前导包含其它数）
    return t;
}
int Solve(ll n, int k)
{
    if (n <= 0) return 0;
    int l = 0;
    for(int i = 0; i < 21; i ++) bits[i] = 0;
    // 将n的每一位从低到高存放到bits[0]到bits[l]中
    while(n)
    {
        bits[l ++] = n % 10;
        n /= 10;
    }
    // 从l + 1开始，比n的长度大1，并且第l + 1位数置位0
    return DFS(l + 1, 0, true, true, k).s;
}

void Init()
{
    node t;
    t.n = -1;
    t.s = 0;
    for(int i = 0; i < 21; i ++) // 长度
        for(int j = 0; j < 20; j ++) // 第i为的取值
            for(int k = 0; k < 400; k ++) // i到0所有位上的交错和 + 200
                dp[i][j][k] = t;
    base[1] = 1;
    for(int i = 2; i < 21; i ++) // base作为基准数，、
        base[i] = base[i - 1] * 10 % mod;
}
int main()
{
    Init();
    ll l, r, k;
    cin >> l >> r >> k;
    int ans = (Solve(r, k) - Solve(l, k) + mod) % mod;
    cout << ans << endl;
    return 0;
}
