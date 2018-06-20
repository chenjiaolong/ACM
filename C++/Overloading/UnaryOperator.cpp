#include<iostream>
#include<windows.h>
using namespace std;
class Time
{
public :
    Time(){minute = 0; sec = 0; } //Ĭ�Ϲ��캯��
    Time(int m, int s):minute(m),sec(s) {} //���캯������
    Time operator ++ ();//����ǰ����������� ++ ���غ���
    //C++Լ����������������Լ�����������غ����У�����һ��int���βΣ����Ǻ����������Լ������������
    Time operator ++ (int);//����������������� ++ ���غ���
    void display(){cout << minute << " : " << sec << endl; } //�������ʱ�亯��
private :
    int minute;
    int sec;
};
Time Time :: operator ++()//����ǰ����������� ++ ���غ���
{
    if(++ sec >= 60)
    {
        sec -= 60;//��60���1����
        ++minute;
    }
    return *this;//�����ԼӺ�ĵ�ǰ����ֵ
}
Time Time :: operator ++(int)//���������������� ++ ���غ���
{
    Time temp( *this);
    sec++;
    if(sec >= 60)
    {
        sec -= 60;
        ++minute;
    }
    return temp;
}
int main()
{
    Time time(0,0);
    for(int i = 0 ; i < 60; i++)
    {
        ++time;
        system("cls");
        time.display();
        Sleep(100);
    }
    Time time1(0,0),time2;
    cout << "time1 : ";
    time1.display();
    ++time1;
    cout << "++ time1 : ";
    time1.display();
    time2 = time1 ++;//���Լ�ǰ�Ķ����ֵ����time2
    cout << "time1 ++ : ";
    time1.display();
    cout << "time2 : ";
    time2.display();
    return 0;
}
