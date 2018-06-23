#include <array>
#include <iostream>

using namespace std;

// 模板的别名，用别名优化模板名称，类，命名空间，全局，不可以在函数内部
template<typename T>
using tencent = array<T, 10>;

template<typename T, int n>
using maomaoyu = array<T, n>;

// C++14 auto功能升级，任意推理
// C++11 需要 -> 指定类型
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}
template<typename T> using t = T;
template<typename T> using tp = T*;
// template<typename T> typedef T* tp; // typedef 模板 非法
template<typename T>
T show(T tx)
{
    t<int > t1(tx); // 一旦使用别名必须指定类型
    tp<int > tp1(&tx); // 初始化
    cout << t1 <<" "<< tp1 << endl;

    return t1;
}
int main()
{
    cout << add(1, 2) << endl;
    cout << add(1, 2.1) << endl;

    cout << "----------" << endl;
    int a = 10;
    cout << show(a) << endl;

    using intarray = array<int, 10>; // 模板别名，明确类型
    array<int, 10>myint;
    intarray myint2;

    cout << "----------" << endl;
    tencent<int > t1{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // 不明确类型
    for(auto i : t1) cout << i << endl;

    cout << "----------" << endl;
    maomaoyu<int, 10> t2{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for(auto i : t2) cout << i << endl;

    return 0;
}
