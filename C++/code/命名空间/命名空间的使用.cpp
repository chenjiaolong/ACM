#include <cstdlib>
#include <iostream>

using namespace std;

namespace string1
{
    char str[10]{"calc"};
}
namespace string2
{
    char str[10]{"notepad"};
}
// 命名空间拓展，名称相同意味着同一个命名空间
// 瀑布式开发
namespace string2
{
    char cmd[10]{"mspaint"};
    void show()
    {
        cout << cmd << endl;
    }
}

// 命名空间，可以无限嵌套
namespace run
{
    namespace runit
    {
        namespace runitout
        {
            int num = 100;
            void show()
            {
                cout << num << endl;
            }
        }
    }
}

int main()
{
    system(string1 :: str);
    system(string2 :: str);
    system(string2 :: cmd);
    string2 :: show(); // 命名空间大的函数与变量

    run :: runit :: runitout :: num = 199;
    run :: runit :: runitout :: show();

    return 0;
}
