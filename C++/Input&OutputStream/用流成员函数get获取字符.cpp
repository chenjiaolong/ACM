//用 get 函数读入一个字符（包括空格字符，制表符）

//不带参数的 get 函数
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

//有一个参数的 get 函数
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

//有三个参数的 get 函数
//cin.get(字符数组(字符指针), 字符个数n, 终止字符)
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
