#include <cstdlib>
#include <iostream>

#define f(x) x*x*x // C����������C++Ҫ�������ϸ�

using namespace std;

inline int get(int x); // C++ ����������

template<typename T>
inline T go(T t)
{
    return t * t;
}

// ��߳��������ٶ�
/**
  * inline ֻ�Ƕ��ڱ������Ľ���
  * һ������£����Ƕ��������������µ����ƣ�
  * ��1�������еݹ�
  * ��2�����ܰ�����̬����
  * ��3�����ܰ���ѭ��
  * ��4�����ܰ���switch��goto���
  * ��5�����ܰ�������
  */
// ��һ�������������岻�����������ƣ������ϵͳ����������ͨ�����Դ���
int main()
{

    auto fun = [](){}; // Ҳ����������
    // cout << (void *) fun << endl;
    cout << go(5) << endl; // �Ż�Ϊ��������
    cout << get(10) << endl;
    return 0;
}
inline int get(int x) // C++ ������������inline����ʡ�ԣ� ���ͣ����Ͱ�ȫ
{
    return x * x * x;
}
