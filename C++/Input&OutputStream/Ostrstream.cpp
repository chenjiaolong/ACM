#include<iostream>
#include<strstream>
using namespace std;
struct student
{
    int num;
    char name[20];
    float score;
};
int main(int argc, char * argv[])
{
    student stu[3] = {1001, "Li", 78, 1002,"Wang", 89.5, 1004, "Fun", 90};
    char array[50];//用户定义的字符数组
    ostrstream strout(array,50);//建立输出字符串流，与数组array建立关联，缓存区长50
    for(int i = 0; i < 3; i ++)//向字符数组 array 写3个学生的数据
        strout << " " << stu[i].num << " " << stu[i].name << " " << stu[i].score;
    strout << ends;//ends 是 C++ 的 I / O 操作符，插入一个'\0'
    cout << "array array : " << array << endl;//显示字符数组 array 中的字符
    return 0;
}
