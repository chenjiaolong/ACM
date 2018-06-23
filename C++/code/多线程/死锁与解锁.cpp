#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>

#define COUNT 1000

using namespace std;
// thread���������ͺ�����ģ�壬��������ת��������ʹ��ָ�룬��������
// ��סһ������֮�󣬾���������������Ҫ������������������ụ��

mutex g_mutex1, g_mutex2; // ������

void add1(int *p1, int *p2)
{
    for(int i = 0; i < COUNT; i ++)
    {
        // ����
        /* g_mutex1.lock();
        (*p1) ++;
        g_mutex2.lock();
        (*p2) ++;
        g_mutex1.unlock();
        g_mutex2.unlock();*/

        g_mutex1.lock();
        (*p1) ++;
        g_mutex1.unlock();

        g_mutex2.lock();
        (*p2) ++;
        g_mutex2.unlock();
    }

}
void add2(int *p1, int *p2)
{
    for(int i = 0; i < COUNT; i ++)
    {
        // ����
        /* g_mutex2.lock();
        g_mutex1.lock();
        (*p1) ++;
        g_mutex1.unlock();
        (*p2) ++;
        g_mutex2.unlock();*/

        g_mutex2.lock();
        (*p2) ++;
        g_mutex2.unlock();

        g_mutex1.lock();
        (*p1) ++;
        g_mutex1.unlock();
    }
}

int main()
{
    int a(0), b(0);
    thread th1(add1, &a, &b);
    thread th2(add2, &a, &b);

    th1.join();
    th2.join();

    // while(1)
    {
        cout << a << " " << b << endl;
        // this_thread :: sleep_for(chrono :: seconds(1));
    }

    return 0;
}
