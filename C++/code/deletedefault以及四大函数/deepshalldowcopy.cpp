// ����ȫ����
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

using namespace std;

// Ĭ�Ͽ������죬ֻ��ֵ���ݣ��������ݣ�����ָ�룬ͬһ��ָ�� -> ǳ����
// ����ڲ���ָ������ڴ棬��Ҫ���������ǳ����
class mystring
{
public :
    char *pstr;
    int length;
    mystring(const char *str)
    {
        length = strlen(str);
        pstr = new char[length]{0};
        strcpy(pstr, str); // ��ʼ��
    }
    ~mystring()
    {
        if(pstr) delete[] pstr, pstr = nullptr;
    }
    mystring(const mystring &p)
    {
        length = p.length;
        pstr = new char[length];
        strcpy(pstr, p.pstr);
    }
    void show()
    {
        cout << length << "  " << (void *)pstr << "  " << pstr << endl;
    }
};

int main()
{
    mystring str1("gogogo");
    str1.show();
    mystring str2(str1);
    str2.show();
    str1.~mystring();
    str2.show();

    return 0;
}
