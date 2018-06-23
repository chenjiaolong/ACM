#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

// atomic
// int num = 0;
// �̰߳�ȫ�����̷߳��ʲ���ͻ����ͻ���ǲ���ȫ��
// mutex m; // ���⣬���������˷�ʱ��

atomic_int num{0}; // ���ᷢ���̳߳�ͻ���̰߳�ȫ
void run()
{
    for(int i = 0; i < 10000000; i ++)
    {
        // m.lock();
        num ++;
        // m.unlock();
    }
}


int main()
{
    clock_t start = clock();
    thread th1(run);
    thread th2(run);
    th1.join();
    th2.join();

    clockid_t end = clock();
    cout << num << endl;
    cout << end - start << "ms" << endl;
    return 0;
}
// ȫ�ֱ�������ͻ���������ȷ���ٶȿ�
// mutex �����ȷ���ٶ���
// atomic �����mutex��

