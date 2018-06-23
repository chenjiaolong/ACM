#include <iostream>

using namespace std;

class point
{
public :
    int x, y;
    point(int a, int b) : x(a), y(b) {  }
    ~point(){  }
};

class line
{
public :
    point *p1, *p2;
    line(int a1, int b1, int a2, int b2) : p1(new point(a1, b1)), p2(new point(a2, b2)) {  }


};

int main()
{

    return 0;
}
