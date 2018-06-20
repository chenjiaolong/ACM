#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
//save_to_file�����Ӽ��̶���һ���ַ����������е���ĸ��������ļ�
void save_to_file()
{
    ofstream outfile("f2.data");//��������ļ������� outfile���������ʽ�򿪴����ļ� f2.data
    if(! outfile)
    {
        cerr << "open f2.data error!" << endl;
        exit(1);
    }
    char str[80];
    cin.getline(str,80);//�Ӽ��̶���һ���ַ�
    for(int i = 0; str[i] != 0; i ++)//���ַ��������֪������ '\0' Ϊֹ
        if(str[i] >= 65 && str[i] < 90 || str[i] >= 97 && str[i] <= 122)//�������ĸ�ַ�
        {
            outfile.put(str[i]);//����ĸ�ַ���������ļ� f2.data
            cout << str[i];//ͬʱ����ʾ����ʾ
        }
        cout << endl;
        outfile.close();//�ر� f2.data
}
//�Ӵ����ļ� f2.data �����ַ��������е�Сд��ĸ��Ϊ��д��ĸ���ٴ��� f3.data
void get_from_file()
{
    char ch;
    //ifstream infile("f3.data", ios :: in | ios :: nocreate);//���������ļ��� outfile���������ʽ�򿪴����ļ� f2.data
    ifstream infile("f2.data", ios :: in);
    if(! infile)
    {
        cerr << "open f2.data error!" << endl;
        exit(1);
    }
    ofstream outfile("f3.data");//��������ļ������� outfile���������ʽ�򿪴����ļ� f3.data
    if(! outfile)
    {
        cerr << "open f3.data error!" << endl;
        exit(1);
    }
    while(infile.get(ch))//�������ַ��ɹ�ʱִ������ĸ������
    {
        if(ch >= 97 && ch <= 122)
            ch = ch - 32;
        outfile.put(ch);//���ô�д��ĸ��������ļ� f3.data
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
