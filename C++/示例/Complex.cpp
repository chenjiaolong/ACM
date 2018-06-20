#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }//定义构造函数
    Complex(double r, double i){ real = r, imag = i; }//构造函数的重载
    Complex complex_add(Complex &c2);//声明复数相加的函数
    void display();
private :
    double real;
    double imag;
};
Complex Complex :: complex_add(Complex &c2)//定义复数相加的函数
{
    Complex c;
    c.real = real + c2.real;//两个复数的实部相加
    c.imag = imag + c2.imag;//两个复数的虚部相加
    return c;
}
void Complex :: display()
{
    cout << "(" << real  << "," << imag << "i)" << endl;
}
int main()
{
    Complex c1(3, 4),c2(5, -10),c3;
    c3 = c1.complex_add(c2);
    cout << "c1 = ";c1.display();
    cout << "c2 = ";c2.display();
    cout << "c1 + c2 = ";c3.display();
    return 0;
}
