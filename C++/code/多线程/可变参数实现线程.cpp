#include <thread>
#include <cstdarg>
#include <iostream>

using namespace std;

int go(const char *fmt, ...)
{
    va_list ap; // ָ��
    va_start(ap, fmt); // ��ʼ
    vprintf(fmt, ap); // ����
    va_end(ap); // ����
    return 0;
}

int main()
{
    thread th(go, "%sABCD%d___%c___%x", "12345asd", 98, 'C', 256);
    th.join();
    return 0;
}
