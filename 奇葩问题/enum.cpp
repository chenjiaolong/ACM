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
    c = (enum response)2;//��˳���Ϊ2��ö��Ԫ�ظ���ö�ٱ���c���൱�� c = response;
    cout << a << " " << b << " " << c << endl;
    return 0;
}

