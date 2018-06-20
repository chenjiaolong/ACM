#include<iostream>

using namespace std;

int f(void *p)
{
    unsigned int n = reinterpret_cast<unsigned int> (p);
    return n;
}
int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = f(a);
    cout << n << endl;
    return 0;
}
