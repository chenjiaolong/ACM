#include <iostream>
#include <functional>

using namespace std;

template<typename T>
void show(T t) // void show(T &t)改变引用
{
    cout << t << endl;
    t += 10;
}

void change(int & num) // 引用作为参数
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
    show(ref(rdb)); // ref 引用包装器
    cout << db << endl;
    return 0;
}
