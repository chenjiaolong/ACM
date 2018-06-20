#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    float a,b,c,disc;
    cout << "Please input a,b,c : ";
    cin >> a >> b >> c;
    if(a == 0)
        cerr << "a is equal to zero,error!" << endl;//将有关出错信息插入 cerr 流， 在屏幕输出
    else
        if((disc = b * b - 4 * a * c ) < 0)
        cerr << "disc = b * b - 4 * a * c < 0" << endl;
        else
        {
            cout << "x1 = " << (- b + sqrt(disc)) / (2 * a) << endl;
            cout << "x2 = " << (- b - sqrt(disc)) / (2 * a) << endl;
        }
    return 0;
}
