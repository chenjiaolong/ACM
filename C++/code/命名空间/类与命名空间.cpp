#include <iostream>

using namespace std;

// struct拥有class的所有功能
// std拓展标准命名空间
// 数据类型可以放在命名空间，避免数据类型冲突
namespace stdfun
{
    class data
    {
        int a;
        int b;
        int getadd()
        {
            return a + b;
        }
        int getsub();
    };
    void run();
}

namespace stdfun
{
	void run()
	{
		cout << "run" << endl; // 空间拓展
	}
	int getsub();
}
// 命名空间 :: 类型 :: 函数名
int stdfun :: data :: getsub()
{
    return a - b;
}
int main()
{
    stdfun :: data data1;
    data1.a = 11; // 访问变量，调用方法
    data1.b = 21;
    cout << data1.getadd() << endl;
    cout << data1.getsub() << endl;
    return 0;
}
