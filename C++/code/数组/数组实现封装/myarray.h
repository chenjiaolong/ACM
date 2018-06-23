#pragma once // 只包含一次
#include <iostream>
#include <initializer_list>

using namespace std;

class myarray
{
    int *p;
    int n; // 地址，长度
public:
    myarray(initializer_list<int> list);
    ~myarray();
    void show();
    void operator +(myarray my)
    {
        for(int i = 0; i < n; i ++)
        {
            p[i] += my.p[i];
        }
    }
    void sort()
    {
        for(int i = 0; i < n - 1; i ++)
            for(int j = 0; j < n - i - 1; j ++)
                if(p[j] > p[j + 1])
                {
                    int temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
    }
};
