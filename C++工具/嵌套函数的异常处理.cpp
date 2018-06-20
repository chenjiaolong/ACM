#include<iostream>
using namespace std;
int main()
{
    void f1();
    try
    {
        f1();
    }catch(double)
    {
        cout << "OK0!" << endl;
    }
    cout << "end0" << endl;
    return 0;
}
void f1()
{
    void f2();
    try
    {
        f2();
    }catch(char)
    {
        cout << "OK1!" << endl;
    }
    cout << "end1" << endl;
}
void f2()
{
    void f3();
    try
    {
        f3();
    }catch(int)
    {
        cout << "OK2!" << endl;
    }
    cout << "end2" << endl;
}
void f3()
{
    double a = 0;
    try
    {
        throw a;
    }catch(double)//catch(float)
    {
        cout << "OK3!" << endl;
        //throw;
    }
    cout << "end3" << endl;
}
