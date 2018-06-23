#include <array>
#include <iostream>

using namespace std;

// ģ��ı������ñ����Ż�ģ�����ƣ��࣬�����ռ䣬ȫ�֣��������ں����ڲ�
template<typename T>
using tencent = array<T, 10>;

template<typename T, int n>
using maomaoyu = array<T, n>;

// C++14 auto������������������
// C++11 ��Ҫ -> ָ������
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}
template<typename T> using t = T;
template<typename T> using tp = T*;
// template<typename T> typedef T* tp; // typedef ģ�� �Ƿ�
template<typename T>
T show(T tx)
{
    t<int > t1(tx); // һ��ʹ�ñ�������ָ������
    tp<int > tp1(&tx); // ��ʼ��
    cout << t1 <<" "<< tp1 << endl;

    return t1;
}
int main()
{
    cout << add(1, 2) << endl;
    cout << add(1, 2.1) << endl;

    cout << "----------" << endl;
    int a = 10;
    cout << show(a) << endl;

    using intarray = array<int, 10>; // ģ���������ȷ����
    array<int, 10>myint;
    intarray myint2;

    cout << "----------" << endl;
    tencent<int > t1{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // ����ȷ����
    for(auto i : t1) cout << i << endl;

    cout << "----------" << endl;
    maomaoyu<int, 10> t2{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for(auto i : t2) cout << i << endl;

    return 0;
}
