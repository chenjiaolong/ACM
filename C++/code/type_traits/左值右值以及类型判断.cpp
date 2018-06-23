#include <string>
#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
    int i(10);
    int &ri(i);
    int &&rri(i + 3);
    // 判断左值引用还是右值引用
    cout << is_lvalue_reference<decltype(i)> :: value << endl;
    cout << is_lvalue_reference<decltype(ri)> :: value << endl;
    cout << is_rvalue_reference<decltype(rri)> :: value << endl;

    cout << "------------" << endl;
    int a[5];
    int *p(a);
    cout << is_array<decltype(a)> :: value << endl;
    cout << is_array<decltype(p)> :: value << endl;

    cout << "------------" << endl;
    int num(10);
    double db(20);
    string str;


    cout << is_integral<decltype(num)> :: value << endl;
    cout << is_integral<decltype(db)> :: value << endl;
    cout << is_class<string> :: value << endl;
    cout << is_class<decltype(str)> :: value << endl;
    // 判断数据类型

    return 0;
}

