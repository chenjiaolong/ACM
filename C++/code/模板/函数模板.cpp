#include <iostream>

using namespace std;

// add CPP ���������Ǹ��ݲ����б�Ĳ�ͬ������

int add(int a, int b)
{
    cout << "int" << endl;
    return a + b;
}
//char add(char a, char b)
//{
//    return a + b;
//}

// ���õ�ʱ����룬�����õ�ʱ�򲻱���
// ����ģ�����壺ͨ�ã�����

template <typename T>
T add(T a, T b)
{
    cout << "T" << endl;
    return a + b;
}
int main()
{
    cout << add(1, 2) << endl; // ԭ������������ģ�庯��
    cout << add<int >(1, 2) << endl;// ǿ�е���ģ�庯����"<>"ָ������
    cout << add('1', '2') << endl;
    system("pause");
    return 0;
}
