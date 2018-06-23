#include <iostream>
#include <functional>

using namespace std;
using namespace std :: placeholders;

template<typename T>
void show(T t)
{
    cout << t << endl;
}

struct node
{
    template<typename T>
    void showit(T t)
    {
        cout << t << endl;
    }
    template<typename T>
    void show(T t1, T t2)
    {
        cout << t1 << " " << t2 << endl;
    }
    void go()
    {
        showit(123);
    }
};

int main()
{
    void (*p)(int i) = show<int>;

    node ps;
    ps.go();
    ps.showit(12.3);
    ps.showit<int>('3');

    node q;
    auto fun1 = bind(&node :: show<int >, &q, 1, _1);
    fun1(2);

    auto fun2 = bind(&node :: show<int >, &q, 1, 2);
    fun2();

    return 0;
}
