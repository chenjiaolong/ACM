#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    string str1 = R"(12345\n123)";
    cout << str1 << endl;
    //! string str2 = R"(12345\n123)"123\n123)"; // 错误
    string str2 = R"-(12345\n123)"123\n123)-"; // - 处理对称性错误
    // string str2 = "12345\n123";
    string str3 = "123\n123";
    cout << str2 + str3 << endl;
    return 0;
}
