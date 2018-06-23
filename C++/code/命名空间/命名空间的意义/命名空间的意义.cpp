// 解决全局变量的冲突
#include "main.h"
#include <iostream>

using namespace std;

int num = 10;

int main()
{
    cout << num << endl;
    cout << data :: num << endl; // :: 域作用符
    return 0;
}
