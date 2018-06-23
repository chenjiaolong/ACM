#include <cstdlib>
#include <iostream>


using namespace std;

int main()
{
    int num(5);
    cout << num << endl;
    // char *p("calc");
    // system(p);
    // char str[10] {"calc"};
    // system(str);

    // L "ABCDEF": 代码区的常量
    wchar_t *wp(L "ABCDEF"); // 宽字符

    int a[5]{1, 2, 3, 4, 5}; // 字符串，数组用{}初始化，单个变量()
    for (auto i : a) // 遍历所有的变量
        cout << i << endl;

    return 0;
}
