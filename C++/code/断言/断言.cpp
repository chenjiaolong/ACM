#include <cassert>
#include <iostream>

using namespace std;

int Div(int a, int b)
{
    assert(b != 0); // 断言
    return a / b;
}

int main()
{
    cout << Div(1, 0) << endl;
    return 0;
}
