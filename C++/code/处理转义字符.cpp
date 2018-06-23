#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    // @"";
    // 64bit
    string str1("\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\"");
    system(str1.c_str());
    cout << str1.c_str() << endl;

    cout << "-----------" << endl;
    // R"("")"
    string str2(R"("C:\Program Files (x86)\Google\Chrome\Application\chrome.exe")");
    cout << str2.c_str() << endl;
    system(str2.c_str());

    cout << "-----------" << endl;
    string str3("\"C:\\Program Files (x86)\\Google\\\nChrome\\Application\\chrome.exe\"");
    cout << str3.c_str() << endl;
    string str4(R"("C:\Program Files (x86)\Google\\nChrome\Application\chrome.exe")"); // \n ²»»á»»ÐÐ
    cout << str4.c_str() << endl;

    return 0;
}
