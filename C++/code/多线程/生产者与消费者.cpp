#include <array>
#include <mutex>
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;

condition_variable isfull, isempty; // �����������
mutex m;
bool flag = true; // ��ʶ���������ˣ��˳�
// 100��

vector<int>v(10); // ����10���ռ�

void put(int num)
{
    for(int i = 0; i < num; i ++)
    {
        unique_lock<mutex>lk(m); // ��ס
        while(v.size() >= 10)
            isempty.wait(lk); // ����һֱ�ȴ�
        v.push_back(i);
        cout << "����" << i << endl;
        isfull.notify_all(); // ֪ͨ������
    }
    this_thread :: sleep_for(chrono :: seconds(5));
    flag = false;
}
void take()
{
    while(flag)
    {
        unique_lock<mutex>lk(m); // ����
        while(v.empty())
        isfull.wait(lk); // �ȴ�

        if(flag)
        {
            cout << "����" << v[v.size() - 1] << " " << this_thread :: get_id() << endl;
            v.pop_back(); // ����
            isempty.notify_all(); // ֪ͨ������
        }
    }
}

int main()
{
    freopen("C:\\Users\\Leon Lee\\Desktop\\test.out", "w", stdout);
    thread t1(take);
    thread t2(take);
    thread t3(take);
    // put(100);
    thread s1(put, 15);
    thread s2(put, 15);

    t1.join();
    t2.join();
    t3.join();

    s1.join();
    s2.join();


//    vector<int> myint{1, 2, 3, 4, 5};
//    // cout << myint[0] << endl;
//    myint.pop_back(); // ɾ��β��
//    myint.push_back(19);
//    for(auto i : myint) cout << i << endl;
    return 0;
}
