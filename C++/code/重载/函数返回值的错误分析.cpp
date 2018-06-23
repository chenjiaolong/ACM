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
    mystring() : p(nullptr), n(0) {  }
    mystring(char *str)
    {
        p = new char[strlen(str) + 1];
        n = strlen(str) + 1;
        strcpy(p, str); // ����
    }
    void operator + (mystring & mystrings)
    {
        cout << "SSSS" << endl;
        n += strlen(mystrings.p); // ���ӳ���
        char *ptemp = new char[n];
        strcpy(ptemp, p); // ����
        strcat(ptemp, mystrings.p); // ����
        delete [] p;
        p = ptemp; // �ӹ�
    }
    ~mystring(){ delete[] p; }
};

int main()
{
    mystring my1("hello");
    mystring my2(", world!");
    cout << typeid(my1.operator + (my2)).name() << endl; // void
    cout << typeid(my1 + my2).name() << endl; // void
    my1 + my2; // ���ܽ��и�ֵ����
    cout << my1.p << endl;

    puts("-----");
    int a = 3;
    cout << typeid(a += 2).name() << endl; // int, typeid ֻ�ǻ�ȡ���ͣ�������м���
    cout << a << endl;

    return 0;
}
