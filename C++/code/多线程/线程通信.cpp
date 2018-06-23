#include <thread>
#include <cstdlib>
#include <iostream>

using namespace std;

class mythread : public thread
{
public :
    static int data;
    mythread() : thread() {  }; // 子类调用父类构造函数
    template<typename T, typename... Args> // 子类调用父类构造函数，可变参数模板
    mythread(T &&func, Args &&... args) : thread(forward<T>(func), forward<Args>(args)...) {  };
};
int mythread :: data  = 0; // 类的静态变量，任何当前线程类都可访问
// 应用：统计对象的个数，多线程（调停者），

// 设计模式：调停者模式
void go()
{
    while(1)
    {
        mythread :: data += 1;
        cout << this_thread :: get_id() << " " << mythread :: data << endl;
        this_thread :: sleep_for(chrono :: seconds(3));
    }
}

int main()
{
    mythread my1(go);
    mythread my2(go);
    mythread my3(go);
    mythread my4(go);
    my1.join();
    my2.join();
    my3.join();
    my4.join();
    return 0;
}
