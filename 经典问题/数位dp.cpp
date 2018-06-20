#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

struct node
{
    ll s, n; // s: ����λ����� n: ���������ĸ���
};
node dp[21][20][400]; // [����][���Ǹ�����Ϊ��ͷ][��������λ�����]
int bits[21]; // ���һ�����ĸ�λ���͵��ߴ����0��20
ll base[21]; // ÿһ��λ�Ļ�׼

// len ��λ���ȣ�dig���׸����֣�begin_zero��ʾ�Ӹ�λ����ǰλ�Ƿ�ȫ��Ϊ0��limit��ʾ��һλö���Ƿ������ƣ�bit[len - 2] ��9����sum��ʾҪ������ֺ�
node DFS(int len, int dig, bool begin_zero, bool limit, int sum)
{
    node t;
    t.s = t.n = 0;
    // �߽�ֵ
    if(len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200) return t;

    // �����Ժ��dp����������仯����
    if(!limit && dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
        return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];

    // ����ֻ��һλ���Ͳ���Ҫö����һλ�ˣ�ֱ�����۷��ؼ���
    if(len == 1)
    {
        if (dig != sum) return t;
        t.n = 1, t.s = sum;
        return t;
    }
    // ��ʼö����һλ������
    int end = limit ? bits[len - 2] : 9; // ��һλ���ֵ����ֵ
    int New = dig - sum;
    node tmp;
    for(int j = 0; j <= end; j ++)
    {
        // ǰ�涼��0���������ľ��ɵ�ǰλ����j�Ƿ�Ϊ0
        if(begin_zero)
            tmp = DFS(len - 1, j, j == 0, limit && (j == end), sum);
        else // ǰ�治ȫ��0
            tmp = DFS(len - 1, j, false, limit && (j == end), New);
        // ��tmp��ֵ�ۼӵ�t��
        t.n += tmp.n;
        // �������������ĳ���Ϊlen��data[len]�������ĺͣ�tmp�ǳ���Ϊi - 1��data[len - 1]�������ĺ�
        // ÿһ����data[len] = dig * base[len] + data[len - 1]�ҹ���n��
        // t.s = t.s + tmp.n * (dig * base[len]) + tmp.s����%mod�͵õ�����Ľ��
        t.s = ((t.s + tmp.s) % mod + ((tmp.n * dig) % mod * base[len]) % mod) % mod;
    }
    // ������Ϊlen������dig��ͷ�ģ���λ��Ϊsum�����н����������ɣ��Ž�����д洢
    if(!limit) dp[len][dig + (begin_zero ? 0 : 10)][sum + 200] = t;
    // dig + (begin_zero ? 0 : 10) ������������״̬����1. ǰ����Ϊ0��2. ǰ��������������
    return t;
}
int Solve(ll n, int k)
{
    if (n <= 0) return 0;
    int l = 0;
    for(int i = 0; i < 21; i ++) bits[i] = 0;
    // ��n��ÿһλ�ӵ͵��ߴ�ŵ�bits[0]��bits[l]��
    while(n)
    {
        bits[l ++] = n % 10;
        n /= 10;
    }
    // ��l + 1��ʼ����n�ĳ��ȴ�1�����ҵ�l + 1λ����λ0
    return DFS(l + 1, 0, true, true, k).s;
}

void Init()
{
    node t;
    t.n = -1;
    t.s = 0;
    for(int i = 0; i < 21; i ++) // ����
        for(int j = 0; j < 20; j ++) // ��iΪ��ȡֵ
            for(int k = 0; k < 400; k ++) // i��0����λ�ϵĽ���� + 200
                dp[i][j][k] = t;
    base[1] = 1;
    for(int i = 2; i < 21; i ++) // base��Ϊ��׼������
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
