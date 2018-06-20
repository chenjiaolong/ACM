#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
    double *a = new double[5];
    for(int i = 0; i < 5; i ++) a[i] = i*1.0;
    double *b = new double[5];
    auto push_data = [](double *a, double *b, int olen, int nlen)
    {
        memcpy(b, a, sizeof(double) * olen);
        delete[] a;
        a = new double[nlen];
        memcpy(a, b, sizeof(double) * olen);
        for(int i = 0; i < olen; i ++)
            cout << a[i] << endl;
        cout << a << endl;
    };
    cout << a << endl;
    push_data(a, b, 5, 10);
    cout << a << endl;
    cout << "------" << endl;
    for(int i = 0; i < 5; i ++)
        cout << a[i] << endl;
    return 0;
}
