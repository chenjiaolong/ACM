#include <iostream>

using namespace std;

struct point
{
    int a, b;

};

class myclass
{
public :
    int x, y;
    myclass(int n) : x(n), y(n){  }
    myclass(const point &p) : x(p.a), y(p.b) {  }
};

int main()
{
    myclass my(5);
    myclass my1 = 5; // 把5转换为myclass类型
    point p{1, 2};
    myclass my2(p);
    myclass my3 = p;
    return 0;
}
