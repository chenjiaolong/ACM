#include <mutex>
#include <chrono> // 时间
#include <thread>
#include <future> // 线程将来结果
#include <iostream>

using namespace std;

mutex g_m;

int main()
{
    auto run = [=](int index) -> int
    {
        lock_guard<mutex>lckg(g_m); // 加锁
        cout << this_thread :: get_id() << " " << index << endl; // 获取线程id
        this_thread :: sleep_for(chrono :: seconds(10));
        return index * 1024;  // 返回结果
    };
    packaged_task<int(int)> pt1(run);
    packaged_task<int(int)> pt2(run); // 创建两个任务包
    thread t1([&](){ pt1(2);});
    thread t2([&](){ pt2(3);}); //  开启线程
    cout << pt1.get_future().get() << endl;
    cout << pt2.get_future().get() << endl;

    t1.join();
    t2.join();
    return 0;
}
