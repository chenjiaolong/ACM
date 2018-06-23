#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using namespace std;

// #pragma once 必须注意，否则死锁（互相包含）
// include 最深层是1024层

// 构造函数不可以互相包含，造成死锁
// 头文件互相包含，互相引用对象，对象，引用指针，可以编译不可执行

void test()
{
    // Aclass a;
    // Bclass b; // 释放的时候从下往上
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
