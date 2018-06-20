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

//void Company :: PayRoll(Employee * e) // �汾һ
//{
//    // �����Ǹ���Ա������������ֳ���Ա�;���
//    e -> PaySalary();
//    e -> PayBonus();
//};
//
//void Company :: PayRoll(Employee * e) // �汾��
//{
//    Programmer *p = dynamic_cast<Programmer *>(e);
//    if(p) // pȷʵָ�����Ա����
//    {
//        p -> PaySalary();
//        p -> PayBonus();
//    }
//    else p -> PaySalary(); // p��ָ�����Ա����������
//};

void Company :: PayRoll(Employee &e) // �汾��
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


// ���pʵ���������ַ���
int main()
{
    return 0;
}
