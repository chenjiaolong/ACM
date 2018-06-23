#include <iostream>

using namespace std;

int objs = 0;
void *g_p = nullptr;

class myclass
{
public :
    myclass() { cout << "create" << endl; }
    ~myclass() { cout << "delete" << endl; }
    // operator重载，针对new 重新作出一种解释，只针对当前类
    static void * operator new (size_t size)
    {
        if(g_p == nullptr)
        {
            objs ++;
            cout << "new call" << endl;
            // return nullptr;
            myclass *p = :: new myclass;
            g_p = p; // 单例模式
            return p;
        }
        return g_p;
    }
    static void operator delete (void *p)
    {
        if(g_p == nullptr) return ;
        objs --;
        cout << "delete call" << endl;
        :: delete p;
        g_p = nullptr;
    }
};

// 第一个功能，无法在堆上被创建的类
// 实现统计分配内存，释放内存的次数
// 实现单例设计模式，实现避免反复delete出错。
// new delete 在内部，只针对当前类，int double 等基本数据类型无影响
int main()
{
    myclass *p1 = new myclass;
    myclass *p2 = new myclass;
    myclass *p3 = new myclass;
    delete p1;
    delete p1;
    cout << objs << endl;
    delete p2;
    delete p3;

    int *p = new int;
    delete p;

    return 0;
}
