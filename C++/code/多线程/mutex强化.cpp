#include <mutex>
#include <thread>
#include <iostream>

#define N 100000

using namespace std;

mutex g_mutex; // 全局互斥量

void add(int *p)
{
    for(int i = 0; i < N; i ++)
    {
        // 拥有mutex所有权，自动加锁，解锁
        // lock_guard<mutex> lgd(g_mutex); // 锁定向导
        // 读取失败的情况就会一直等待

        // 自动加锁，自动解锁，根据块语句锁定
        // 根据mutex属性，决定是否可以加锁
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
