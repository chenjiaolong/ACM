#include "myarray.h"

myarray::myarray(initializer_list<int> list)
{
    n = list.size(); // ��ȡ��С�������ڴ�
    p = new int[n];

    int id = 0;
    for(auto i : list)
    {
        p[id] = i; // ��������
        id ++;
    }
}

myarray::~myarray()
{
    delete []p;
    n = 0;
}
void myarray::show()
{
    for(int i = 0; i < n; i ++)
        cout << p[i] << endl;
}

