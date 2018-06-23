#include <thread>
#include <iostream>

using namespace std;

// C++�������ü̳�
class mmythread : public thread
{
public :
    mmythread() : thread(){  }; // ������ø���Ĺ��췽��
    template<typename T, typename...Args> // ������ø��๹�캯�����ɱ�����Ĺ���
    mmythread(T && func, Args && ... args) : thread(forward<T>(func), forward<Args>(args)...)
    {

    }
    void run(const char *cmd) // �����Ĺ���
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
