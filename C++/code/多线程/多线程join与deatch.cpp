#include <array>
#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;
// join��ǰ���̵߳ȴ��������߳�ִ����ɲ����˳�
// deatch�������̵߳İ󶨣����߳��˳���ʱ�򣬲�Ӱ�����߳�

void show()
{
    MessageBox(0, "content", "title", 0);
}


int main()
{
    array<thread, 3> threads{thread(show), thread(show), thread(show)};
    for(int i = 0; i < 3; i ++)
    {
        // �Ƿ����join���ж�
        cout << threads[i].joinable() << endl;
        threads[i].join(); // ���̵߳ȴ���ǰ�߳�ִ��������˳�
        // cout << threads[i].joinable() << endl;
    }

    // ��ȡCPU�Ĵ�����
    auto n = thread :: hardware_concurrency();
    cout << n << endl;

    thread th(show);
    // th.join();
    th.detach(); // �������̵߳Ĺܿأ����̹߳��ˣ��������Զ��˳�
    // deatch �Ժ��߳��޷�ͨ��
    cout << th.joinable() << endl;;
    // cin.get();
    return 0;
}
