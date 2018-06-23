#include <regex>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    // 1999/12/15
    regex reg("^\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])$");
    string str1;
    getline(cin, str1); // 遇到'\n'结束
    cout << str1 << endl;
    if(regex_match(str1, reg)) cout << "OK" << endl;
    else cout << "Error!" << endl;

    cout << "--------" << endl;
    regex regs("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
    string str2;
    getline(cin, str2); // 遇到'\n'结束
    cout << str2 << endl;
    smatch m; // 帮助转换
    if(regex_match(str2, m, reg))
    {
        // m[0]忽略
        cout << endl << endl;
        cout << m[0].str().c_str() << endl; // 汇总全部0
        cout << m[1].str().c_str() << endl; // 1 2 3
        cout << m[2].str().c_str() << endl;
        cout << m[3].str().c_str() << endl;

        int year = atoi(m[1].str().c_str()); // 获取整数
        int month = atoi(m[2].str().c_str());
        int day = atoi(m[3].str().c_str());
        cout << endl << endl;
        cout << year << " " << month << " "<< day << endl;
        cout << "OK" << endl;
    }
    else cout << "Error!" << endl;

    // 字符串拆分
    cout << "--------" << endl;
    regex regx("\\s*[,#,;]+\\s*");
    string str3;
    getline(cin, str3);
    // 迭代器
    sregex_token_iterator end;
    for(sregex_token_iterator it(str3.begin(), str3.end(), reg, -1); it != end; it ++)
        cout << *it << endl;
    return 0;
}
