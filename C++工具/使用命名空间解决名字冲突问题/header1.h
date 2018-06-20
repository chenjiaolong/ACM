#ifndef HEADER1_H_INCLUDED
#define HEADER1_H_INCLUDED

#include<string>
#include<math.h>
using namespace std;
namespace ns1
{
    class Student
    {
    public :
        Student(int n, string na, int a)
        {
            num = n;
            name = na;
            age = a;
        }
        void get_data();
    private :
        int num;
        string name;
        int age;
    };
    void Student :: get_data()
    {
        cout << num << " " << name << " " << age << endl;
    }
    double fun(double a, double b)
    {
        return sqrt(a + b);
    }
}

#endif // HEADER1_H_INCLUDED
