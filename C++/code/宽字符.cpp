#include <locale>
#include <iostream>

using namespace std;

int main()
{
    // CPP���ַ���ʾ
    // ���ػ�
    // setlocale(LC_ALL, "chs"); // chs: ��������
    // setlocale(LC_ALL, "zh-CN");
    _wsetlocale(LC_ALL, L"zh-CN");
    wchar_t *wp(L"hello maomaoyu");
    wcout << wp << endl;

    return 0;
}
