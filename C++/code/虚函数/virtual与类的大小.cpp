#include <iostream>

class my // �����
{

};
class myfu: virtual public my // ��̳У������ָ�룬�洢������ַ��4���ֽ�
{

};
class myfupo: virtual public myfu // 12���ֽ�
{
    virtual void go() = 0; // ���麯�����麯�����洢���麯����ĵ�ַ��4���ֽ�
};
int main()
{
    std :: cout << sizeof(myfu) << std :: endl;
    std :: cout << sizeof(myfupo) << std :: endl;
    return 0;
}
