// 元编程
// 什么元编程(metaprogramming)?
// 利用模板可以进行编译期计算（数值计算、型式计算、代码计算）的特点进行程序设计
//
// 为什么可以进行元编程？
// C++是两层语言：执行编译期计算的代码称为静态代码，执行运行期计算的代码称为动态代码
// 模板可用于函数式编程（functional programming）:强调抽象计算，重视模板化，使用递归控制流程
// 模板时图灵完备的：理论上，模板可以执行任何计算任务
//
// 为什么需要元编程？
// 编译期计算可以使代码更通用，更易用，提升程序执行性能
//
// 元编程的缺点
// 相对结构化编程，编译效率极低
// 代码丑陋不堪，阅读难、调试难、维护难，易导致代码膨胀
//
// 元编程可以做什么？
// 数值序列计算、素性判断、控制结构、循环展开、型式判定、表达式、编译期多态、特征、策略、标签、元容器、.……
// 注：对操作系统编程而言，元编程意义不大
//#include<iostream>
//
//using namespace std;
//类模板，计算Fibonacci数列的第i项
//template<int i = 1>class Fibonacci
//{
//public:
//    enum{value = Fibonacci<i - 1> :: value + Fibonacci<i - 2> :: value};
//};
// 类模板特化，递归终止条件
//template<> class Fibonacci<2> { public: enum{ value = 1}; };
//template<> class Fibonacci<1> { public: enum{ value = 1}; };
//
//int main()
//{
//    cout << "Fib(" << 1 << ") = " << Fibonacci<1> :: value << endl;
//    cout << "Fib(" << 2 << ") = " << Fibonacci<2> :: value << endl;
//    cout << "Fib(" << 3 << ") = " << Fibonacci<3> :: value << endl;
//    cout << "Fib(" << 4 << ") = " << Fibonacci<4> :: value << endl;
//    return 0;
//}

// 素数枚举
#include<iostream>
#include<iomanip>

using namespace std;

// 递归计算p是否为素数;若是，素数判定结论answer为1，否则为0
template<int p, int i> struct PrimeMagicCube
{
    enum {answer = p % i && PrimeMagicCube<p, i - 1> :: answer};
};
// 素数魔方类模板部分特化，递归终止条件，除数为1，没有找到因子
template<int p> struct PrimeMagicCube<p, 1> {enum { answer = 1 }; };

// 数值类模板，输出不大于i的全部素数
template<int i> struct Number
{
    Number<i - 1> a; // 递归定义数值对象
    enum{ answer = PrimeMagicCube<i, i - 1> :: answer };
    void IsPrime()
    {
        // 先降序输出全部素数，后升序输出全部数值素性序列
        if(answer) cout << setw(4) << right << i;
        a.IsPrime(); // 递归调用，计算下一个数值的素性
        cout << setw(2) << answer;
    }
};
// 数值类模板特化，终止于2
template<> struct Number<2>
{
    enum { answer = 1};
    void IsPrime()
    {
        cout << setw(4) << right << 2 << endl;
        cout << setw(2) << answer;
    }
};
int main()
{
    Number<100> a;
    a.IsPrime();
    cout << endl;
    return 0;
}
