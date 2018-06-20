#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
#include<unordered_map>// (pku C++, G++编译器不支持)
#include<unordered_set>// (pku C++, G++编译器不支持)
#include <ext/hash_map>// (hdu C++编译器不支持) (pku C++, G++编译器不支持)
/***********************
 *以上是 C++ 常用容器 *
 **********************/
#include<string>
#include<fstream>
#include<istream>
#include<ostream>
#include<sstream>
#include<iostream>
#include<strstream>// (pku G++编译器不支持)
/***********************
 *以上是 C++ 流式文件 *
 **********************/
#include<math.h>
#include<time.h>
#include<ctype.h> // 字符文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/***********************
 *以上是 C++ 基本文件 *
 **********************/
#include<algorithm>// 算法模板文件
#include<functional>
#pragma comment(linker, "/STACK:102400000, 102400000")// 输入加速外挂 (hdu C++编译器不支持) (pku C++编译器不支持)

using namespace std;

// 常用的功能或常量宏定义
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
/*注意可能会有输出-0.000*/
#define Sgn(x) (x<-eps? -1 :x<eps? 0:1)//x为两个浮点数差的比较,注意返回整型
#define Cvs(x) (x > 0.0 ? x+eps : x-eps)//浮点数转化
#define zero(x) (((x)>0?(x):-(x))<eps)//判断是否等于0
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

