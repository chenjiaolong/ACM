#include <iostream>
#include <functional> // 包装的头文件

using namespace std;

using std :: function; // 函数包装

void go()
{
   cout << "go" << endl;
}
int add(int a, int b)
{
    return a + b;
}
int main()
{
            // 返回值，参数
    function<void(void)> fun1 = go;
    fun1();

    cout << "---------" << endl;
    function<void(void)> fun2 = [](){ cout << "go lambda" << endl; };
    fun2();

    cout << "---------" << endl;
    function<int(int, int)> fun3 = add;
    cout << fun3(10, 19) << endl;

    cout << "---------" << endl;
    function<int(int, int)> fun4 = [](int a, int b) -> int{ return a + b; };
    cout << fun4(10, 9) << endl;
    return 0;
}
