#include<string>
#include<iostream>
using namespace std;
class Teacher
{
public :
    Teacher(string name, int age, string title)
    {
        this -> name = name;
        this -> age = age;
        this -> title = title;
    }
    void display()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "title : " << title << endl;
    }
protected :
    string name;
    int age;
    string title;
};
class Student
{
public :
    Student(string name, char sex, float score)
    {
        this -> name = name;
        this -> sex = sex;
        this -> score = score;
    }
    void displayone()
    {
        cout << "name : " << name << endl;
        cout << "sex : " << sex << endl;
        cout << "score : " << score << endl;
    }
protected :
    string name;
    char sex;
    float score;
};
class Graduate : public Teacher, Student
{
public :
    Graduate(string name, int age, char sex, string title, float score, float wage) :
        Teacher(name, age, title), Student(name, sex, score),wage(wage){ }
    void show()
    {
        cout << "name : " << Teacher :: name << endl;
        cout << "age : " << age << endl;
        cout << "sex : " << sex << endl;
        cout << "score : " << score << endl;
        cout << "title : " << title << endl;
        cout << "wages : " << wage << endl;
    }
protected :
    float wage;
};
int main()
{
    Graduate graduate("Wang - Li", 24, 'f', "assistant", 89.5, 1234.5);
    graduate.show();
    return 0;
}
