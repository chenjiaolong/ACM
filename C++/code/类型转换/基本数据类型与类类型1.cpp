#include <iostream>

using namespace std;

class myclass
{
public :
    int x, y;
    myclass(int a) : x(a), y(a){ cout << "构造函数" << endl; } // 赋值初始化
};

int main()
{
    // 构造函数初始化，视作类型转换
    myclass my1 = 5;
    myclass my2(5);
    myclass my3 = myclass(5);
    myclass my4 = (myclass)5;




    return 0;
}
