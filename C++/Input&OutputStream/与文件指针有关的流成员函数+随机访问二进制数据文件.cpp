#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct student
{
    int num;
    char name[20];
    float score;
};
int main(int argc, char * argv[])
{
    student stu[5] = { 1001, "Li", 85, 1002, "Fun", 97.5, 1004, "Wang", 54, 1006, "Tan", 76.5, 1010,"ling",96 };
    fstream iofile("stu.data",ios :: in | ios :: out | ios :: binary);
    //用 fstream 类定义输入输出二进制文件流对象 iofile
    if(! iofile)
    {
        cerr << "open error" << endl;
        abort();
    }
    for(int i = 0; i < 5; i ++)//向磁盘文件输出5个学生数据
        iofile.write((char * )&stu[i], sizeof(stu[i]));
    student stud[5];//用来存放从磁盘文件读入的数据
    for(int i = 0; i < 5; i += 2)
    {
        iofile.seekg(i * sizeof(stu[i]),ios :: beg);//定位于第0,2,4学生数据的开头
        //先后读入3个学生的数据，存放在stud[0],stud[1],stud[2];
        iofile.read((char * )&stud[i / 2],sizeof(stud[0]));
        cout << stud[i / 2].num << " " << stud[i / 2].name << " " << stud[i / 2].score << endl;
        //输出stud[0],stud[1],stud[2]各成员的值
    }
    cout << endl;
    //修改第3个学生(序号为2)的数据
    stu[2].num = 1012;
    strcpy(stu[2].name, "Wu");
    stu[2].score = 60;
    iofile.seekp(2 * sizeof(stu[0]), ios :: beg);//定位于第三个学生数据的开头
    iofile.write((char * )&stu[2],sizeof(stu[2]));//更新第3个学生数据
    iofile.seekg(0, ios :: beg);//重新定位于文件开头
    for(int i = 0; i < 5; i ++)
    {
        iofile.read((char * )& stu[i],sizeof(stu[i]));//读入5个学生的数据
        cout << stu[i].num << " " << stu[i].name << " " << stu[i].score << endl;
    }
    iofile.close();
    return 0;
}
