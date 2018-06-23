#include <cstdlib>
#include <iostream>

using namespace std;

// C++ C 语言层
// C语言层管理内存，管理malloc free
// 全局new 局部new 都会被调用一次构造函数
// 管理内存，既调用局部，调用管理
// 局部的类用于管理类对象，全局管理基本数据类型
// 局部new -> 全局new -> malloc -> 构造 , 局部的new -> malloc -> 构造
// 析构 -> 局部delete -> 全局delete -> free， 析构 -> 局部delete -> free

void * mymalloc(size_t size)
{
    cout << "malloc call" << endl;
    return malloc(size);
}
void myfree(void *p)
{
    cout << "free call" << endl;
    free(p);
}

#define malloc mymalloc
#define free myfree

// new 无论局部还是全局都会调用一次构造

void * operator new(size_t size)
{
    cout << "g_all new" << endl;
    void *p(malloc(size));
    return p;
}
void operator delete (void *p)
{
    cout << "g_all delete" << endl;
    free(p);
}

class myclass
{
public :
    myclass()
    {
        cout << "myclass()" << endl;
    }
    ~myclass()
    {
        cout << "~myclass()" << endl;
    }
    void * operator new(size_t size)
    {
        cout << "myclass new" << endl;
        // myclass *p(:: new myclass);
        void *p(malloc(size));
        return p;
    }
    void operator delete (void *p)
    {
        cout << "myclass delete" << endl;
        // :: delete p;
        free(p);
    }

};

int main()
{
//    int *p1(new int(5));
//    int *p2{new int[5]{1, 2, 3, 4, 5}};
    // new delete本质是函数，C++标准库函数，重写

    // 调用局部：重写new delete不实现具体的方法，不再调用析构和构造
    myclass *p(new myclass);
    delete p;

    // 调用全局
//    myclass *p( :: new myclass);
//    :: delete p;

    return 0;
}
