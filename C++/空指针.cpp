#include <iostream>
using namespace std;
int main()
{
    //!void voidObject; ����������void���͵ı���
    void *pv; //�ԣ���������void���͵�ָ��
    int i = 5;
    pv = &i; //void����ָ��ָ�����ͱ���
    cout << &i << endl;
    cout << (int *)pv << endl;
    int *pint = static_cast<int *>(pv); //voidָ��ת��Ϊintָ��
    cout << "*pint = " << *pint << endl;
    return 0;
}

