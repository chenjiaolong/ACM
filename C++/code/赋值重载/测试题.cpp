#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
// Ĭ�Ͽ������죬��ֵ���أ�ֵ����
// ��ָ�룬��ǳ����һ����ָ��
// ǳ�������ڴ湲��ָ��һ�£�����һ��
// �����ָ�벻һ�£�����һ�£��ڴ����

// ��ֵ��������з����������Ͷ��󣬻���ÿ������죬ע����ǳ����
// ���ض���û��Ӱ�� ���ص�ַ�����ã���������
using namespace std;

class mystring
{
public:
    char *p;
    int n;
    mystring() : p(nullptr), n(0){  }
    mystring(const char *str)
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
        cout << "���캯��call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
    mystring * operator = (const mystring &str)
    {
        mystring tmp;
        cout << "��ֵ����call" << endl;
        tmp.n = str.n;
        tmp.p = new char[tmp.n];
        strcpy(tmp.p, str.p);
        return &tmp;
    }
};

int main()
{
    mystring my1{"12345"};
    mystring my2;
    cout << (void *)my1.p << " " << my1.p << endl;
    cout << (void *) (my2 = my1) -> p << " " << (my2 = my1) -> p << endl;

    my1.~mystring();
    return 0;
}

