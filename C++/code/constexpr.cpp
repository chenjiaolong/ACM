#include <iostream>

using namespace std;

// constexpr ��־����ֵ���������ʽ�ǳ���
constexpr int get()
{
    return 5;
}

int main()
{
    int a[5 + get()];
    return 0;
}
