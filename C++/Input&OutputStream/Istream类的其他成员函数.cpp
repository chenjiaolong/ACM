//eof����
//#include<iostream>
//using namespace std;
//int main(int argc, char *argv[])
//{
//    char ch;
//    while(! cin.eof())
//        if((ch = cin.get()) != ' ')
//        cout.put(ch);
//    return 0;
//}

//peek������putback����
//#include<iostream>
//using namespace std;
//int main(int argc, char *argv[])
//{
//    char str[20];
//    int ch;
//    cout << "please enter a sentence : " << endl;
//    cin.getline(str, 15, '/');
//    cout << "The first part is : " << str << endl;
//    ch = cin.peek();//�ۿ���ǰ�ַ�
//    cout << "The next character (ASCII code) is : " << ch << endl;//��һ���ַ��ǿո�
//    cin.putback(str[0]);//�� 'I' ���뵽ָ����ָ��
//    cin.getline(str, 15, '/');
//    cout << "The second part is : " << str << endl;
//    return 0;
//}

//ignore ����: cin.ignore(n, ��ֹ�ַ�) �����������е� n ���ַ��� ����������ָ������ֹ�ַ�ʱ��ǰ����
//ignore()(n Ĭ��ֵΪ 1�� ��ֹ�ַ�Ĭ��Ϊ EOF) < = > ignore(1,EOF)
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    char str[20];
    cin.get(str, 20, '/');
    cout << "The first part is : " << str << endl;
    cin.ignore();//������������һ���ַ�
    cin.get(str, 20, '/');
    cout << "The second part is : " << str << endl;
    return 0;
}
