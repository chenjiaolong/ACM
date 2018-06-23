#include <iostream>

using namespace std;
// 参数的个数，类型不一样，顺序重载，与返回值无关
// 有指针优先匹配指针
template<typename T>
void go(T t)
{
    cout << "TTTTT" << endl;
    cout << t << endl;
}
template<typename T>
void go(T *t)
{
    cout << "*****" << endl;
    cout << t << endl;
}

int main()
{
    int *p{new int [5]{1, 2, 3, 4, 5}};
    go(p[0]);
    go(p);
    go(&p); // 地址趋向于地址
    return 0;
}
