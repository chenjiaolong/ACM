#include <iostream>

using namespace std;

void show(int num)
{
    cout << num << endl;
}
void show1(double num)
{
    cout << num + 1 << endl;
}
template<typename T>
void showit(T num)
{
    cout << num << endl;
}

// ���ͽӿڣ��κ��������ͣ����ݺ���ָ��
template<typename T, typename F>
void run(T t, F f)
{
    f(t);
}

int main()
{
    run(10, show);
    run(10.1, show1);
    //! run("abc", showit<char *>);// Error! ���ܴ�const char* ת��Ϊ char*
    run("abc", showit<const char *>);
    // �ӿڣ��ϸ����ͣ�
    return 0;
}
