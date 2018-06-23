#include <thread>
#include <cstdlib>
#include <iostream>

using namespace std;

class mythread : public thread
{
public :
    static int data;
    mythread() : thread() {  }; // ������ø��๹�캯��
    template<typename T, typename... Args> // ������ø��๹�캯�����ɱ����ģ��
    mythread(T &&func, Args &&... args) : thread(forward<T>(func), forward<Args>(args)...) {  };
};
int mythread :: data  = 0; // ��ľ�̬�������κε�ǰ�߳��඼�ɷ���
// Ӧ�ã�ͳ�ƶ���ĸ��������̣߳���ͣ�ߣ���

// ���ģʽ����ͣ��ģʽ
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
