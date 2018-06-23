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
    // 重要的东西放在内部
    A(int i, char c) : id(i), ch(c) { cout << "A(int i, char c)" << endl; } // 主构造函数，目标构造
    int id;
    char ch;
};

int main()
{
    A a;
    a.show();
    return 0;
}
