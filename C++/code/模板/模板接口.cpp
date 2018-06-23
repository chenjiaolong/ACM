#include <iostream>

using namespace std;

void show(int num)
{
    cout << num << endl;
}
void show1(double num)
{
    cout << num + 1 << endl;
}
template<typename T>
void showit(T num)
{
    cout << num << endl;
}

// 泛型接口，任何数据类型，传递函数指针
template<typename T, typename F>
void run(T t, F f)
{
    f(t);
}

int main()
{
    run(10, show);
    run(10.1, show1);
    //! run("abc", showit<char *>);// Error! 不能从const char* 转换为 char*
    run("abc", showit<const char *>);
    // 接口，严格类型，
    return 0;
}
