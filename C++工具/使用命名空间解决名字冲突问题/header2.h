#ifndef HEADER2_H_INCLUDED
#define HEADER2_H_INCLUDED

#include<string>
#include<math.h>
using namespace std;
namespace ns2
{
    class Student
    {
    public :
        Student(int n, string na, char s)
        {
            num = n;
            name = na;
            sex = s;
        }
        void get_data();
    private :
        int num;
        string name;
        char sex;
    };
    void Student :: get_data()
    {
        cout << num << " " << name << " " << sex << endl;
    }
    double fun(double a, double b)
    {
        return sqrt(a - b);
    }
}


#endif // HEADER2_H_INCLUDED
