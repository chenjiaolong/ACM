#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void show(T *p) // 引用
{
    // decltype(*p) num(*p); // 内存备份
    // cout << num << endl;

    int a = *p; // 获取一个类型
    decltype(a) num[5]{a, a, a, a, a};
    for(auto i : num)
        cout << i << endl;

    cout << *p << endl;
}

int main()
{
    auto str("hello world");
    cout << typeid(str).name() << endl;// const char *

    cout << "----------" << endl;
    auto flag(1 && 0 && 3 || -1);
    //! flag(0); ()仅用于初始化
    cout << typeid(flag).name() << " " << flag << endl;

    cout << "----------" << endl;
    auto flag1(flag);
    cout << typeid(flag1).name() << " " << flag1 << endl;

    // 拷贝类型
    cout << "----------" << endl;
    // decltype(flag) 根据一个变量获取类型，创建数组，创建指针
    decltype(flag)flag2[5]{0}; // {0}初始化
    for(auto i : flag2)
        cout << typeid(i).name() << " " << i << endl;

    cout << "----------" << endl;
    int a = 10;
    show(&a);

    return 0;
}
