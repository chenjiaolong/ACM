#include <iostream>

using namespace std;
// union 默认公有，设置私有
// union 可以实现封装，只有一个变量，节约
union u
{
// private :
    int num;
    float f;
    void go()
    {
        cout << "SSS" << endl;
    }
};
// 共用体无法继承，多态
//! union uSon : public u{  };

int main()
{
    u p1;
    p1.num = 10;
    p1.go();
    u p2{14}; // 只能初始化一个变量
    cout << p2.num << endl;
    p2.f = 10.8;
    cout << p2.num << endl;
    return 0;
}
