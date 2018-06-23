#include <iostream>

using namespace std;

struct suffix
{
    unsigned int num;
};
// operator "" _s增加后缀
// 文本运算符
// 参数列表应该为char、wchar_t、char16_t、char32_t或unsigned long long
// 文本后缀必须放在外部
suffix operator "" _s(unsigned long long data)
{
    // 给结构体初始化，传递的数据域接受的数据一致。伸缩装换
    return { (unsigned int)data };
}

int main()
{
    suffix p = 12_s;
    cout << p.num << endl;
    return 0;
}
