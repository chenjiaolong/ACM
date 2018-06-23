#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

// condition_variable
using namespace std;
// �߳�ͨ�ţ����mutex
// һ���̣߳�����̴߳��ڵȴ���֪ͨһ����֪ͨ���
mutex m; // �̻߳����ų�
condition_variable cv; // �߳�ͨ��

int main()
{
    thread **th{ new thread* [10]}; // �����̵߳�ָ������
    for(int i = 0; i < 10; i ++)
    {
        th[i] = new thread([](int index)
        {
            unique_lock<mutex>lck(m); // ����
            cv.wait_for(lck, chrono :: hours(1000)); // һֱ�ȴ�
            cout << index << endl; // ��ӡ���
        }, i); // ���ݲ���
        this_thread :: sleep_for(chrono :: milliseconds(100)); // ��
    }
    for(int i = 0; i < 10; i ++)
    {
        lock_guard<mutex>lckg(m); // ������
        // cv.notify_one(); // ����������֪ͨ
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
