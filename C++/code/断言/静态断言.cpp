#include <cassert>
#include <iostream>

using namespace std;
// static_assert(sizeof(void*) != 8, "IDE is not 64 bits, baby");
// ������ָ��Ĵ�С
int main()
{
    cout << sizeof(void *) << endl;
    const int a = 0;
    // assert(a > 0); // ����ʱ����
    static_assert(a > 0, "> 0, baby");// ���������ԣ����볣��
    return 0;
}


