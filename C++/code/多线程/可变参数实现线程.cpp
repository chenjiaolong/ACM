#include <thread>
#include <cstdarg>
#include <iostream>

using namespace std;

int go(const char *fmt, ...)
{
    va_list ap; // 指针
    va_start(ap, fmt); // 开始
    vprintf(fmt, ap); // 调用
    va_end(ap); // 结束
    return 0;
}

int main()
{
    thread th(go, "%sABCD%d___%c___%x", "12345asd", 98, 'C', 256);
    th.join();
    return 0;
}
