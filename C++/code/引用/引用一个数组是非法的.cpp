#include <iostream>

using namespace std;

// 数组的每一个元素都是引用
int main()
{
    int a(1);
    int b(2);
    int c(3);
    int &ra(a);
    int &rb(b);
    int &rc(c);
    // 引用数组是非法的
    //! int &myarray[3]{ra, rb, rc};
    return 0;
}
