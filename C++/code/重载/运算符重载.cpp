#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class mystring
{
public :
    char *pstr;
    int length;
    mystring() : pstr(nullptr), length(0){  }
    mystring(const char *str)
    {
        length = strlen(str) + 1; // ��ȡ�ַ�������
        pstr = new char[length];
        strcpy(pstr, str);
    }
    // ��������
    mystring(const mystring &my)
    {
        cout << "���" << endl;
        length = my.length;
        pstr = new char[length];
        strcpy(pstr, my.pstr);
    }
    mystring add(const mystring &my)
    {
       int n = length + my.length - 1;
       mystring temp;
       temp.length = n;
       temp.pstr = new char[length];
       strcpy(temp.pstr, pstr);
       strcat(temp.pstr, my.pstr);
       return temp;
    }
    mystring operator + (const mystring & my)
    {
        int n = length + my.length - 1;
        mystring temp;
        temp.length = n;
        temp.pstr = new char[length];
        strcpy(temp.pstr, pstr);
        strcat(temp.pstr, my.pstr);
        return temp;
    }
};

template<class T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    mystring my1 = "12345";
    mystring my2 = "67890";
    // mystring my3 = my1.add(my2); // ��Ա����ʵ��
    mystring my3 = my1 + my2; // my3 = my1.operator + my2;
    cout << my3.pstr << endl;

    cout << add(my1, my2).pstr << endl;
    return 0;
}
