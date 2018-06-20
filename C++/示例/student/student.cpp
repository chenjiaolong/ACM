#include<iostream>
#include "student.h"
void Student :: set_value()
{
    cout << "Please input number, name, sex in order : " <<endl;
    cin >> num >> name >> sex;
}
void Student :: display()
{
    cout << "num : " << num << endl;
    cout << "name : " << name << endl;
    cout << "sex : " << sex << endl;
}
