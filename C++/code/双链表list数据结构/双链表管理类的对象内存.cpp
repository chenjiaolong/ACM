#include <list>
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

class myclass; // 类的声明

// 类，函数是共享的，数据是每个对象私有的，
// 空指针，调用成员函数，访问数据，可以调用，访问数据不可以

// 代码区是共享的
struct info
{
    myclass *p; // 指针，内存的首地址
    int n; // 代表多少个对象
};
list<info> myclasslist; // 双链表数据结构，管理一个类的所有对象
struct classinfo
{
    myclass *p;
    int n;
    char name[10]; // 类的名称
};
list<list<classinfo>> myclassList; // 管理多个类的内存

void showmem()
{
    // 显示内存
    for(auto i : myclasslist) cout << "内存地址：" << i.p << "个数：" << i.n << endl;
}

class myclass
{
public :
    int i = 0;
    void show()
    {
        //! i = 0;
        MessageBoxA(0, "content", "title", 0);
    }
    myclass() { cout << "myclass()" << endl; }
    ~myclass() { cout << "~myclass()" << endl; }
    void * operator new(size_t size)
    {
        cout << "new " << size << endl;
        void *p(malloc(size)); // 多个元素
        if(p != nullptr)
        {
            info infonow;
            infonow.p = (myclass *)p; // 分配了就记录一下
            // infonow.n = 1; // 记录地址与个数
            if(size / sizeof(myclass) == 1)
                infonow.n = 1;
            else infonow.n = (size - sizeof(myclass *)) / sizeof(myclass);
            myclasslist.push_back(infonow);
            return p;
        }
        return nullptr;
    }
    void * operator new[](size_t size)
    {
        cout << "new [] " << size << endl;
        return operator new(size); // 回调用new
    }
    void operator delete(void *p)
    {
        // 双链表中检索内存，存在就删除，不存在，忽略
        for(auto ib = myclasslist.begin(), ie = myclasslist.end(); ib != ie; ib ++)
        {
            if(p == (*ib).p)
            {
                myclasslist.erase(ib); // 删除
                free(p);
                break;
            }
        }
    }
    void operator delete[] (void *p)
    {
        operator delete(p); // 回调用delete
    }
};

void callallobject()
{
    for(auto i : myclasslist)
    {
        if(i.n == 1) i.p -> show();
        // 对象数组的第一个地址是数组名
        else for(int j = 0; j < i.n; j ++) i.p[j + 1].show(); // 跳过开头
    }
}

int main()
{
    myclass *p(nullptr);
    p -> show();

    cout << "--------" << endl;
    myclass *p1(new myclass);
    myclass *p2(new myclass);
    myclass *p3(new myclass);
    myclass *p4(new myclass);
    delete p1;
    delete p1;
    showmem();

    delete p2;
    showmem();

    cout << "--------" << endl;
    myclass *pa1{ new myclass[5] };
    myclass *pa2{ new myclass[10] };
    myclass *pa3{ new myclass[15] };
    delete[] pa2;
    delete[] pa3;
    showmem();
    callallobject();

    return 0;
}
