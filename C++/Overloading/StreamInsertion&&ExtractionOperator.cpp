#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }
    Complex(double r, double i){ real = r; imag = i; }
    Complex operator + (Complex &c2);//运算符 " + " 重载为成员函数
    //对 " << " 和 " >> " 重载的函数形式：
    //istream & operator >> (istream &, 自定义类 &);
    //ostream & operator >> (ostream &, 自定义类 &);
    friend ostream & operator << (ostream &, Complex &);//运算符 " << " 重载为友元函数
    friend istream & operator >> (istream &, Complex &);//声明重载运算符 " >> " 函数
private :
    double real;
    double imag;
};
Complex Complex :: operator + (Complex &c2)//定义运算符 " + " 重载函数
{
    return Complex(real + c2.real, imag + c2. imag);
}
//形参 output 是 ostream 类对象 ( cout ) 的引用
ostream & operator << (ostream &output, Complex &c)//定义运算符 " << "重载函数
{
    output << "( " << c.real;
    if(c.imag >= 0) // 虚部为正数时，在虚部前加 " + " 号
        output << " + ";
     output << c.imag << "i )";//虚部为负数时，在虚部前不加 " + " 号
    return output;//为了能连续向输出流插入信息
}
istream & operator >> (istream &input, Complex &c)//定义重载运算符 " >> " 函数
{
    cout << "input real part and imaginary part of complex number:";
    input >> c.real >> c.imag;
    return input;//函数返回 cin 的新值
}
int main()
{
    Complex c1(2, 4),c2(6, 10),c3;
    c3 = c1 + c2;
    cout << "c3 = " << c3 << endl; //编译器里编译时实质：operator << (cout, c3);
    Complex c4, c5;
    cin >> c4 >> c5;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    return 0;
}
