#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

// condition_variable
using namespace std;
// 线程通信，结合mutex
// 一个线程，多个线程处于等待，通知一个或通知多个
mutex m; // 线程互相排斥
condition_variable cv; // 线程通信

int main()
{
    thread **th{ new thread* [10]}; // 开辟线程的指针数组
    for(int i = 0; i < 10; i ++)
    {
        th[i] = new thread([](int index)
        {
            unique_lock<mutex>lck(m); // 锁定
            cv.wait_for(lck, chrono :: hours(1000)); // 一直等待
            cout << index << endl; // 打印编号
        }, i); // 传递参数
        this_thread :: sleep_for(chrono :: milliseconds(100)); // 错开
    }
    for(int i = 0; i < 10; i ++)
    {
        lock_guard<mutex>lckg(m); // 解锁向导
        // cv.notify_one(); // 挨个挨个的通知
    }
    cv.notify_all();
    for(int i = 0; i < 10; i ++)
    {
        th[i] -> join();
        delete th[i];
    }
    delete[] th;

    return 0;
}
