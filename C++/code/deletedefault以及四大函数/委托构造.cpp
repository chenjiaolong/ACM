#include <iostream>

using namespace std;

class A
{
public :
    A() : A(1) { cout << "A()" << endl; }
    A(int i) : A(i, 'A') { cout << "A(int i)" << endl; }
    A(char c) : A(1, c){ cout << "A(char c)" << endl; }
    void show()
    {
        cout << id << " " << ch << endl;
    }
private :
    // ��Ҫ�Ķ��������ڲ�
    A(int i, char c) : id(i), ch(c) { cout << "A(int i, char c)" << endl; } // �����캯����Ŀ�깹��
    int id;
    char ch;
};

int main()
{
    A a;
    a.show();
    return 0;
}
