#include<iostream>
using namespace std;
class Complex
{
public :
    Complex(){ real = 0; imag = 0; }
    Complex(double r, double i){ real = r; imag = i; }
    Complex operator + (Complex &c2);//����� " + " ����Ϊ��Ա����
    //�� " << " �� " >> " ���صĺ�����ʽ��
    //istream & operator >> (istream &, �Զ����� &);
    //ostream & operator >> (ostream &, �Զ����� &);
    friend ostream & operator << (ostream &, Complex &);//����� " << " ����Ϊ��Ԫ����
    friend istream & operator >> (istream &, Complex &);//������������� " >> " ����
private :
    double real;
    double imag;
};
Complex Complex :: operator + (Complex &c2)//��������� " + " ���غ���
{
    return Complex(real + c2.real, imag + c2. imag);
}
//�β� output �� ostream ����� ( cout ) ������
ostream & operator << (ostream &output, Complex &c)//��������� " << "���غ���
{
    output << "( " << c.real;
    if(c.imag >= 0) // �鲿Ϊ����ʱ�����鲿ǰ�� " + " ��
        output << " + ";
     output << c.imag << "i )";//�鲿Ϊ����ʱ�����鲿ǰ���� " + " ��
    return output;//Ϊ���������������������Ϣ
}
istream & operator >> (istream &input, Complex &c)//������������� " >> " ����
{
    cout << "input real part and imaginary part of complex number:";
    input >> c.real >> c.imag;
    return input;//�������� cin ����ֵ
}
int main()
{
    Complex c1(2, 4),c2(6, 10),c3;
    c3 = c1 + c2;
    cout << "c3 = " << c3 << endl; //�����������ʱʵ�ʣ�operator << (cout, c3);
    Complex c4, c5;
    cin >> c4 >> c5;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    return 0;
}
