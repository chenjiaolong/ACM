#include <iostream>

using namespace std;

int main()
{
    int num = 100;
    int *p1 = &num;
    //! char *p2 = p1; // CPP类型检测严格，精准
    // int *p2 = p1; // C语言的赋值
    int *p2(p1); // () 初始化
    return 0;
}
