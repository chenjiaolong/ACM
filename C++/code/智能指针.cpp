#include <iostream>
#include <memory>
#include <windows.h>

using namespace std;

// 智能指针，内存泄露，自动管理

void cmem()
{
    while(1)
    {
        double *p = new double[1024 * 1024 * 10];
        Sleep(3);
        delete p;// 释放
        Sleep(3);
    }
}
void autoptr()
{
    while(1)
    {
        double *p(new double[1024 * 1024 * 10]);
        auto_ptr<double> autop(p); // 接管，自动回收
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
