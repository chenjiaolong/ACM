#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <typeinfo>
#include <iostream>

using namespace std;

class mystring
{
public :
    char *p;
    int n;
    mystring() : p(nullptr), n(0) { cout << "SSSS" << endl; }
    mystring(char *str)
    {
        p = new char[strlen(str) + 1];
        n = strlen(str) + 1;
        strcpy(p, str); // ����
    }
//    mystring(mystring & mystr) // ��������������õĹ��죬ǳ����
//    {
//        cout << "call ��������" << endl;
//        p = mystr.p;
//        n = mystr.n;
//    }
    mystring (mystring & mystr) // ��������������õĹ��죬ǳ����
    {
        cout << "call ��������" << endl;
        p = mystr.p;
        n = mystr.n;
    }
    mystring operator + (mystring & mystrings)
    {
        cout << "��ֵ����" << endl;
        mystring mys("ssss"); // �����Զ�����
        mys.n = n + mystrings.n;
        mys.p = new char[mys.n];
        strcpy(mys.p, p);
        strcat(mys.p, mystrings.p);
        return mys; // ��������
    }
    ~mystring(){ delete[] p; }
};

int main()
{
    mystring s1("hello,");
    mystring s2("world!");
    (s1 + s2); // ����
    cout << (s1 + s2).p << endl;
    return 0;
}
