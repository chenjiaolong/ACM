#include <vector>
#include <typeinfo>
#include <iostream>

using namespace std;

auto main() -> int
{
    const vector<int >v{1, 2, 3, 4, 5};

    auto inta = v[0];
    cout << typeid(inta).name() << endl;
    inta = 20;
    decltype(v[0]) intd = 1;
    cout << typeid(intd).name() << endl;
    //! ind = 30; // decltype ���Ի�ȡ�������� ��ȡ��������

    const double db = 10.8;
    const double &rdb(db);
    struct mys
    {
        //! auto r1; // auto �������ڽṹ���ڲ�
        decltype(rdb) r1;
    };
    cout << sizeof(mys) << endl; /// 4
    cout << typeid(v[0]).name() << endl;

    double db2 = 10.9;
    double &rdb2(db2);
    auto dbx = rdb;
    dbx = 8.9;
    cout << db << endl;
    cout << dbx << endl;

    cout << "------------" << endl;
    int a = 10;
    int &ra(a);
    auto i1 = 10;
    auto i2 = a;
    auto i3 = ra; // auto �޷����ֳ����������������ñ���

    cout << typeid(i1).name() << endl;
    cout << typeid(i2).name() << endl;
    cout << typeid(i3).name() << endl;

    cout << "------------" << endl;
    decltype(a) i4 = 10;
    decltype(10) i5 = a;
    decltype(ra) i6 = ra;
    cout << typeid(i4).name() << endl;
    cout << typeid(i5).name() << endl;
    cout << typeid(i6).name() << endl;

    cout << typeid(ra).name() << endl;
    // typeid,ֻ�ܻ�ȡ���ͣ����ܻ�ȡ���úͳ���

    return 0;
}
