#include <array>
#include <mutex>
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;

condition_variable isfull, isempty; // 处理两种情况
mutex m;
bool flag = true; // 标识消费者完了，退出
// 100，

vector<int>v(10); // 开辟10个空间

void put(int num)
{
    for(int i = 0; i < num; i ++)
    {
        unique_lock<mutex>lk(m); // 锁住
        while(v.size() >= 10)
            isempty.wait(lk); // 满了一直等待
        v.push_back(i);
        cout << "生产" << i << endl;
        isfull.notify_all(); // 通知消费者
    }
    this_thread :: sleep_for(chrono :: seconds(5));
    flag = false;
}
void take()
{
    while(flag)
    {
        unique_lock<mutex>lk(m); // 锁定
        while(v.empty())
        isfull.wait(lk); // 等待

        if(flag)
        {
            cout << "消费" << v[v.size() - 1] << " " << this_thread :: get_id() << endl;
            v.pop_back(); // 消除
            isempty.notify_all(); // 通知生产者
        }
    }
}

int main()
{
    freopen("C:\\Users\\Leon Lee\\Desktop\\test.out", "w", stdout);
    thread t1(take);
    thread t2(take);
    thread t3(take);
    // put(100);
    thread s1(put, 15);
    thread s2(put, 15);

    t1.join();
    t2.join();
    t3.join();

    s1.join();
    s2.join();


//    vector<int> myint{1, 2, 3, 4, 5};
//    // cout << myint[0] << endl;
//    myint.pop_back(); // 删除尾部
//    myint.push_back(19);
//    for(auto i : myint) cout << i << endl;
    return 0;
}
