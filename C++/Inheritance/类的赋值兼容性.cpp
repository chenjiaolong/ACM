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
    Derived(string s1,string s2) : Base(s1), str_b(s2) { }  // 调用基类构造函数初始化
    void Print() const { cout << "In derived: " << str_a + " " + str_b << endl; }
protected:
    string str_b;
};

int main()
{
  Derived d1( "Hello", "World" );

  Base b1( d1 );   // 拷贝构造，派生类至基类，仅复制基类部分
  d1.Print();  // Hello World
  b1.Print();  // Hello

  Base & b2 = d1;  // 引用，不调用拷贝构造函数，仅访问基类部分
  d1.Print();
  b2.Print();

  Base * b3 = &d1;  // 指针，不调用拷贝构造函数，仅引领基类部分
  d1.Print();
  b3->Print();
  return 1;
}


