#include "myArray.h"
#include <stdio.h>

myArray::myArray(initializer_list<initializer_list<int >> list)
{
    n = list.size(); // 开辟指针数组
    p = new int[n]; // 记录每行几个
    pp = new int*[n];// 记录一共有多行行
    int k; // 下标
    for(auto i : list)
    {
        pp[k] = new int[i.size()]; // 再次分配
        p[k] = i.size();
        int l = 0; // 下标
        for(auto j : i)
        {
            pp[k][l] = j;
            l ++;
        }
        k ++; // 循环
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

