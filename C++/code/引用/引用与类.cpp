#include <iostream>

using namespace std;

class myclass; // 类的声明,提升作用域，作用于指针或者引用，不能是对象

myclass *p;
//! myclass &ra; // 引用在定义时必须初始化，作为参数时除外
void run(myclass & rmy)
{

}
// myclass my;

// 类中间可以包含引用成员，默认，构造初始化(注意和拷贝构造初始化有冲突)

int g_num = 100;
class myclass
{
public :
    int x, y;
    // int &rx = x;
    // int &rx{x}; // 默认初始化
    //! int &rx(x); // 和类的成员函数冲突
    int &rx;
    myclass() : rx(g_num) // 构造初始化
    {
        rx = 10; // 改变引用的值
    }
//    myclass(const myclass &my) // 和引用构造初始化有冲突
//    {
//        cout << "copy call" << endl;
//    }
    void show() const
    {
        cout << x << "  " << y << endl;
    }
};
// 引用可以避免不必要的拷贝构造
myclass &get(myclass &data)
{
    return data;
}
int main()
{
    cout << sizeof(myclass) << endl;
    myclass my1;
    cout << g_num << endl;
    get(my1);

    myclass my2;
    const myclass & my3(my2); // 引用my2 等价于my1,内存占四个字节（32bit）
    my3.show();// 常引用等价于常对象
    return 0;
}
