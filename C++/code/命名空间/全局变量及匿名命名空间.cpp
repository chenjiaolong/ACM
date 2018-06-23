#include <iostream>

using namespace std;

// int a; // CPP 没有声明和定义的差别
int a = 5;

// 一般禁止使用匿名命名空间
namespace
{
    int a = 10;
}

int main()
{
    //! a = 3;
    cout << :: a << endl;// 引用全局，不包含匿名
    :: a = 3;
    return 0;
}
