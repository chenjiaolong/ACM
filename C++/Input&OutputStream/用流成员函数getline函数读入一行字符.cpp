#include<iostream>
using namespace std;
int main()
{
    //cin.getline(�ַ�����(�ַ�ָ��), �ַ�����n, ��ֹ�ַ�)
    char str[20];
    cout << "enter a sentence : " << endl;
    cin >> str;
    cout << "The string read with cin is : " << str << endl;
    cin.getline(str, 20, '/');//��19���ַ����� '/' ����
    cout << "The second part is : " << str << endl;
    cin.getline(str, 20);//��19���ַ� ���� '\n'����
    cout << "The third apart is : " << str << endl;
    return 0;
}
