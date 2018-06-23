#include <array>
#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;
// join当前主线程等待所有子线程执行完成才能退出
// deatch脱离主线程的绑定，主线程退出的时候，不影响子线程

void show()
{
    MessageBox(0, "content", "title", 0);
}


int main()
{
    array<thread, 3> threads{thread(show), thread(show), thread(show)};
    for(int i = 0; i < 3; i ++)
    {
        // 是否可以join，判断
        cout << threads[i].joinable() << endl;
        threads[i].join(); // 主线程等待当前线程执行完成再退出
        // cout << threads[i].joinable() << endl;
    }

    // 获取CPU的处理器
    auto n = thread :: hardware_concurrency();
    cout << n << endl;

    thread th(show);
    // th.join();
    th.detach(); // 脱离主线程的管控，主线程挂了，不报错，自动退出
    // deatch 以后线程无法通信
    cout << th.joinable() << endl;;
    // cin.get();
    return 0;
}
