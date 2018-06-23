#include <cstdlib>
#include <iostream>

using namespace std;

// 预留参数接口，参数无法调用
void add(int a, int b, int)
{

}

template<class T>
void show(T a, T, T c) // 预留接口，第二个参数无法调用
{

}

int main()
{
    add(1, 2, 3);
    return 0;
}
