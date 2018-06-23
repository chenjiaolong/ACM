#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

// void operator()() ����������������������()
// ()���������ڵ�ǰ�ṹ�����
// ���ʺ���Ϊ���̲߳����� ����̫��


struct MyStruct
{
    MyStruct() { cout << "create" << endl; }
    ~MyStruct() { cout << "end"  << endl; }
    void operator()()
    {
        MessageBoxA(0, "content", "title", 0);
    }
};

int main()
{
    MyStruct go1;
    thread t1(go1);

    MyStruct go2;
    thread t2(go2);

    thread t3(MyStruct()); // ���ʺ���Ϊ���̲߳����� ����̫��

    MyStruct *p(new MyStruct());

    // int a(5);
    // int*p = new int(5); // ()��ʼ�������캯��

    // MyStruct() ���캯��������һ����ʱ������������
    MyStruct()();

    system("pause");
    return 0;
}
