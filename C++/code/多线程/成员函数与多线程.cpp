#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

struct fun
{
    int i;
    void run()
    {
        // i = 3;
        MessageBoxA(0, "content", "title", 0);
        cout << "hello china hello cpp" << endl;
    }
    void runit(const char *str)
    {
        // i = 3;
        MessageBoxA(0, str, str, 0);
        cout << "hello china hello cpp" << endl;
    }

};

int main()
{
    // fun *p(nullptr);
    // p -> run(); // ����ָ���������û�е����ڲ������ĳ�Ա����

    fun fun1;
    // & fun1 :: run ���ó�Ա����
    thread th1(& fun :: run, fun1);
    thread th2(& fun :: run, fun1);
    thread th3(& fun :: runit, fun1, "maomaoyu");
    thread th4(& fun :: runit, fun1, "liufangjun"); // ���ݲ���ģʽ
    system("pause");

    return 0;
}
