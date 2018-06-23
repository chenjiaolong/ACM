#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

// lambda表达式主要解决函数内联，CPP
// []()mutable -> int {}(); // 匿名表达式
// [], =值捕获，只读，=mutable读原本改副本，&读写原本
// ()参数, int a, int b
// {} 语句实现,()调用
// -> 指定返回值类型
// C++11不支持参数auto，C++14支持

int main()
{
    int num1 = 100;
    int num2 = 99;
    // [=]只能读外部变量，不可以写
    [=](){cout << num1 << " " << num2 << endl;}();
    [&](){ num1 = 20, num2 = 90; cout << num1 << " " << num2 << endl; }();
    [=]()mutable{ num1 = 10, num2 = 20, cout << num1 << " " << num2 << endl;}();

    cout << "main = " << num1 << " " << num2 << endl;

    int a{10};
    int b{9};
    int c{8};
    // &a, b, c: a可读可写，bc只能读
    [&a, b, c](){ a = 5, cout << a << " " << b << " " << c << endl;}();

    // a, b, c 只能读
    [a, b, c](){ cout << a << " " << b << " " << c << endl; }();
    [a, b, c]()mutable{ a = 1, b = 2, c = 3, cout << a << " " << b << " " << c << endl; }();

    cout << a << " " << b << " " << c << endl; // [a, b, c]() mutable副本，能读写，读的原本， 写的副本

    // = 只能制定全部
    // [&a, = ](){cout << a << " " << b << " " << c << endl; }();

    [](auto a, auto b) { cout << a + b << endl; }(10, 11); // C++14推理数据类型
    [](auto a, auto b) { cout << a + b << endl; }(10.8, 11); // auto 推理数据类型
    [](auto a = 0, auto b = 0) { cout << a + b << endl; }(1, 1); // 默认参数初始化用=
    [](int a = 0, int b = 0){ cout << a + b << endl; }();

    array<int, 10> myint{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // CPP风格的数组
//    for(auto i : myint)
//        cout << i << endl;
    for_each(myint.begin(), myint.end(), [](int num) { cout << num << endl; }); // 显示
    for_each(myint.begin(), myint.end(), [](int &num) { num += 1, cout << num << endl; }); // 修改
    for_each(myint.begin(), myint.end(), [](int num) {cout << num << endl; });
    return 0;
}
