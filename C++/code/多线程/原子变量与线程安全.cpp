#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

// atomic
// int num = 0;
// 线程安全，多线程访问不冲突，冲突就是不安全的
// mutex m; // 互斥，加锁解锁浪费时间

atomic_int num{0}; // 不会发生线程冲突，线程安全
void run()
{
    for(int i = 0; i < 10000000; i ++)
    {
        // m.lock();
        num ++;
        // m.unlock();
    }
}


int main()
{
    clock_t start = clock();
    thread th1(run);
    thread th2(run);
    th1.join();
    th2.join();

    clockid_t end = clock();
    cout << num << endl;
    cout << end - start << "ms" << endl;
    return 0;
}
// 全局变量，冲突，结果不正确，速度快
// mutex 结果正确，速度慢
// atomic 结果比mutex快

