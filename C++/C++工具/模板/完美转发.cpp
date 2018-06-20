// 普通构造函数实现
//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public :
//    A(const string &s, const string &t) : _s(s), _t(t) { cout << 1 << endl; }
//    A(const string &s, string &&t) : _s(s), _t(move(t)) { cout << 2 << endl; }
//    A(string &&s, const string &t) : _s(move(s)), _t(t) { cout << 3 << endl; }
//    A(string &&s, string &&t) : _s(move(s)), _t(move(t)){ cout << 4 << endl; }
//private :
//    string _s, _t;
//};
//
//int main()
//{
//    string s1("Hello");
//    const string s2("World");
//    A a1(s1, s2);
//    A a2(s1, string("Bingo"));
//    A a3(string("Good"), s2);
//    A a4(string("Good"), string("Bingo"));
//    return 0;
//}

//完美转发
//完美转发的意义
//库的设计者需要设计一个通用函数，将接收到的参数转发给其他函数
//转发过程中，所有参数保持原先语义不变
//完美转发的实现策略
//当需要同时提供移动语义与拷贝语义时，要求重载大量建构函数，编程工作量巨大，易出错
//右值引用于函数模板互相配合，可以实现完美转发，极大降低代码编写量

#include<iostream>

using namespace std;
class A
{
public :
    // 根据实际参数型式生成不同的左值或右值引用来构建函数版本
    // T1或T2可以以为不同型，此处相同仅为示例
    // 实参推演时，使用引用折叠机制
    // 当形式参数为T&&型时，当且仅当实际参数为右值或左值引用时，
    // 实际参数型式才为右值引用
    // 引用折叠机制与const/volatile无关，保持其参数性质不变
    // std :: forward<T>(t) 转发参数的右值引用T &&
    template<typename T1, typename T2> A(T1 &&s, T2 &&t)
    : _s(std :: forward<T1>(s)), _t(std :: forward<T2>(t)) {  }
private :
    std :: string _s, _t;
};

int main()
{
    string s1("Hello");
    const string s2("World");
    A a1(s1, s2);
    A a2(s1, string("Bingo"));
    A a3(string("Good"), s2);
    A a4(string("Good"), string("Bingo"));
    return 0;
}