#include <locale>
#include <iostream>

using namespace std;

int main()
{
    // CPP宽字符显示
    // 本地化
    // setlocale(LC_ALL, "chs"); // chs: 简体中文
    // setlocale(LC_ALL, "zh-CN");
    _wsetlocale(LC_ALL, L"zh-CN");
    wchar_t *wp(L"hello maomaoyu");
    wcout << wp << endl;

    return 0;
}
