#include<iostream>

using namespace std;

template<class T> void Swap(T &a, T &b)
{
    T t;
    t = a, a = b, b = t;
}
int main()
{
    int m = 11, n = 7;
    char a = 'A', b = 'B';
    double c = 1.0, d = 2.0;
    // ��ȷ���ã��廯Swap(int &, int &)
    Swap(m, n);
    // ��ȷ����, �廯Swap(char &, char &)
    Swap<char>(a, b);
    // ��ȷ���ã��廯Swap(double &, double &)
    Swap<double >(c, d);
    cout << m << ", " << n << endl;
    cout << a << ", " << b << endl;
    cout << c << ", " << d << endl;
    return 0;
}
