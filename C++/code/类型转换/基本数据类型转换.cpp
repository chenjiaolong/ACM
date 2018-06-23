#include <iostream>

using namespace std;

int main()
{
    int a = 1.2; // 自动转换
    int b = static_cast<int > (2.3); // CPP类转换
    int c = (int )2.5; // C风格的转换
    int *p1 = nullptr;
    char *p2 = reinterpret_cast<char *>(p1); // CPP的指针转换，地址复制过来，不管类型

    return 0;
}
