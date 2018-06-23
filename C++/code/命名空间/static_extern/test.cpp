#include <iostream>

using namespace std;

int x = 10;
static int x1 = 100; // static 作用于当前文件，可以编译，无法连接
namespace
{
    int x = 999;
    static int x1 = 999;
}

void test()
{
    cout << :: x << endl; // 跨文件引用的是全局
    cout << :: x1 << endl; // 同一个文件，引用的还是static
}
