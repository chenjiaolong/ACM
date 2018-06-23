#include "myArray.h"
#include <stdio.h>

myArray::myArray(initializer_list<initializer_list<int >> list)
{
    n = list.size(); // ����ָ������
    p = new int[n]; // ��¼ÿ�м���
    pp = new int*[n];// ��¼һ���ж�����
    int k; // �±�
    for(auto i : list)
    {
        pp[k] = new int[i.size()]; // �ٴη���
        p[k] = i.size();
        int l = 0; // �±�
        for(auto j : i)
        {
            pp[k][l] = j;
            l ++;
        }
        k ++; // ѭ��
    }
}

myArray::~myArray()
{
    for(int i = 0; i < n; i ++)
        delete pp[i];
    delete[] pp;
    delete[] p;
}
void myArray::show()
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < p[i]; j ++)
            cout << pp[i][j] << " ";
        puts("");
    }
}

