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
        strcpy(p, str); // 拷贝
    }
//    mystring * operator + (mystring & mystrings)
//    {
//        cout << "SSSS" << endl;
////!        mystring mys; // 栈上，自动回收
////!        mys.n = n + mystrings.n;
////!        mys.p = new char[mys.n];
////!       strcpy(mys.p, p);
////!       strcat(mys.p, mystrings.p);
////!        return &mys;
//
//      mystring *ps = new mystring;
//      ps -> p = new char[ps -> n];
//      ps -> n = n + mystrings.n;
//      strcpy(ps -> p, p);
//      strcat(ps -> p, mystrings.p);
//      return ps;
//    }
//     mystring & operator + (mystring & mystrings)
//    {
//        mystring mys; // 栈上，自动回收
//        mys.n = n + mystrings.n;
//        mys.p = new char[mys.n];
//        strcpy(mys.p, p);
//        strcat(mys.p, mystrings.p);
//        return mys;
//    }
    mystring & operator + (mystring & mystrings)
    {
      mystring *ps = new mystring;
      ps -> p = new char[ps -> n];
      ps -> n = n + mystrings.n;
      strcpy(ps -> p, p);
      strcat(ps -> p, mystrings.p);
      return *ps;
    }
    ~mystring(){ delete[] p; }
};

int main()
{
    mystring str1("hello");
    mystring str2(", world!");
//    mystring *p = str1 + str2;
//    cout << "1234567890" << endl;
//    cout << p -> p << endl;
//    cout << p -> n << endl;

   //! mystring &rstr = str1 + str2;
   //! cout << rstr.p << endl;
   //! cout << rstr.n << endl;

    mystring &rstr = str1 + str2;
    cout << "1234567890" << endl;
    cout << rstr.p << endl;
    cout << rstr.n << endl;

    return 0;
}
