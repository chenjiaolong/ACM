#include<iostream>
#include<windows.h>
#include<fstream>
//////////SubMian//////////
int main(int argc, char *argv[])
{
    std :: ostream *prevstr;
    std :: ofstream ofs;
    ofs.open("test.txt");

    std :: cout << "tie example:\n"; // ֱ���������Ļ

    *std :: cin.tie() << "This is inserted into cout\n";// �ղ������÷���ֵĬ�ϵ�output stream�� Ҳ����cout
    prevstr = std :: cin.tie(&ofs);// cin��ofs�� ����ԭ����output stream
    *std :: cin.tie() << "This is inserted into the file\n";// ofs�� ������ļ�

    std :: cin.tie(prevstr);// �ָ�
    ofs.close();
    system("pause");
    return 0;
}
//////////End Sub//////////
