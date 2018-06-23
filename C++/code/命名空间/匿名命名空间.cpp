#include <iostream>

using namespace std;

// 匿名命名空间等同全局变量
namespace
{
    int x = 10;
}

// int x = 9;

int main()
{
    x = 3;
    cout << x << endl;
    return 0;
}
