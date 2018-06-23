#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char str[100] {0}; // char str[100]{""};
    cin >> str;
    cout << str;
    system(str);
    // C++重定向：>重写(覆盖)，>> 追加 < << 输入
    return 0;
}
