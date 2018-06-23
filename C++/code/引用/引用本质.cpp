#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    int data = 20;
    int &rnum(num); // 引用一旦初始化，不会再引用其他变量
    rnum = data;
    cout << num << endl;
    cout << data << endl;

    double db;
    double &rdb(db);
    cout << sizeof(rdb) << endl; // 编译器的优化处理，引用变量名的别名

    struct MyStruct // 引用的本质是指针实现的，简称程序
    {
        int &rint;
        double &rdb;
    };
    cout << sizeof(MyStruct) << endl;
    return 0;
}
