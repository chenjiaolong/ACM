#include <iostream>
#include <functional>

using namespace std;
using std :: function; // ʹ�������ռ��һ����
using fun = std :: ios :: fmtflags; // �����ռ����������ߺ�������

// һ�������ԭ����usingȡ��typedef
// typedef������ģ�壬�����������ռ�
// double DB;
// typedef doule DB;
// DB ����double

// int num; // �������
// using INT = int num;����using INT =
// using INT = int; // ȥ��������

typedef double DB;
using DBCPP = double; // CPP���ı���

typedef int a[10];
using intarray = int[10];

typedef int(*p)(int a, int b); // ����ָ�����ͣ�p
using pf = int(*)(int a, int b); // CPP���ı���

typedef int(*pa[10])(int a, int b); // ����ָ���������ͣ�pa
using ppf = int(*[10])(int a, int b);


namespace china
{
    template<typename T> using tp = T; // ����
    // template<typename T> typedef T tp;
    template<typename T>
    T add(T a, T b)
    {
        T c = a + b;
        return c;
    }
}


int main()
{
    cout << sizeof(DBCPP) << endl;
    cout << sizeof(DB) << endl;
    intarray int_array;
    cout << sizeof(int_array) << endl;

    cout << china :: add<int >(1, 2) << endl;

    return 0;
}
