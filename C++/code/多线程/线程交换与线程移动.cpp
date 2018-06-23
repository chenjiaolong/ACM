#include <thread>
#include <iostream>

using namespace std;
// �����߳�

int main()
{
    thread t1([]()
    {
        cout << "maomao" << endl;
    });
    thread t2([]()
    {
        cout << "yu" << endl;
    });

    cout << "t1.get_id() = " << t1.get_id() << ", t2.get_id() = " << t2.get_id() << endl;
    swap(t1, t2);
    cout << "t1.get_id() = " << t1.get_id() << ", t2.get_id() = " << t2.get_id() << endl;

    t1.join();
    t2.join();

    cout << "---------" << endl;
    thread t3([]()
    {
        int i;
        while(1)
        {
            i ++;
            if(i > 100000000) break;
        }
        cout << i << endl;
        system("pause");
    });
    cout << "t3.get_id() = " << t3.get_id() << endl;
    thread t4 = move(t3); // �߳��ƶ���t4�߱�t3������
    cout << "t3.get_id() = " << t3.get_id() << endl;
    cout << "t4.get_id() = " << t4.get_id() << endl;
    t4.join();

    return 0;
}
