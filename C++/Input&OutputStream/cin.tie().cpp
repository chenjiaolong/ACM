#include<iostream>
#include<windows.h>
#include<fstream>
//////////SubMian//////////
int main(int argc, char *argv[])
{
    std :: ostream *prevstr;
    std :: ofstream ofs;
    ofs.open("test.txt");

    std :: cout << "tie example:\n"; // 直接输出到屏幕

    *std :: cin.tie() << "This is inserted into cout\n";// 空参数调用返回值默认的output stream， 也就是cout
    prevstr = std :: cin.tie(&ofs);// cin绑定ofs， 返回原来的output stream
    *std :: cin.tie() << "This is inserted into the file\n";// ofs， 输出到文件

    std :: cin.tie(prevstr);// 恢复
    ofs.close();
    system("pause");
    return 0;
}
//////////End Sub//////////
