#include <iostream>

using namespace std;
// 函数指针数组，二级函数指针，下标循环，指针循环，引用

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}
int main()
{
    // 栈上
    int (*p[4])(int a, int b) { Add, Sub, Mul, Div };

    // 堆上
    // 二级函数指针开辟函数指针数组
    int (**pp)(int, int) { new (int(*[4]) (int, int)) { Add, Sub, Mul, Div } };

    int (* (&rp)[4] )(int a, int b)(p); // 引用函数指针数组
    int (** (&rpp) )(int, int )(pp); // 引用二级函数指针
    for(int i = 0; i < 4; i ++) cout << rp[i](100, 10) << endl;
    cout << endl;
    for(int i = 0; i < 4; i ++) cout << rpp[i](100, 10) << endl;


    cout << "-------------" << endl;
    for(int (**ppx)(int, int)(pp); ppx < pp + 4; ppx ++) cout << (*ppx)(100, 10) << endl;
    cout << endl;
    for(int (**ppx)(int, int)(rpp); ppx < rpp + 4; ppx ++) cout << (*ppx)(100, 10) << endl;
    cout << endl;
    return 0;
}


