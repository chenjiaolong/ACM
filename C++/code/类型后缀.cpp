#include <iostream>

using namespace std;

struct suffix
{
    unsigned int num;
};
// operator "" _s���Ӻ�׺
// �ı������
// �����б�Ӧ��Ϊchar��wchar_t��char16_t��char32_t��unsigned long long
// �ı���׺��������ⲿ
suffix operator "" _s(unsigned long long data)
{
    // ���ṹ���ʼ�������ݵ���������ܵ�����һ�¡�����װ��
    return { (unsigned int)data };
}

int main()
{
    suffix p = 12_s;
    cout << p.num << endl;
    return 0;
}
