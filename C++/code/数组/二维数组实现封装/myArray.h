#pragma once // ֻ����һ��
#include <iostream>
#include <initializer_list>

using namespace std;

class myArray
{
    int *p;
    int **pp;
    int n; // ��ַ������
public:
    myArray(initializer_list<initializer_list<int >> list);
    ~myArray();
    void show();
};

