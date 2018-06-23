#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
// 静态函数没有this指针，无法调用成员变量成员函数

struct runit
{
    static vector<runit *> all;
    int a, b;
    runit(int x, int y) : a(x), b(y)
    {
        all.push_back(this); // 每次构造，压入地址
    }
    void show()
    {
        cout << a << " " << b << endl;
    }
    static void showall() // 配合静态成员，管理对象数量，批量操作
    {
        for(auto i : all)
            cout << (*i).a << " " << (*i).b << endl;
    }
};

vector<runit *>runit :: all;

int main()
{
    runit run1(1, 1);
    runit run2(1, 2);
    runit run3(1, 3);
    run1.show();
    run2.show();
    run3.show();
    runit :: showall();
    return 0;
}
