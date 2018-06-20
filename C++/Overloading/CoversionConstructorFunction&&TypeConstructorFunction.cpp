#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }
    Complex(double r){ real = r; imag = 0; }//转化构造函数： 讲一个其他类型的数据转换成一个指定的类的对象
    Complex(double r, double i){ real = r; imag = i; }
//    operator double(){ return real; }//类型转换函数: 将一个类的对象转换成另一个类型的数据
    friend Complex operator + (Complex c1,Complex c2);
    void display();
private :
    double real;
    double imag;
};
Complex operator + (Complex c1, Complex c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
void Complex :: display()
{
    cout << "( " << real << "," << imag << "i )" << endl;
}
int main()
{
    Complex c1(3, 4),c2(5, -10),c3,c4;
    c3 = c1 + 2.5;//使用友元函数的编译原理：operator + (c1, Complex(2.5));
    c3.display();
    c4 = 2.5 + c2;//使用友元函数的编译原理：(2.5).operator + (c1);
    c4.display();
//     double d = c1 + c2;//类型转换函数
//     cout << d <<endl;
    Complex cc = 1.4 + 1.5;
    cc.display();
    return 0;
}
