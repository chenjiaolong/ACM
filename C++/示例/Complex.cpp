#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }//���幹�캯��
    Complex(double r, double i){ real = r, imag = i; }//���캯��������
    Complex complex_add(Complex &c2);//����������ӵĺ���
    void display();
private :
    double real;
    double imag;
};
Complex Complex :: complex_add(Complex &c2)//���帴����ӵĺ���
{
    Complex c;
    c.real = real + c2.real;//����������ʵ�����
    c.imag = imag + c2.imag;//�����������鲿���
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
