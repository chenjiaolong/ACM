#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){real = 0; imag = 0;}
    Complex(double r, double i){real = r; imag = i;}
    Complex operator + (Complex &c2);//声明重载运算符 + 的函数
    void display();
private :
    double real;
    double imag;
};
Complex Complex :: operator + (Complex &c2)//定义重载运算符 + 函数
{
    Complex c;
    c.real = real + c2.real;
    c.imag = imag + c2.imag;
    return c;
}
void Complex :: display()
{
    cout << "(" << real << "," << imag << "i)" << endl;
}
int main()
{
    Complex c1(3,4),c2(5,-10),c3;
    c3 = c1 + c2; //运算符 + 用于复数运算
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c1 + c2 = "; c3.display();
    return 0;
}
