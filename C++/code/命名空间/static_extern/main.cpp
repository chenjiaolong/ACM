#include <iostream>
// :: ��ǰ�ļ���static�����ǿ��ļ���extern
// �����ṹ���ͬȫ�ֱ��������Կ��ļ���:: ��������

using namespace std;
extern int x; // �����ⲿȫ�ֱ���

int x1 = 199;
namespace
{
    int x = 999;
}
int main()
{
    // cout << x << endl;
    cout << x1 << endl;
    cout << :: x << endl; // ������extern��ͻ��:: x ��ʾ�ⲿ

    void test(); // ����
    test();
    return 0;
}
