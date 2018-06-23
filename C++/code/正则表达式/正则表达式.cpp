#include <regex>
#include <iostream>

using namespace std;

int main()
{
    // select or 1 = 1
    regex reg("^select ([a-zA-Z]*) from ([a-zA-Z]*)$");
    cmatch what; // 匹配的词语检索出来
    bool isit = regex_match("select id from admin", what, reg); //

    // 输出匹配的信息
    for(int i = 0; i < what.size(); i++)
        cout << what[i + 1].first << "\t";

    if(isit) cout << "匹配" << endl;
    else cout << "不匹配" << endl;

    cout << "--------" << endl;
    // 13 15
    // ^ 开头
    // () 组
    // [] 或
    // {} 几次
    // $ 结尾
    regex regx("^(1[3|4|5|8|7][0-9]{9})");
    string str1;
    cin >> str1;
    bool isitx = regex_match(str1, regx); // 不需要返回结果
    if(isitx) cout << "OK!" << endl;
    else cout << "Error!" << endl;

    cout << "--------" << endl;
    cmatch match;
    regex re("\\d+"); // 数字
    char str2[50]{"hello 8848, hello maomao 180"};
    bool isFind = regex_search(str2, match, re);
    if(isFind)
    {
        for(int i = 0; i != match.size(); i++)
            cout << match[i].first << endl;
    }

    cout << "--------" << endl;
    regex r("\\d+"); // 数字
    char str3[50]{"hello 8848, hello maomao 180"};
    // 并不改变原字符串
    cout << regex_replace(str3, r, "ABCD") << endl;

    return 0;
}
