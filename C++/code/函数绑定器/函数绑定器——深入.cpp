#include <iostream>
#include <functional>

using namespace std;
using namespace std :: placeholders;

struct node
{
    int operator() (int a, int b)
    {
        cout << "a = " << a << " b = " << b << endl;
        return a + b;
    }
};

int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    // ÊÊÅäÆ÷Ä£Ê½
    auto fun1 = bind(add, 10, 12, _1);
    cout << fun1(1100) << endl;

    auto fun2 = bind([](int a, int b) -> int { return a + b; }, 100, _1);
    cout << fun2(123) << endl;

    node p;
    cout << p(1, 2) << endl;
    auto fun3 = bind(p, 100, _1);
    cout << fun3(123) << endl;

    return 0;
}
