#include <iostream>
#include <string>
using namespace std;
class Base
{
public:
  Base(string s) : str_a(s) { }
  Base(const Base & that) { str_a = that.str_a; }
  void Print() const { cout << "In base: " << str_a << endl; }
protected:
    string str_a;
};
class Derived : public Base
{
public:
    Derived(string s1,string s2) : Base(s1), str_b(s2) { }  // ���û��๹�캯����ʼ��
    void Print() const { cout << "In derived: " << str_a + " " + str_b << endl; }
protected:
    string str_b;
};

int main()
{
  Derived d1( "Hello", "World" );

  Base b1( d1 );   // �������죬�����������࣬�����ƻ��ಿ��
  d1.Print();  // Hello World
  b1.Print();  // Hello

  Base & b2 = d1;  // ���ã������ÿ������캯���������ʻ��ಿ��
  d1.Print();
  b2.Print();

  Base * b3 = &d1;  // ָ�룬�����ÿ������캯������������ಿ��
  d1.Print();
  b3->Print();
  return 1;
}


