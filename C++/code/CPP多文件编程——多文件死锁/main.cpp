#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using namespace std;

// #pragma once ����ע�⣬�������������������
// include �������1024��

// ���캯�������Ի���������������
// ͷ�ļ�����������������ö��󣬶�������ָ�룬���Ա��벻��ִ��

void test()
{
    // Aclass a;
    // Bclass b; // �ͷŵ�ʱ���������
    Bclass c;
    Aclass d;
    c.show(d);
    d.show(c);
}

int main()
{
    test();
    return 0;
}
