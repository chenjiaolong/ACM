#include <stdio.h>

// C语言枚举，本质类型检测不严格，允许类型不一致
enum color
{
    red = 10,
    yellow,
    white,
    blue
};

int main()
{
    enum color c1 = 2;
    return 0;
}
