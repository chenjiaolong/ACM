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
    //�� fstream �ඨ����������������ļ������� iofile
    if(! iofile)
    {
        cerr << "open error" << endl;
        abort();
    }
    for(int i = 0; i < 5; i ++)//������ļ����5��ѧ������
        iofile.write((char * )&stu[i], sizeof(stu[i]));
    student stud[5];//������ŴӴ����ļ����������
    for(int i = 0; i < 5; i += 2)
    {
        iofile.seekg(i * sizeof(stu[i]),ios :: beg);//��λ�ڵ�0,2,4ѧ�����ݵĿ�ͷ
        //�Ⱥ����3��ѧ�������ݣ������stud[0],stud[1],stud[2];
        iofile.read((char * )&stud[i / 2],sizeof(stud[0]));
        cout << stud[i / 2].num << " " << stud[i / 2].name << " " << stud[i / 2].score << endl;
        //���stud[0],stud[1],stud[2]����Ա��ֵ
    }
    cout << endl;
    //�޸ĵ�3��ѧ��(���Ϊ2)������
    stu[2].num = 1012;
    strcpy(stu[2].name, "Wu");
    stu[2].score = 60;
    iofile.seekp(2 * sizeof(stu[0]), ios :: beg);//��λ�ڵ�����ѧ�����ݵĿ�ͷ
    iofile.write((char * )&stu[2],sizeof(stu[2]));//���µ�3��ѧ������
    iofile.seekg(0, ios :: beg);//���¶�λ���ļ���ͷ
    for(int i = 0; i < 5; i ++)
    {
        iofile.read((char * )& stu[i],sizeof(stu[i]));//����5��ѧ��������
        cout << stu[i].num << " " << stu[i].name << " " << stu[i].score << endl;
    }
    iofile.close();
    return 0;
}
