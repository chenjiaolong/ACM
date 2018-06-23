#include <iostream>

using namespace std;
// 全局内存管理，统计释放内存，分配内存
// new  new[]  delete  delete[]
// 分配内存优先于构造函数
// 析构函数优先于释放内存

// 优先级:
// new -> 构造函数(new -> :: new -> malloc -> create)
// 析构函数 -> delete(析构函数 -> delete -> :: delete -> free)

class myclass
{
public :
    myclass() { cout << "create call" << endl; }
    ~myclass() { cout << "delete call" << endl; }
};

class all
{
    char ch;
    void run(int d)
    {

    }
};

void * operator new(size_t size)
{
    cout << "g_new call" << endl;
    void *p(malloc(size));
    return p;
}
void * operator new [](size_t size)
{
    cout << size << endl; // 18 = 一个指针占8个字节，10个空类占10字节
    cout << "g_new call []" << endl;
    return operator new(size); // 每个元素调用一次new
}

void operator delete(void *p)
{
    cout << "g_delete call" << endl;
    free(p);
}
void operator delete [](void *p)
{
    cout << "g_delete call []" << endl;
    operator delete(p);
}

// sizeof统计类的大小，原则，不统计代码区
// 空类占1个字节表示存在，等价于结构体
int main()
{
    int *p(new int(5));
    delete p;

    cout << "--------" << endl;
    // :: new
    myclass *ptr(new myclass);
    delete ptr;

    cout << "--------" << endl;
    int *pint { new int[10] };
    delete pint;

    cout << "--------" << endl;
    myclass *px{ new myclass[10] };
    delete[] px;

    cout << sizeof(all) << endl;

    return 0;
}

