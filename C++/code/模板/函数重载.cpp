#include <iostream>

using namespace std;
// �����ĸ��������Ͳ�һ����˳�����أ��뷵��ֵ�޹�
// ��ָ������ƥ��ָ��
template<typename T>
void go(T t)
{
    cout << "TTTTT" << endl;
    cout << t << endl;
}
template<typename T>
void go(T *t)
{
    cout << "*****" << endl;
    cout << t << endl;
}

int main()
{
    int *p{new int [5]{1, 2, 3, 4, 5}};
    go(p[0]);
    go(p);
    go(&p); // ��ַ�����ڵ�ַ
    return 0;
}
