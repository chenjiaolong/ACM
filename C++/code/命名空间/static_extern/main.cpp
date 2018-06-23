#include <iostream>
// :: 当前文件的static，再是跨文件的extern
// 匿名结构体等同全局变量，可以跨文件，:: 屏蔽匿名

using namespace std;
extern int x; // 引用外部全局变量

int x1 = 199;
namespace
{
    int x = 999;
}
int main()
{
    // cout << x << endl;
    cout << x1 << endl;
    cout << :: x << endl; // 匿名与extern冲突，:: x 表示外部

    void test(); // 声明
    test();
    return 0;
}
