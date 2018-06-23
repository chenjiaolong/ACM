#include <iostream>

using namespace std;

// constexpr 标志返回值或其它表达式是常量
constexpr int get()
{
    return 5;
}

int main()
{
    int a[5 + get()];
    return 0;
}
