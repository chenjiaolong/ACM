#include<string.h>
#include<iostream>
using namespace std;
class String
{
public :
    String(){ p = NULL; }//�����壩Ĭ�Ϲ��캯��
    String (char *str);//���ع��캯��������
    friend bool operator > (String &string1, String &string2);//�������������Ϊ��Ԫ����
    friend bool operator == (String &string1, String &string2);
    friend bool operator < (String &string1, String &string2);
    void display();
private :
    char *p;//�ַ���ָ�룬����ָ���ַ���
};
String :: String(char *str)//���幹�캯��
{
    p = str;//ʹ p ָ��ʵ���ַ���
}
void String :: display()//��� p ��ָ����ַ���
{
    cout << p;
}
bool operator > (String &string1, String &string2)//������������غ���
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
