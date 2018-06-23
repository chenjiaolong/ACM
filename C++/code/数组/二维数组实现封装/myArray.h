#pragma once // 只包含一次
#include <iostream>
#include <initializer_list>

using namespace std;

class myArray
{
    int *p;
    int **pp;
    int n; // 地址，长度
public:
    myArray(initializer_list<initializer_list<int >> list);
    ~myArray();
    void show();
};

