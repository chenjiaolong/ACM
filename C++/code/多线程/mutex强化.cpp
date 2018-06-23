#include <mutex>
#include <thread>
#include <iostream>

#define N 100000

using namespace std;

mutex g_mutex; // ȫ�ֻ�����

void add(int *p)
{
    for(int i = 0; i < N; i ++)
    {
        // ӵ��mutex����Ȩ���Զ�����������
        // lock_guard<mutex> lgd(g_mutex); // ������
        // ��ȡʧ�ܵ�����ͻ�һֱ�ȴ�

        // �Զ��������Զ����������ݿ��������
        // ����mutex���ԣ������Ƿ���Լ���
        unique_lock<mutex> ulk(g_mutex);
        (*p) ++;
    }
}

int main()
{
    int a(0);
    thread t1(add, &a);
    thread t2(add, &a);
    t1.join();
    t2.join();

    cout << a <<endl;
    return 0;
}
