#include <iostream>

using namespace std;

int main()
{
//    const int n = 10;
//    int a[n]; // C++ 编译器自动优化， n替换10
//    cout << sizeof(a) << endl;

    int a = 10;
    const int n = a;
    cout << n << endl;
    //! int data[n]; // C++编译器不敢乱优化，但是变量发生变化

    const int num = 10;
    *(int *)(&num) = 3;
    cout << (void *)&num << endl;

    // cout << *(int *)(&num) << endl;
    cout << *(&num) << endl;// 优化，强行替换10
    cout << num << endl;

    const int num2 = a;
    *(int *)(&num2) = 3;
    cout << (void *)&num2 << endl;

    // cout << *(int *)(&num2) << endl;
    cout << *(&num2) << endl;// 直接读内存，不敢优化
    cout << num2 << endl;

    return 0;
}
