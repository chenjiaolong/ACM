#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct student
{
    char name[20];
    int num;
    int age;
    char sex;
};
int main(int argc, char * argv[])
{
    student stu[3] = {"Li", 1001, 18, 'f', "Fun",1002, 19, 'm', "Wang", 1004, 17, 'f'};
    ofstream outfile("stu.data", ios :: binary);
    if(! outfile)
    {
        cerr << "Open error!" << endl;
        abort();//退出程序
    }
//    for(int i = 0; i < 3; i ++)
//        outfile.write((char *)&stu[i],sizeof(stu[i]));
        outfile.write((char *)&stu[0],sizeof(stu));
    outfile.close();
    return 0;
}

