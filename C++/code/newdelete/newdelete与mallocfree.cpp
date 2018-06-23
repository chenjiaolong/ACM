#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;


class mydata
{
public :
    void *p;
    mydata() { cout << "mydata create" << endl;
    p = malloc(1024 * 1024 * 1024); // 分配
     }
    ~mydata() { cout << "mydata delete" << endl;
    free(p); // 释放
     }
};
// mydata d1; // 创建对象，自动调用构造函数
void test()
{
    mydata d1; // 栈上,创建调用构造函数，销毁调用析构函数
}
int main()
{
    // 基本数据类型， int double char
    int *p(new int(5));
    cout << (void *)p << "  p = " << p << endl;
    delete p;
    // free(p);
    p = nullptr; // delete 不会改变指针的值，避免迷途指针，指针设定为nullptr
    cout << "   p = " << p << endl;
    // delete p;

    // delete free 对于基本数据类型，释放，释放两次都会出错
    // free不改变指针的值，delete会改变


    cout << "------------" << endl;
    int *ptr = (int *)malloc(4);
    *ptr = 4;
    free(p);// 基本数据类型，free malloc new delete 效果一致

    // test();
    // puts("OK");

    mydata *pNew = new mydata;

    delete pNew; // 自动调用，构造，析构
    // free(pNew); // free 不会调用析构函数

    mydata *pMalloc = (mydata *) malloc(sizeof(mydata));

    free(pMalloc);
    //! delete pMalloc; // 内存泄露

    system("pause");


    return 0;
}
