#include <iostream>

using namespace std;
// ����ָ�����飬��������ָ�룬�±�ѭ����ָ��ѭ��������

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}
int main()
{
    // ջ��
    int (*p[4])(int a, int b) { Add, Sub, Mul, Div };

    // ����
    // ��������ָ�뿪�ٺ���ָ������
    int (**pp)(int, int) { new (int(*[4]) (int, int)) { Add, Sub, Mul, Div } };

    int (* (&rp)[4] )(int a, int b)(p); // ���ú���ָ������
    int (** (&rpp) )(int, int )(pp); // ���ö�������ָ��
    for(int i = 0; i < 4; i ++) cout << rp[i](100, 10) << endl;
    cout << endl;
    for(int i = 0; i < 4; i ++) cout << rpp[i](100, 10) << endl;


    cout << "-------------" << endl;
    for(int (**ppx)(int, int)(pp); ppx < pp + 4; ppx ++) cout << (*ppx)(100, 10) << endl;
    cout << endl;
    for(int (**ppx)(int, int)(rpp); ppx < rpp + 4; ppx ++) cout << (*ppx)(100, 10) << endl;
    cout << endl;
    return 0;
}


