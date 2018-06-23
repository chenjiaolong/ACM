#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// union内部如果有自定义的类，有自己的构造函数，union原来的构造函数和析构函数会被删除，必须自己实现
union U
{
    string str; // string是一个类，自己有构造函数
    int a;
    int b;
};

union Union
{
    string str;
    int a;
    int b;
    Union()
    {
        new(&str)string; // 调用string构造函数
    }
    ~Union()
    {
        str.~basic_string(); // 析构
    }
};

struct node
{
    string str;
    int a;
    int b;
};
// 初始化数据的时候，如果类中引用其它类，重写构造函数
struct Node
{
    int x, y;
    Node(int a, int b) : x(a), y(b){  }
};
class Per
{
    string str;
    int a;
    int b;
};

int main()
{
    //! U u;
    node p;
    Per o;
    Union u;

    Node *ptr = new Node[3]{{1, 2}, {2, 3}, {3, 4}};
    for(int i = 0; i < 3; i ++)
        cout << ptr[i].x << " " << ptr[i].y << endl;

    return 0;
}
