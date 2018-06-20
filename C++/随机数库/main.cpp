#include<iostream>

#include"zyrandom.h"

using namespace std;

int main()
{
    Randomize();
    for(int i = 1; i <= 8; i ++)
    {
        int t = GenerateRandomNumber(10, 99);
        cout << t << "; ";
    }
    cout << endl;
    for(int i = 1; i <= 8; i ++)
    {
        double d = GenerateRandomReal(10.0, 99.0);
        cout << d << "; ";
    }
    cout << endl;
    return 0;
}
