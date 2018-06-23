#include <iostream>

// using, 可以省略std
// 制定命名空间
// 原则禁止使用using namespace std; // 明确空间

namespace maomaoyu = std;// 给标准别名，不推荐
// CPP编译器设置，禁止改变标准

namespace stdrun
{
    int num = 101;
    void show()
    {
        std :: cout << num << std :: endl;
    }
}

namespace mmy = stdrun; // 给自定义的别名

int main()
{
    maomaoyu :: cout << "hello" << maomaoyu :: endl;
    mmy :: show();
    return 0;
}
