#include<string>
#include<iostream>
using namespace std;
class Student
{
public :
    Student(int, string, float);
    void display();
private :
    int num;
    string name;
    float score;
};
Student :: Student(int num, string name, float score)
{
    this -> num = num;
    this -> name = name;
    this -> score = score;
}
void Student :: display()
{
    cout << "num : " << num << endl;
    cout << "name : " << name << endl;
    cout << "score : " << score << endl;
}
class Graduate : public Student
{
public :
    Graduate(int, string, float, float);
    void display();
private :
    float pay;
};
Graduate :: Graduate(int num, string name, float score, float pay) : Student(num, name, score), pay(pay){ }
void Graduate :: display()
{
    Student :: display();
    cout << "pay : " << pay << endl;
}
int main()
{
    Student stu(1001, "Li", 87.5);
    Graduate graduate(2001, "Wang", 98.5, 563.5);
    //通过指向基类对象的指针，只能访问派生类中的基类成员，而不能访问访问派生类增加的成员
    Student *pt = &stu;
    pt -> display();
    cout << endl;
    pt = &graduate;
    pt -> display();
    cout << endl;
    Graduate *ptr = &graduate;
    ptr -> display();
    cout << endl;
    return 0;
}
