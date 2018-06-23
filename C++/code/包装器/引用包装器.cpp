#include <iostream>
#include <functional>

using namespace std;

template<typename T>
void show(T t) // void show(T &t)�ı�����
{
    cout << t << endl;
    t += 10;
}

void change(int & num) // ������Ϊ����
{
    num = 3;
}

int main()
{
    int data = 100;
    // change(data);
    int &rdata(data);
    change(rdata);
    cout << data << endl;

    double db(1.0);
    // show(db);
    // cout << db << endl;
    double &rdb(db);
    show(ref(rdb)); // ref ���ð�װ��
    cout << db << endl;
    return 0;
}
