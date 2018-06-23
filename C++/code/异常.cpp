#include <cstdlib>
#include <iostream>

using namespace std;
// 异常与错误不一样，异常一般能够正常工作
// 错误就是程序无法正常工作，无法编译
// 异常让程序在错误的输入，文件不存在，内存异常仍然可以正常工作
int Div(int a, int b)
{
    try // 尝试
    {
        if(b == 0) throw 1; // 抛出
        cout << "a = " << a << " , b = " << b << endl;
        return a / b;
    }catch(int code) // 捕获异常
    {
        if(code == 1)
            cout << "除数不可以为0" << endl;
        return 0;
    }

}

int main()
{
    int num1;
    int num2;
    cin >> num1 >> num2;
    cout << Div(num1, num2) << endl;
    return 0;
}
