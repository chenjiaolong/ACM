//eof函数
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

//peek函数和putback函数
//#include<iostream>
//using namespace std;
//int main(int argc, char *argv[])
//{
//    char str[20];
//    int ch;
//    cout << "please enter a sentence : " << endl;
//    cin.getline(str, 15, '/');
//    cout << "The first part is : " << str << endl;
//    ch = cin.peek();//观看当前字符
//    cout << "The next character (ASCII code) is : " << ch << endl;//下一个字符是空格
//    cin.putback(str[0]);//将 'I' 插入到指针所指处
//    cin.getline(str, 15, '/');
//    cout << "The second part is : " << str << endl;
//    return 0;
//}

//ignore 函数: cin.ignore(n, 终止字符) 跳过输入流中的 n 个字符， 或者在遇到指定的终止字符时提前结束
//ignore()(n 默认值为 1， 终止字符默认为 EOF) < = > ignore(1,EOF)
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    char str[20];
    cin.get(str, 20, '/');
    cout << "The first part is : " << str << endl;
    cin.ignore();//跳过输入流中一个字符
    cin.get(str, 20, '/');
    cout << "The second part is : " << str << endl;
    return 0;
}
