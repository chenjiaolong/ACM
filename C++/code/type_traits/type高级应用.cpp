#include <string>
#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

template<class T1, class T2>
void same(const T1 &t1, const T2 &t2)
{
    // 判断模板的数据类型
    cout << is_same<T1, T2> :: value << endl;

    cout << typeid(T1).name() << " " <<is_integral<T1> :: value << endl;
    // cout << typeid(T1).name() << " " <<is_integral<decltype(t1)> :: value << endl;

}

int main()
{

    same(1, 123);
    same(1, 123.1);
    same(3.0, "123");
    return 0;
}
