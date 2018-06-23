#include <cstdlib>
#include <iostream>

#define f(x) x*x*x // C语言内联，C++要求类型严格

using namespace std;

inline int get(int x); // C++ 的内联函数

template<typename T>
inline T go(T t)
{
    return t * t;
}

// 提高程序运行速度
/**
  * inline 只是对于编译器的建议
  * 一般情况下，我们对内联函数做如下的限制：
  * （1）不能有递归
  * （2）不能包含静态数据
  * （3）不能包含循环
  * （4）不能包含switch和goto语句
  * （5）不能包含数组
  */
// 若一个内联函数定义不满足以上限制，则编译系统把它当作普通函数对待。
int main()
{

    auto fun = [](){}; // 也是内联函数
    // cout << (void *) fun << endl;
    cout << go(5) << endl; // 优化为内联函数
    cout << get(10) << endl;
    return 0;
}
inline int get(int x) // C++ 的内联函数，inline可以省略， 类型，类型安全
{
    return x * x * x;
}
