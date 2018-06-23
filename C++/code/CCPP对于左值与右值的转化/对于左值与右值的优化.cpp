#include <iostream>

using namespace std;

int main()
{
    // C++ 会把有内存实体的右值转化为左值
    int i = 3;
    (++ i) ++;
    cout << i << endl;
    (i = 2) = 4;
    cout << i << endl;
    (++i) = 3;
    cout << i << endl;
    //! i ++ = 2;
    return 0;
}
