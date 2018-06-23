#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
// Ĭ�Ͽ������죬��ֵ���أ�ֵ����
// ��ָ�룬��ǳ����һ����ָ��
// ǳ�������ڴ湲��ָ��һ�£�����һ��
// �����ָ�벻һ�£�����һ�£��ڴ����

// ��ֵ��������з����������Ͷ��󣬻���ÿ�������
// ���ض���û��Ӱ�� ���ض����ַ�����ã���������
// �����ջ�ϣ�Ҳ�ᴥ���쳣
using namespace std;

class mystring
{
public:
    char *p;
    int n;
    mystring() : p(nullptr), n(0){  }
    mystring(char *str)
    {
        n = strlen(str) + 1;
        p = new char[n];
        strcpy(p, str);
    }
    ~mystring()
    {
        if(p) delete[] p, p = nullptr;
    }
    mystring(const mystring &str)
    {
        delete[] p;
        cout << "���캯��call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
    void operator = (const mystring &str)
    {
        delete[] p;
        cout << "��ֵ����call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
};

int main()
{
    mystring my1{"12345"};
    mystring my2;
    my2 = my1;
    cout << (void *)my1.p << " " << my1.p << endl;
    cout << (void *)my2.p << " " << my2.p << endl;

    my1.~mystring();
    cout << (void *)my2.p << " " << my2.p << endl;
    return 0;
}
