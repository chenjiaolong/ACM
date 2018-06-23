#include <thread>
#include <iostream>

using namespace std;

// C++代码重用继承
class mmythread : public thread
{
public :
    mmythread() : thread(){  }; // 子类调用父类的构造方法
    template<typename T, typename...Args> // 子类调用父类构造函数，可变参数的构造
    mmythread(T && func, Args && ... args) : thread(forward<T>(func), forward<Args>(args)...)
    {

    }
    void run(const char *cmd) // 新增的功能
    {
        system(cmd);
    }
};

int main()
{
    mmythread t1([](){ cout << "hello, this is maomaoyu!" << endl; });
    t1.run("calc");
    t1.join();

    mmythread t2([](int num){ cout << "hello, maomaoyu!" << num << endl; }, 100);
    t2.run("notepad");
    t2.join();

    return 0;
}
