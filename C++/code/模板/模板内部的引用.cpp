#include <iostream>
#include <functional>

using namespace std;
// ��������ֵ���ã���ֵ���ã�ԭ���ܳ�ͻ
// ref ���� -> ��ֵ����
// move ��ֵ���� -> ��ֵ����

// ģ���Դ����ã�����&��&&����ԭ��
// T t, ref����ԭ���������Ǹ���

template<typename T>
void print1(T t)
{
    t += 1;
    cout << "void print1(T t)" << t << endl;
}
template<typename T>
void print2(T & t) // ref
{
    t += 1;
    cout << "void print2(T & t)" << t << endl;
}
template<typename T>
void print3(T && t) // move
{
    t += 1;
    cout << "void print3(T && t)" << t << endl;
}
void printint(int && t)
{
    cout << t << endl;
}
int main()
{
    int data1 = 100;
    int &rdata1(data1);
    int && rrdata1(data1 + 1);
    print1(data1); // ����
    cout << "data1 = " << data1 << endl;

    print1(ref(data1)); // ԭ�����ð�װ������װ������������
    cout << "ref(data1) = " << data1 << endl;

    print1(rdata1); // ģ�岢����ʶ����������ã�����
    cout << "rdata1 = " << rdata1 << endl;

    print1(rrdata1); // ��ֵ�����ڴ汣�����ʱֵ�� ����
    cout << "rrdata1 = " << rrdata1 << endl;

    print1(ref(rrdata1)); // ��ֵ�����ڴ汣�����ʱֵ�� ����
    cout << "ref(data1) = " << rrdata1 << endl;

    cout << "------------" << endl;
    int data2 = 100;
    int &rdata2(data2);
    int && rrdata2(data2 + 1);
    // print2(data2); // ԭ����ģ���Դ�����
    // print2(rdata2);
    print2(rrdata2);
    cout << "data2 = " << data2 << endl;
    cout << "rdata2 = " << rdata2 << endl;
    cout << "rrdata2 = " << rrdata2 << endl;

    cout << "------------" << endl;
    int data3 = 100;
    int &rdata3(data3);
    int && rrdata3(data3 + 1);
    // print3(data3); // ԭ����ģ���Դ�����
    // print3(rdata3);
    print3(rrdata3);
    cout << "data3 = " << data3 << endl;
    cout << "rdata3 = " << rdata3 << endl;
    cout << "rrdata3 = " << rrdata3 << endl;

    cout << "------------" << endl;
    int num = 10;
    int & rnum(num);
    //! printint(num);
    printint(move(num)); // �ƶ����壬 ���ݣ���ֵ����ת����ֵ����
    printint(move(rnum));
    printint(rnum  + 1);

    return 0;
}
