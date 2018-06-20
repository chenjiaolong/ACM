#include<string>
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
using namespace std;
class Student
{
public :
    void set_value();
    void display();
private:
    int num;
    string name;
    char sex;
};

#endif // STUDENT_H_INCLUDED
