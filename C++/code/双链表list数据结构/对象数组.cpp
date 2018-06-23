#include <list>
#include <cstdlib>
#include <iostream>

using namespace std;

// 如果类里存在有构造函数与析构函数，也占用类的私有空间
class go
{
public :
    int num;
    void *operator new (size_t size)
    {
        cout << "new " << size << endl;
        void *p(malloc(size));
        return p;
    }
    void *operator new[] (size_t size)
    {
        cout << "new []" << size << endl;
        return operator new(size);
    }
};

void *operator new (size_t size)
{
     cout << "g_new" << size << endl;
    void *p(malloc(size));
    return p;
}
void *operator new[] (size_t size)
{
    cout << "g_new []" << size << endl;
    return operator new(size);
}


int main()
{
    go *p { new go[10] }; // 40 字节


    return 0;
}
