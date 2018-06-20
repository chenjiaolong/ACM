#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    enum response{no,yes,none};
    response a,b,c;
    a = no;
    b = yes;
    c = (enum response)2;//将顺序号为2的枚举元素赋予枚举变量c，相当于 c = response;
    cout << a << " " << b << " " << c << endl;
    return 0;
}

