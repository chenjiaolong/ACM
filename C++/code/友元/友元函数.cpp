#include <iostream>

using namespace std;
// 访问私有变量

class myclass
{
    int x, y;
    friend void show(const myclass &my);
public :
    myclass() : x(20), y(30) {  }
};

void show(const myclass &my)
{
    cout << my.x << " " << my.y << endl;
}
int main()
{
    myclass my1;
    show(my1);
    return 0;
}
