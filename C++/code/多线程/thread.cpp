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
//    // 同步，阻塞
//    run();
//    run();
//    run();
//
//    // 并行，异步，非阻塞
//    thread t1(run); // 根据函数初始化并执行
//    thread t2(run); // 栈上
//    thread t3(run);
//    thread t4(run);

    // thread t[5]{thread(run), thread(run), thread(run), thread(run), thread(run)}; // 初始化

    // 堆上
//    thread *pthread1(new thread(run));
//    thread *pthread2(new thread(run));
//    thread *pthread3(new thread(run));

    // 堆上开辟了线程数组
    thread *pthread(new thread[5] {thread(run), thread(run), thread(run), thread(run), thread(run)});
    system("pause");//不要这句，主线程关闭，出现异常，可用cin.get()替换



    return 0;
}
