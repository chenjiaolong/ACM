#include <iostream>

using namespace std;

struct func
{
    void operator()() // 方法，可以将对象名当作函数名使用
    {
        cout << "hello china hello cpp" << endl;
    }
    void operator()(int i) // 方法，可以将对象名当作函数名使用
    {
        cout << "hello china hello cpp " << i << endl;
    }
};

int main()
{
    func f1;
    f1();

    func f2;
    f2(1);


    return 0;
}
