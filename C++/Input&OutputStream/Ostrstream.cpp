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
    char array[50];//�û�������ַ�����
    ostrstream strout(array,50);//��������ַ�������������array������������������50
    for(int i = 0; i < 3; i ++)//���ַ����� array д3��ѧ��������
        strout << " " << stu[i].num << " " << stu[i].name << " " << stu[i].score;
    strout << ends;//ends �� C++ �� I / O ������������һ��'\0'
    cout << "array array : " << array << endl;//��ʾ�ַ����� array �е��ַ�
    return 0;
}
