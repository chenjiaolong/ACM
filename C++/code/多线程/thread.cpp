#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

void run()
{
    MessageBoxA(0, "Content", "Title", 0);
}

int main()
{
//    // ͬ��������
//    run();
//    run();
//    run();
//
//    // ���У��첽��������
//    thread t1(run); // ���ݺ�����ʼ����ִ��
//    thread t2(run); // ջ��
//    thread t3(run);
//    thread t4(run);

    // thread t[5]{thread(run), thread(run), thread(run), thread(run), thread(run)}; // ��ʼ��

    // ����
//    thread *pthread1(new thread(run));
//    thread *pthread2(new thread(run));
//    thread *pthread3(new thread(run));

    // ���Ͽ������߳�����
    thread *pthread(new thread[5] {thread(run), thread(run), thread(run), thread(run), thread(run)});
    system("pause");//��Ҫ��䣬���̹߳رգ������쳣������cin.get()�滻



    return 0;
}
