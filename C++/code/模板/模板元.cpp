#include <iostream>

using namespace std;

int get50(int n)
{
    if(n == 1) return 1;
    if( n == 2) return 2;
    return get50(n - 1) + get50(n - 2);
}
// 反复调用，函数等待，返回，浪费时间多
// 模板元实现递归加速
// 执行速度快，编译时间的慢，代码会增加
// 把运行的时间节约在编译的时候
// 递归加速，游戏优化， 仅仅使用C++11

template<int N>
struct data
{
    // 递归
    enum{ res = data<N -1> :: res + data<N - 2> :: res };
};
template<>
struct data<1>
{
    enum {res = 1};
};
template<>
struct data<2>
{
    enum {res = 2};
};
int main()
{
    int num = 40;
    cout << data<40> :: res << endl; // 模板元，代码加速
    // cout << data<num> :: res << endl;
    cout << get50(40) << endl;
    return 0;
}
