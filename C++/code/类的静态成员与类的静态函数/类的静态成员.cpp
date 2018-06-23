#include <iostream>

using namespace std;

class myclass
{
public :
    static int num; // 只会初始化一次
    int data; // 每创建一次都会初始化一次
    myclass()
    {
        num += 1;
    }
    ~myclass()
    {
        num -= 1;
    }
};

int myclass :: num = 0; // 静态成员，所有的对象都可以访问

int main()
{
    myclass my1, my2, my3;
    my3.~myclass();
    // 静态成员不属于任何一个对象，任何一个对象都可以访问，静态区
    // 用于同类对象通信
    myclass *p = new myclass;
    cout << my1.num << endl;
    cout << my2.num << endl;
    cout << my3.num << endl;
    cout << myclass :: num << endl;
    return 0;
}
