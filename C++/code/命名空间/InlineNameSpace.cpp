#include <iostream>

using namespace std;
// 软件工程的瀑布模型和迭代式开发
namespace all
{
    namespace V2014
    {
        void fun(int num)
        {
            cout << "int " << " V2014" << endl;
        }
    }
}
namespace all
{
    // inline 展开在all，默认的版本
    inline namespace V2015
    {
        void fun(int num)
        {
            cout << "int " << " V2015" << endl;
        }
        void fun(double num)
        {
            cout << "double " << " V2015" << endl;
        }
    }
}
int main()
{
    all :: V2014 :: fun(1); // 明确调用一个版本
    all :: V2015 :: fun(1);
    all :: fun(1.0); // 指定默认版本
    return 0;
}
