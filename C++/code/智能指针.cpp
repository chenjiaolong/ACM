#include <iostream>
#include <memory>
#include <windows.h>

using namespace std;

// ����ָ�룬�ڴ�й¶���Զ�����

void cmem()
{
    while(1)
    {
        double *p = new double[1024 * 1024 * 10];
        Sleep(3);
        delete p;// �ͷ�
        Sleep(3);
    }
}
void autoptr()
{
    while(1)
    {
        double *p(new double[1024 * 1024 * 10]);
        auto_ptr<double> autop(p); // �ӹܣ��Զ�����
        Sleep(3);
    }
}

void autoptrnew()
{
    while(1)
    {
        Sleep(6);
        unique_ptr<double >p(new double[1024 * 1024 * 10]);
        Sleep(6);
    }
}

int main()
{
    // cmem();
    // autoptr();
    autoptrnew();
    return 0;
}
