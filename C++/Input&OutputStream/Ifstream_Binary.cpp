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
    student stu[3];
    ifstream infile("stu.data",ios :: binary);
    if(! infile)
    {
        cerr << "open error!" << endl;
        abort();
    }
//    for(int i = 0; i < 3; i ++)
//        infile.read((char *)&stu[i],sizeof(stu[i]));
    infile.read((char *)&stu[0],sizeof(stu));
    infile.close();
    for(int i = 0; i < 3; i++)
    {
        cout << "NO." << i + 1 << endl;
        cout << "name : " << stu[i].name << endl;
        cout << "num : " << stu[i].num << endl;
        cout << "age : " << stu[i].age << endl;
        cout << "sex : " << stu[i].sex << endl << endl;
    }
    return 0;
}
