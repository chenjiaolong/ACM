#include <mutex>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
bool done = false;

void run()
{
    auto start = chrono :: high_resolution_clock :: now(); // 当前时间
    auto end = start + chrono :: seconds(10);

    unique_lock<mutex> lk(m);
    while(!done)
    {
        if(cv.wait_until(lk, end) == cv_status :: timeout) // 超时
        {
            done = true;
            break;
        }
    }
    // 线程等待不用sleep_until
    // this_thread :: sleep_until(end);
    system("pause");
}

int main()
{
//    thread th(run);
//    th.join();
    time_t t1, t2;
    auto start = chrono :: high_resolution_clock :: now();
    t1 = time(&t1);
    double db = 0;
    for(int i = 0; i < 1000000000; i ++)
        db += i;
    auto end = chrono :: high_resolution_clock :: now();
    t2 = time(&t2);
    cout << difftime(t2, t1) << endl; // 精确度低下
    cout << (end - start).count() << endl; // 10^(-9)秒 精确度高


    return 0;
}
