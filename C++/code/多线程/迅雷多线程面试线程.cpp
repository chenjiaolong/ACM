#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;
// 编写一个程序，开启三个线程，这三个线程的ID分别为A、B、C
// 每个线程将自己的ID在屏幕上打印10遍，
// 要求输出的结果必须按照ABC的顺序显示：如：ABCABC...依次递推。

int LOOP = 10;
int flag = 0;
mutex m;
condition_variable cv;

void fun(int id)
{
    for(int i = 0; i < LOOP; i ++)
    {
        unique_lock<mutex> ulk(m); // 设定锁定
        while((id - 65) != flag) cv.wait(ulk); // 不是该出现的场合，等待
        cout << (char) id; // 转换
        flag = (flag + 1) % 3; // 012,012,
        cv.notify_all(); // 通知全部
    }
}


int main()
{
    thread t1(fun, 65);
    thread t2(fun, 66);
    thread t3(fun, 67);

    t1.join();
    t2.join();
    t3.join();
    cout << endl;

    return 0;
}
