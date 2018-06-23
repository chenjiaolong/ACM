#include <typeinfo>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    bool flag = true;// 非零解析为1，0解析为0 true false
    cout << flag << endl;
    cout << sizeof(flag) << endl;// 一个字节
    cout << typeid(flag).name() << endl;

    // while(flag)
        // cout << "SSS";

    bool flag1(false);
    bool flag2(true);
     flag1 = 0 && 10 && -1 || 2 + 3;
//     flag1 = 0 && 10 && -1 || 2;
//     flag1 = 3 > 2 && 3 < 1 || 1 | 2;
    while(flag1)
    cout << "SSSS";
    return 0;
}
