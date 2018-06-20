#include<string>
#include<iostream>
using namespace std;
class Student
{
public :
    Student(int n, string na)
    {
        cout << "constructor  - " << n << endl;
        num = n;
        name = na;
    }
    ~Student(){ cout << "destructor - " << num << endl; }
    void get_data();
private :
    int num;
    string name;
};
void Student :: get_data()
{
    if(num == 0) throw num;
    else cout << num << " " << name << endl;
    cout << "in get_data()" << endl;
}
void fun()
{
    Student stu1(1101, "Tan");
    stu1.get_data();
    Student stu2(0, "Li");
    stu2.get_data();
}
int main(int argc, char * argv[])
{
    cout << "main begin" << endl;
    cout << "call fun()" << endl;
    try
    {
        fun();
    }catch(int n)
    {
        cout << "num = " << n << ", error!" << endl;
    }
    cout << "main end" << endl;
    return 0;
}
