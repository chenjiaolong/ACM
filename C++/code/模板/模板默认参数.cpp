#include <iostream>

using namespace std;
// ��֤���е����Ͳ��������Ƶ���Ĭ�ϣ�ָ����ȷ
// ����������ѭĬ��ֵ����
template<typename T = int, int n = 10> // ģ�����������Ĭ��ֵ
void show(T t)
{
    cout << n << endl;
    cout << t << endl;
}

// ��Լ����Ĳ��������Ͳ���������ָ�������⣬���������ң����븲�����Ͳ���
template<typename T1 = int, typename T2 = int, typename T3 = double, typename T4 = double>
// ����������Ĭ��ͬ�����ұߣ�����Ҫ��Ĭ�ϵ�����˲���ʹ��
void go(T1 t1 = 250.1111, T2 t2 = 250.111, T3 t3 = 250.11, T4 t4 = 250.1)
{
    cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
}

int main()
{
    show<>(250.250); // �Զ�����
    show<int, 250>(250.250);

    go<double, double, double, double>();
    go();
    go(1, 2, 3, 4);
    return 0;
}
