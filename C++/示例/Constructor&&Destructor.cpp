#include<iostream>
using namespace std;
class Time
{
public :
    //���幹���Ա��������������������ͬ
    Time(){ hour = 0; minute = 0; sec = 0; cout << "None pram Constructor called." << endl;}//���ù��캯���Զ����е����ݳ�Ա����ֵ
    //����һ���޲εĹ��캯��,�����ع��캯��
    //Time();
    //����һ����һ�������Ĺ��캯���������ع��캯��
    Time(int);
    //����һ�������������Ĺ��캯���������ع��캯��
    Time(int, int);
    //�����������Ĺ��캯��
    //Time(int, int, int);
    //����һ���вεĹ��캯�����ò�����ʼ��������ݳ�Ա��ʼ��
    Time(int h, int m, int s):hour(h),minute(m),sec(s){ cout << "Three pram Constructor called." << endl; }
    //���������캯����ָ��Ĭ�ϲ���
    //Time(int h = 10,int m = 10,int s = 10);
    ~Time(){cout << "Destructor called." << endl;}
    void set_time();
    void show_time();
private :
    int hour;
    int minute;
    int sec;
};
//����һ���޲εĹ��캯��
//Time :: Time()
//{
//    hour = 10;
//    minute = 10;
//    sec = 10;
//}
//����һ����һ�������Ĺ��캯���������ع��캯��
Time :: Time(int h)
{
    hour = h;
    minute = 10;
    sec = 10;
    cout << "One pram Constructor called." << endl;
}
//����һ�������������Ĺ��캯���������ع��캯��
Time :: Time(int h, int m)
{
    hour = h;
    minute = m;
    sec = 10;
    cout << "Two pram Constructor called." << endl;
}
//�����ⶨ����εĹ��캯��
//Time :: Time(int h, int m,int s)//�ڶ��庯��ʱ���Բ���ָ��������Ĭ��ֵ
//{
//    hour = h;
//    minute = m;
//    sec = s;
//}
void Time :: set_time()
{
    cin >> hour >> minute >> sec;
}
void Time :: show_time()
{
    cout << hour << " : " << minute << " : " << sec << endl;
}
int main()
{
    //�ȹ���ĺ����������������������ջ���Ƚ������
    Time t1;
    t1.set_time();
    t1.show_time();
    Time t2;
    t2.show_time();
    //��������
    Time array[3] = {Time(15),Time(15,30),Time(15,30,20)};
    array[0].show_time();
    array[1].show_time();
    array[2].show_time();
    return 0;
}
