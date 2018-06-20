#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
//save_to_file函数从键盘读入一行字符，并将其中的字母存入磁盘文件
void save_to_file()
{
    ofstream outfile("f2.data");//定义输出文件流对象 outfile，以输出方式打开磁盘文件 f2.data
    if(! outfile)
    {
        cerr << "open f2.data error!" << endl;
        exit(1);
    }
    char str[80];
    cin.getline(str,80);//从键盘读入一行字符
    for(int i = 0; str[i] != 0; i ++)//对字符逐个处理，知道遇到 '\0' 为止
        if(str[i] >= 65 && str[i] < 90 || str[i] >= 97 && str[i] <= 122)//如果是字母字符
        {
            outfile.put(str[i]);//将字母字符存入磁盘文件 f2.data
            cout << str[i];//同时向显示器显示
        }
        cout << endl;
        outfile.close();//关闭 f2.data
}
//从磁盘文件 f2.data 读入字符，将其中的小写字母改为大写字母，再存入 f3.data
void get_from_file()
{
    char ch;
    //ifstream infile("f3.data", ios :: in | ios :: nocreate);//定义输入文件流 outfile，以输出方式打开磁盘文件 f2.data
    ifstream infile("f2.data", ios :: in);
    if(! infile)
    {
        cerr << "open f2.data error!" << endl;
        exit(1);
    }
    ofstream outfile("f3.data");//定义输出文件流对象 outfile，以输出方式打开磁盘文件 f3.data
    if(! outfile)
    {
        cerr << "open f3.data error!" << endl;
        exit(1);
    }
    while(infile.get(ch))//当读入字符成功时执行下面的复合语句
    {
        if(ch >= 97 && ch <= 122)
            ch = ch - 32;
        outfile.put(ch);//将该大写字母存入磁盘文件 f3.data
        cout << ch;
    }
    cout << endl;
    infile.close();
    outfile.close();
}
void display_file(char * filename)
{
    //ifstream infile(filename,ios :: in | ios :: nocreate);
    ifstream infile(filename,ios :: in);
    if(! infile)
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    char ch;
    while(infile.get(ch))
        cout.put(ch);
    cout << endl;
    infile.close();
}
int main(int argc, char * argv[])
{
    save_to_file();
    get_from_file();
    display_file("f3.data");
    return 0;
}
