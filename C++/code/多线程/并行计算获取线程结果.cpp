#include <mutex>
#include <chrono> // ʱ��
#include <thread>
#include <future> // �߳̽������
#include <iostream>

using namespace std;

mutex g_m;

int main()
{
    auto run = [=](int index) -> int
    {
        lock_guard<mutex>lckg(g_m); // ����
        cout << this_thread :: get_id() << " " << index << endl; // ��ȡ�߳�id
        this_thread :: sleep_for(chrono :: seconds(10));
        return index * 1024;  // ���ؽ��
    };
    packaged_task<int(int)> pt1(run);
    packaged_task<int(int)> pt2(run); // �������������
    thread t1([&](){ pt1(2);});
    thread t2([&](){ pt2(3);}); //  �����߳�
    cout << pt1.get_future().get() << endl;
    cout << pt2.get_future().get() << endl;

    t1.join();
    t2.join();
    return 0;
}
