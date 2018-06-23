#include <iostream>
#include <functional> // 函数包装器

using namespace std;
using std :: function;

int add(int a, int b)
{
    return a + b;
}
template<typename T, typename F>
T run(T t1, T t2, F f)
{
    return f(t1, t2);
}

int main()
{
    function<int(int, int)> fun1 = add; // 包装函数
    function<int(int, int)> fun2 = [](int a, int b) -> int { return a - b; };
    cout << fun1(10, 19) << endl;
    cout << fun2(20, 10) << endl;
    cout << run(19, 29, fun1) << endl;
    cout << run<int, function<int(int, int)>>(19, 29, fun1) << endl;
    return 0;
}
