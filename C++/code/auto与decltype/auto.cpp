#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T1, typename T2>
auto add(T1 t1, T2 t2) // 自动推理数据类型
{
    return t1 + t2;
}
int main()
{
    // 自适应数据类型，自动推理
    // auto num = 10;
    // auto num = 10.1;
    // auto num = 'A';
    // auto num = L"bobo"; // wchar_t const *
    //! auto double num = 3 + 1.2; // auto 不能与任何其它类型说明符组合
    auto num = 3 / 5;
    cout << typeid(num).name() << endl;

    int a[5] = {1, 2, 3, 4, 5};
    // auto i 副本 auto &i 原本
    for(auto &i : a)
    {
        i += 1;
        cout << i << endl;
    }
    for(auto i : a) cout << i << endl;

    cout << add(10, 11.2) << endl;
    cout << add(10.1, 11) << endl;

    return 0;
}
