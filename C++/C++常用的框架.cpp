#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
#include<unordered_map>// (pku C++, G++��������֧��)
#include<unordered_set>// (pku C++, G++��������֧��)
#include <ext/hash_map>// (hdu C++��������֧��) (pku C++, G++��������֧��)
/***********************
 *������ C++ �������� *
 **********************/
#include<string>
#include<fstream>
#include<istream>
#include<ostream>
#include<sstream>
#include<iostream>
#include<strstream>// (pku G++��������֧��)
/***********************
 *������ C++ ��ʽ�ļ� *
 **********************/
#include<math.h>
#include<time.h>
#include<ctype.h> // �ַ��ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/***********************
 *������ C++ �����ļ� *
 **********************/
#include<algorithm>// �㷨ģ���ļ�
#include<functional>
#pragma comment(linker, "/STACK:102400000, 102400000")// ���������� (hdu C++��������֧��) (pku C++��������֧��)

using namespace std;

// ���õĹ��ܻ����궨��
#define maxnode 15
#define sigma_size 26
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lrt rt << 1
#define rrt rt << 1 | 1
#define middle int m = (l + r) >> 1
#define LL long long
#define ull unsigned long long
#define mem(x, v) memset(x, v, sizeof(x))
#define lowbit(x) (x & -x)
#define pii pair<int, int>
#define mk make_pair
#define limit 10000
/*ע����ܻ������-0.000*/
#define Sgn(x) (x<-eps? -1 :x<eps? 0:1)//xΪ������������ıȽ�,ע�ⷵ������
#define Cvs(x) (x > 0.0 ? x+eps : x-eps)//������ת��
#define zero(x) (((x)>0?(x):-(x))<eps)//�ж��Ƿ����0
#define mul(a,b) (a<<b)
#define dir(a,b) (a>>b)
#define ONLINE_JUDGE

const int prime = 999983;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-4;
const LL mod = 1e9 + 7;
const ull mx = 133333331;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Test.in", "r", stdin);
    freopen("Test.out", "w", stdout);
#endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    return 0;
}

