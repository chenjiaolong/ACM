#include <iostream>

using namespace std;

// add CPP 函数重载是根据参数列表的不同来划分

int add(int a, int b)
{
    cout << "int" << endl;
    return a + b;
}
//char add(char a, char b)
//{
//    return a + b;
//}

// 调用的时候编译，不调用的时候不编译
// 函数模板意义：通用，泛型

template <typename T>
T add(T a, T b)
{
    cout << "T" << endl;
    return a + b;
}
int main()
{
    cout << add(1, 2) << endl; // 原生函数优先于模板函数
    cout << add<int >(1, 2) << endl;// 强行调用模板函数用"<>"指定类型
    cout << add('1', '2') << endl;
    system("pause");
    return 0;
}
