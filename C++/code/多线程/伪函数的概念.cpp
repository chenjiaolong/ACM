#include <iostream>

using namespace std;

struct func
{
    void operator()() // ���������Խ�����������������ʹ��
    {
        cout << "hello china hello cpp" << endl;
    }
    void operator()(int i) // ���������Խ�����������������ʹ��
    {
        cout << "hello china hello cpp " << i << endl;
    }
};

int main()
{
    func f1;
    f1();

    func f2;
    f2(1);


    return 0;
}
