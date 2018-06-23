#include <cstdlib>
#include <iostream>

using namespace std;

// 设计模式：外观模式
// C语言没有默认参数赋值
// 函数可以快速调用
// 省略参数，CPP独有
// 默认参数都从右边开始，参数进栈，从右向左
// 不默认的参数，都在左边，默认右边
int add(int a, int b, int c = 1, int d = 1)
{
    return a + b + c + d;
}
void run(const char *str = "notepad")
{
    system(str);
}
int main()
{
    // cout << add(1) << endl; 不默认的参数，必须传递
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    cout << add(1, 2, 3, 4) << endl;
    run();
    return 0;
}
