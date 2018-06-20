#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }
    Complex(double r){ real = r; imag = 0; }//ת�����캯���� ��һ���������͵�����ת����һ��ָ������Ķ���
    Complex(double r, double i){ real = r; imag = i; }
//    operator double(){ return real; }//����ת������: ��һ����Ķ���ת������һ�����͵�����
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
    c3 = c1 + 2.5;//ʹ����Ԫ�����ı���ԭ��operator + (c1, Complex(2.5));
    c3.display();
    c4 = 2.5 + c2;//ʹ����Ԫ�����ı���ԭ��(2.5).operator + (c1);
    c4.display();
//     double d = c1 + c2;//����ת������
//     cout << d <<endl;
    Complex cc = 1.4 + 1.5;
    cc.display();
    return 0;
}
