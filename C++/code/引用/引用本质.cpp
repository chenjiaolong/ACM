#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    int data = 20;
    int &rnum(num); // ����һ����ʼ����������������������
    rnum = data;
    cout << num << endl;
    cout << data << endl;

    double db;
    double &rdb(db);
    cout << sizeof(rdb) << endl; // ���������Ż��������ñ������ı���

    struct MyStruct // ���õı�����ָ��ʵ�ֵģ���Ƴ���
    {
        int &rint;
        double &rdb;
    };
    cout << sizeof(MyStruct) << endl;
    return 0;
}
