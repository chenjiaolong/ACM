#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    auto fun = []()
    {
        MessageBoxA(0, "content", "title", 0);
    };
    thread thread1(fun);
    thread thread2(fun);
    thread thread3([]()
    {
        this_thread :: sleep_for(chrono :: seconds(3));
        this_thread :: yield(); // ��CPU��ִ�������̣߳�����ʱ��ִ�б��߳�
        cout << this_thread :: get_id() << endl;
        //! this_thread :: sleep_until(); // ��ĳ��ʱ��֮ǰһֱ�ȴ�
    });
    thread thread4([]()
    {
        this_thread :: sleep_for(chrono :: seconds(10));
        cout << this_thread :: get_id() << endl;
    });
    cin.get();
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}
