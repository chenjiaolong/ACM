#include<iostream>
#include<string>
using namespace std;
class Student
{
public :
    Student(int, string, float);
    virtual void display();
    virtual ~Student(){ cout << "executing Student destructor" << endl; }
protected :
    int num;
    string name;
    float score;
};
Student :: Student(int num,string name,float score)
{
    this -> num = num;
    this -> name = name;
    this -> score = score;
}
void Student :: display()
{
    cout << "num : " << num << endl << "name : " << name << endl << "score : " << score << endl << endl;
}
class Graduate : public Student
{
public :
    Graduate(int, string, float, float);
    void display();
    ~Graduate(){ cout << "executing Graduate destructor" << endl; }
private :
    float pay;
};
Graduate :: Graduate(int num, string name, float score, float pay) : Student(num, name, score) , pay (pay){  }
void Graduate :: display()
{
    cout << "num : " << num << endl << "name : " << name << endl << "score : " << score << endl << "pay : " << pay << endl;
}
int main()
{
    Student stu(1001, "Li", 87.5);
    Graduate graduate(1002, "Wang", 98.5, 563.5);
    Student *pt = &stu;
    pt -> display();
    pt = &graduate;
    pt -> display();
    cout << endl;
    return 0;
}

//ÐéÎö¹¹º¯Êý
//#include<iostream>
//using namespace std;
//class Point
//{
//public :
//    Point(){  }
//    virtual ~Point() { cout << "executing Point destructor" << endl; }
//};
//class Circle : public Point
//{
//public :
//    Circle(){  }
//    ~Circle(){ cout << "executing Circle destructor" << endl; }
//};
//int main()
//{
//    Point *p = new Circle;
//    delete p;
//    return 0;
//}
