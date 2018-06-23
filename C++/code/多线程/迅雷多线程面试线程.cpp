#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;
// ��дһ�����򣬿��������̣߳��������̵߳�ID�ֱ�ΪA��B��C
// ÿ���߳̽��Լ���ID����Ļ�ϴ�ӡ10�飬
// Ҫ������Ľ�����밴��ABC��˳����ʾ���磺ABCABC...���ε��ơ�

int LOOP = 10;
int flag = 0;
mutex m;
condition_variable cv;

void fun(int id)
{
    for(int i = 0; i < LOOP; i ++)
    {
        unique_lock<mutex> ulk(m); // �趨����
        while((id - 65) != flag) cv.wait(ulk); // ���Ǹó��ֵĳ��ϣ��ȴ�
        cout << (char) id; // ת��
        flag = (flag + 1) % 3; // 012,012,
        cv.notify_all(); // ֪ͨȫ��
    }
}


int main()
{
    thread t1(fun, 65);
    thread t2(fun, 66);
    thread t3(fun, 67);

    t1.join();
    t2.join();
    t3.join();
    cout << endl;

    return 0;
}
