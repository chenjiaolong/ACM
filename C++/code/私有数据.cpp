#include <iostream>

using namespace std;

struct node
{
private :
    int a;
    int b;
public :
    node(){  }
    node(int x, int y): a (x), b(y) { }
    void show()
    {
        cout << a << " " << b << endl;
    }
};

int main()
{
    node p;
    node p1{1, 2};
    node p2 = p1; // 赋值，赋值拷贝，无论私有或者公有
    //! cout << p2.a << " " << p2.b << endl;
    p2.show();
    return 0;
}
