#include <iostream>

using namespace std;

// CPP类型转换限定 -> 类型检测
int main()
{
    // char ch(787878); // 不保证结果的正确
    char ch{ 7700 }; // 保证数据类型转换
    cout << (int )ch << endl;

    return 0;
}
