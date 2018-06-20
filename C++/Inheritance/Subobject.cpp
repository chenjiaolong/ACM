#include<string>
#include<iostream>
using namespace std;
class Student
{
public :
    Student(int _num, string _name)
    {
        num = _num;//this -> num = _num;
        name = _name;
    }
    ~Student(){ cout << "Base class destructor called." << endl; }
    void display()
    {
        cout << "num : " << num << endl << "name : " << name << endl;
    }
protected :
    int num;
    string name;
};
class Studentone : public Student
{
public :
    Studentone(int _num, string _name, int n_m, string name_m, int _age,string _addr) : Student(_num,_name),monitor(n_m,name_m)
    {
        age = _age;
        addr = _addr;
    }
    Studentone(int _num, string _name, int n_m, string name_m) : Student(_num, _name),monitor(n_m,name_m){ }
    ~Studentone(){ cout << "Derived class destructor called." << endl; }
    void show()
    {
        cout << "This student is : " << endl;
        display();
        cout << "age : " << age << endl;
        cout << "address : " << addr << endl << endl;
    }
    void show_monitor()
    {
        cout << endl << "Class monitor is : " << endl;
        monitor.display();
    }
private :
    Student monitor;//定义子对象
    int age;
    string addr;
};
int main()
{
    Studentone stu(10010, "Wang - Li", 10001, "Li - Sun", 19, "115 Beijing Road, Shanghai");
    stu.show();
    stu.show_monitor();
    Studentone _stu(10010, "Wang - Li", 1001,"Li - Sun");
    cout << endl << "This student is : " << endl;
    _stu.display();
    _stu.show_monitor();
    return 0;
}
