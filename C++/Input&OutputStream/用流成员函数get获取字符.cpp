//�� get ��������һ���ַ��������ո��ַ����Ʊ����

//���������� get ����
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//int main(int argc, char *argv[])
//{
//    int ch;
//    cout << "enter a sentence : " << endl;
//    while((ch = cin.get()) != EOF)
//        cout.put(ch);
//    cout.put('\n');
//    return 0;
//}

//��һ�������� get ����
//#include<iostream>
//using namespace std;
//int main(int argc, char *argv[])
//{
//    char ch;
//    cout << "enter a sentence : " << endl;
//    while(cin.get(ch))
//        cout.put(ch);
//    cout << "end" << endl;
//    return 0;
//}

//������������ get ����
//cin.get(�ַ�����(�ַ�ָ��), �ַ�����n, ��ֹ�ַ�)
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    char str[20];
    cout << "enter a sentence : " << endl;
    cin.get(str, 10, '\n');
    cout << str << endl;
    return 0;
}
