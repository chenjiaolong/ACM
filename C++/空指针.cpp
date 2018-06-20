#include <iostream>
using namespace std;
int main()
{
    //!void voidObject; 错，不能声明void类型的变量
    void *pv; //对，可以声明void类型的指针
    int i = 5;
    pv = &i; //void类型指针指向整型变量
    cout << &i << endl;
    cout << (int *)pv << endl;
    int *pint = static_cast<int *>(pv); //void指针转换为int指针
    cout << "*pint = " << *pint << endl;
    return 0;
}

