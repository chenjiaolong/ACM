#include<vector>
#include<iostream>
#include<typeinfo>

using namespace std;

class Employee
{
public :
    virtual void PaySalary();
    virtual void PayBonus();
};

class Manager : public Employee
{
public :
    virtual void PaySalary();
    virtual void PayBonus();
};

class Programmer : public Employee
{
public :
    virtual void PaySalary();
    virtual void PayBonus();
};
class Company
{
public :
    virtual void PayRoll(Employee *e);
    virtual void PayRoll(Employee & e);
private :
    vector<Employee *>_employees;
};

//void Company :: PayRoll(Employee * e) // 版本一
//{
//    // 调用那个成员函数？如何区分程序员和经理
//    e -> PaySalary();
//    e -> PayBonus();
//};
//
//void Company :: PayRoll(Employee * e) // 版本二
//{
//    Programmer *p = dynamic_cast<Programmer *>(e);
//    if(p) // p确实指向程序员对象
//    {
//        p -> PaySalary();
//        p -> PayBonus();
//    }
//    else p -> PaySalary(); // p不指向程序员，不发奖金
//};

void Company :: PayRoll(Employee &e) // 版本三
{
    try
    {
        Programmer &p = dynamic_cast<Programmer &>(e);
        p.PaySalary();
        p.PayBonus();
    }catch(bad_cast)
    {
        e.PaySalary();
    }
};


// 输出p实际类名的字符串
int main()
{
    return 0;
}
