#include<iostream>
#include<windows.h>
using namespace std;
class Time
{
public :
    Time(){minute = 0; sec = 0; } //默认构造函数
    Time(int m, int s):minute(m),sec(s) {} //构造函数重载
    Time operator ++ ();//声明前置自增运算符 ++ 重载函数
    //C++约定：如果在自增（自减）运算符重载函数中，增加一个int型形参，就是后置自增（自减）运算符函数
    Time operator ++ (int);//声明后置自增运算符 ++ 重载函数
    void display(){cout << minute << " : " << sec << endl; } //定义输出时间函数
private :
    int minute;
    int sec;
};
Time Time :: operator ++()//定义前置自增运算符 ++ 重载函数
{
    if(++ sec >= 60)
    {
        sec -= 60;//满60秒进1分钟
        ++minute;
    }
    return *this;//返回自加后的当前对象值
}
Time Time :: operator ++(int)//定义后置自增运算符 ++ 重载函数
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
    time2 = time1 ++;//将自加前的对象的值赋给time2
    cout << "time1 ++ : ";
    time1.display();
    cout << "time2 : ";
    time2.display();
    return 0;
}
