#include <cstdlib>
#include <iostream>

using namespace std;

// char str[1024]{0}; // 内存静态区

// 静态区，栈区，堆区
// int *p2(new (str) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
// 堆区，delete p2
// 栈区，静态区，可以覆盖重写，不可以delete p2


int main()
{
    // char str[1024]{0}; // 内存栈区
    char *str(new char[1024]{0}); // 堆区

    // 堆上开辟内存
    int *p1(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // 一定在堆区
    int *p2(new (str) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // 分配内存，str开始的地址
    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

    cout << "---------------" << endl;
    free(str); // 释放
    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

//    cout << "---------------" << endl;
//    p1 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    p2 = new (str + 40) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; //! 栈区和静态区 free(str)后内存泄露，强行指定内存，再次分配
//    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;
//
//    cout << "---------------" << endl;
//    p1 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    p2 = new (str + 40) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

    return 0;
}
