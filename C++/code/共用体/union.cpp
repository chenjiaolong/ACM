#include <iostream>

using namespace std;
// CPP共用体，可以初始化，内部可以有函数，定义变量时不需要union关键字
// 共用体，共享内存，不计入代码去大小
union u
{
    int num = 10;
    double db;
    void go()
    {
        cout << "SSS" << endl;
    }
};

int main()
{
    cout << sizeof(u) << endl;
    u *ptr(nullptr);
    ptr -> go();
    return 0;
}
