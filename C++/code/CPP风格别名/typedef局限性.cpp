#include <iostream>

// typedef ֻ�ܴ���C����
// C++���������ռ䣬����ģ�壬 ��ģ��

using namespace std;

typedef int a[5]; // ����

namespace run
{
    int num = 10;
}
//! typedef run NS; // C���.���ܴ���C++���е������ռ�

namespace NS = run; // ����������������ռ�

template<typename T> // typedef T tx
void runit(T t)
{
    typedef T tx;
    tx t1 = t; // �ڲ�����
    cout << t << endl;
}

int main()
{
    a a1;
    cout << sizeof(a1) << endl;

    run :: num = 19;
    cout << run :: num << endl;

    NS :: num = 9;
    cout << NS :: num << endl;

    runit(10);
    return 0;
}
