#include <iostream>

using namespace std;

// 命名空间没有私有，全局变量，函数都公有都可以访问
namespace data
{
    int num;
    void show()
    {
        cout << num << endl;
    }
}

using namespace data; // 使用命名空间，直接访问当作全局变量

// 内层覆盖外层
namespace dataX
{
    int num = 100;
    namespace run
    {
        int num = 10;
        void show()
        {
            // cout << num << endl;

            // :: num 直接全局变量，全局变量不存在就是0
            // cout << :: num << endl;

            cout << dataX :: num << endl;
        }
    }

}

using namespace dataX; // 使用命名空间必须在定义之后

int main()
{
    data :: num = 15;
    show();
    dataX :: run :: show();
    run :: show();
    return 0;
}
