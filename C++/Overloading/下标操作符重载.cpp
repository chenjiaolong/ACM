#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stdexcept>


using namespace std;

class Couple
{
public :
    Couple(int a = 0, int b = 0) { _a[0] = a, _a[1] = b; }
    int & operator[](int index);
    const int & operator[](int index) const;
private :
    int _a[2];
};
int & Couple :: operator[](int index)
{
    if(index < 0 || index > 1)
        throw out_of_range("Index is out of range!");
    return _a[index];
}
const int & Couple :: operator[](int index) const
{
    if(index < 0 || index > 1)
        throw out_of_range("Index is out of range!");
    return _a[index];
}
int main()
{
    Couple a(1, 2), b(3, 4);
    cin >> a[0] >> a[1];
    cout << a[0] << " " << a[1] << endl;
    cout << b[0] << " " << b[1] << endl;
    return 0;
}
