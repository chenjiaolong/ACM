#include <cstdlib>
#include <iostream>

using namespace std;

// ���ģʽ�����ģʽ
// C����û��Ĭ�ϲ�����ֵ
// �������Կ��ٵ���
// ʡ�Բ�����CPP����
// Ĭ�ϲ��������ұ߿�ʼ��������ջ����������
// ��Ĭ�ϵĲ�����������ߣ�Ĭ���ұ�
int add(int a, int b, int c = 1, int d = 1)
{
    return a + b + c + d;
}
void run(const char *str = "notepad")
{
    system(str);
}
int main()
{
    // cout << add(1) << endl; ��Ĭ�ϵĲ��������봫��
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    cout << add(1, 2, 3, 4) << endl;
    run();
    return 0;
}
