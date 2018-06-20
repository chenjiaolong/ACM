#include<iostream>
using namespace std;
class Time
{
public :
    //定义构造成员函数，函数名与类名相同
    Time(){ hour = 0; minute = 0; sec = 0; cout << "None pram Constructor called." << endl;}//利用构造函数对对象中的数据成员赋初值
    //声明一个无参的构造函数,是重载构造函数
    //Time();
    //声明一个有一个参数的构造函数，是重载构造函数
    Time(int);
    //声明一个有两个参数的构造函数，是重载构造函数
    Time(int, int);
    //声明带参数的构造函数
    //Time(int, int, int);
    //声明一个有参的构造函数，用参数初始化标对数据成员初始化
    Time(int h, int m, int s):hour(h),minute(m),sec(s){ cout << "Three pram Constructor called." << endl; }
    //在声明构造函数是指定默认参数
    //Time(int h = 10,int m = 10,int s = 10);
    ~Time(){cout << "Destructor called." << endl;}
    void set_time();
    void show_time();
private :
    int hour;
    int minute;
    int sec;
};
//定义一个无参的构造函数
//Time :: Time()
//{
//    hour = 10;
//    minute = 10;
//    sec = 10;
//}
//定义一个有一个参数的构造函数，是重载构造函数
Time :: Time(int h)
{
    hour = h;
    minute = 10;
    sec = 10;
    cout << "One pram Constructor called." << endl;
}
//定义一个有两个参数的构造函数，是重载构造函数
Time :: Time(int h, int m)
{
    hour = h;
    minute = m;
    sec = 10;
    cout << "Two pram Constructor called." << endl;
}
//在类外定义带参的构造函数
//Time :: Time(int h, int m,int s)//在定义函数时可以不再指定参数的默认值
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
    //先构造的后析构，后构造的先析构——栈（先进后出）
    Time t1;
    t1.set_time();
    t1.show_time();
    Time t2;
    t2.show_time();
    //对象数组
    Time array[3] = {Time(15),Time(15,30),Time(15,30,20)};
    array[0].show_time();
    array[1].show_time();
    array[2].show_time();
    return 0;
}
