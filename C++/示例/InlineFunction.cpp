#include<string>
#include<iostream>
#include<stdlib.h>
#define power_bug(x) x * x

using namespace std;
inline int power(int x)//���ã���������
{
    return x * x;
}
int main()
{
    cout << "string���ֽ�����" << sizeof(string) << endl;
    cout << "2 * 2 = " << power(2) << endl;
    cout << "(1 + 1) * (1 + 1) = " << power(1 + 1) << endl;
    cout << "1 + 1 * 1 + 1 = " << power_bug(1 + 1) << endl;
    return 0;
}

