#include <thread>
#include <future>
#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

promise<string>val; // ȫ��ͨ�ű���
promise<int>vall;

int main()
{
    string str1("12345");
    string str2("12345");
    string str3(str1 + str2); // C++ �����ַ���
    cout << str3  << endl;

    cout << "-------" << endl;
    thread th1([]()
    {
        future<string> fu = val.get_future(); // ��ȡδ����״̬
        cout << "�ȴ���" << endl;
        cout << fu.get() << endl;
    });
    thread th2([]()
    {
        system("pause");
        val.set_value("maomaoyu with junge");
        system("pause");
    });
    th1.join();
    th2.join();

    cout << "-------" << endl;
    thread th3([]()
    {
        future<int> fu = vall.get_future(); // ��ȡδ����״̬
        cout << "�ȴ���" << endl;
        cout << fu.get() << endl;
    });
    thread th4([]()
    {
        system("pause");
        vall.set_value(5201314);
        system("pause");
    });
    th3.join();
    th4.join();

    system("pause");
    return 0;
}
