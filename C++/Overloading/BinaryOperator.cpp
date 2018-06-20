#include<string.h>
#include<iostream>
using namespace std;
class String
{
public :
    String(){ p = NULL; }//（定义）默认构造函数
    String (char *str);//重载构造函数的声明
    friend bool operator > (String &string1, String &string2);//声明运算符函数为友元函数
    friend bool operator == (String &string1, String &string2);
    friend bool operator < (String &string1, String &string2);
    void display();
private :
    char *p;//字符型指针，用于指向字符串
};
String :: String(char *str)//定义构造函数
{
    p = str;//使 p 指向实参字符串
}
void String :: display()//输出 p 所指向的字符串
{
    cout << p;
}
bool operator > (String &string1, String &string2)//定义运算符重载函数
{
    if(strcmp(string1.p, string2.p) > 0)
        return true;
    return false;
}
bool operator == (String &string1, String &string2)
{
    if(strcmp(string1.p, string2.p) == 0)
        return true;
    return false;
}
bool operator < (String &string1, String &string2)
{
    if(strcmp(string1.p, string2.p) < 0)
        return true;
    return false;
}
void compare(String string1, String string2)
{
    //if(operator > (string1, string2))
    if(string1 > string2)
    {
        string1.display();
        cout << " > ";
        string2.display();
    }
    //else if(operator == (string1, string2))
    else if(string1 == string2)
    {
        string1.display();
        cout << " = ";
        string2.display();
    }
    //else if(operator < (string1, string2))
    else if(string1 < string2)
    {
        string1.display();
        cout << " < ";
        string2.display();
    }
    cout << endl;
}
int main()
{
    String string1("Hello"),string2("Book"),string3("Computer"),string4("Hello");
    compare(string1, string2);
    compare(string2, string3);
    compare(string1, string4);
    return 0;
}
