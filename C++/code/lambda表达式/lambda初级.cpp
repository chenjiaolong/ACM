#include <typeinfo>
#include <iostream>

using namespace std;

// 解决函数怀孕现象
int main()
{
    auto fun = []{ cout << "hello, world!" << endl; }; // 函数指针
    fun(); // 调用
    cout << typeid(fun).name() << endl;

    cout << "----------" << endl;
    [] { cout << "hello, world!" << endl; }(); // 匿名lambda表示式
    // ()最后的括号是调用

    cout << "----------" << endl;
    // {  }函数体，执行
    [] { cout << "hello, world, ", cout << "maomaoyu!" << endl; }();

    // ()参数列表，{}函数体，()调用
    cout << "----------" << endl;
    [](const char * str){ cout << str << endl; }("maomaoyu");

    cout << "----------" << endl;
    auto f = [](char * str){ cout << str << endl; };
    f("Lee");// 本质类，
    cout << typeid(f).name() << endl; // class <lambda_8fcff5e887e1a3c06bf0d6c40e66b8c>

    //! cout << f << endl; // lambda表达式不可以直接取地址，无法当作函数指针

    cout << "---------" << endl;
    // -> 在(){}之间指定返回值类型
    auto f1 = [](double a, double b) -> int { return a + b; };
    cout << f1(10, 19.1) << endl;
    // 内联展开，无法取出地址

    cout << "---------" << endl;
    // -> decltype(a + b) 类型推理
    auto f2 = [](double a, int b) -> decltype(a + b) { return a + b; };
    cout << f2(10.1, 10) << endl;

    // []
    int num = 100;
    auto f3 = [](int num){num = 5; cout << num << endl; };
    f3(num); // 遵循副本机制
    cout << "main = " << num << endl;

    return 0;
}
